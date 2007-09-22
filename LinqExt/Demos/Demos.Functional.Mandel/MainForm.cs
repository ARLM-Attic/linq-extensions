using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;

namespace Demos.Functional.Mandel
{
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
		}

		// Initial position in the set
		float cx = -0.55f, wid = 3.1f;
		float cy = 0f, hgt = 2.6f;

		/// <summary>
		/// Refresh the image
		/// </summary>
		protected override void OnResize(EventArgs e)
		{
			var res = this.BackgroundImage;
			this.BackgroundImage = DrawMandel();
			if (res != null) res.Dispose();
			base.OnResize(e);
		}

		/// <summary>
		/// Change zoom and position in the set
		/// (left click for zoom-in, right for zoom-out)
		/// </summary>
		protected override void OnMouseDown(MouseEventArgs e)
		{
			cx = wid * (e.X - Width / 2) / Width + cx;
			cy = hgt * (e.Y - Height / 2) / Height + cy;
			if (e.Button == MouseButtons.Left)
			{
				wid = wid / 1.5f;
				hgt = hgt / 1.5f;
			}
			else if (e.Button == MouseButtons.Right)
			{
				wid = wid * 1.5f;
				hgt = hgt * 1.5f;
			}
			this.OnResize(EventArgs.Empty);
			base.OnMouseDown(e);
		}

		/// <summary>
		/// Initialize bitmap of specified size using given function.
		/// (Implemented using C# unsafe code)
		/// </summary>
		unsafe static private Bitmap InitBitmap(int width, int height, Func<int, int, Color> f)
		{
			Bitmap b = new Bitmap(width, height);
			BitmapData data = b.LockBits(new Rectangle(0, 0, width, height), ImageLockMode.ReadWrite, PixelFormat.Format32bppRgb);

			for (int y = 0; y < height; y++)
			{
				int* pos = (int*)data.Scan0 + y * (data.Stride/sizeof(int));
				for (int x = 0; x < width; x++)
				{
					*pos = f(x, y).ToArgb();
					pos++;
				}
			}

			b.UnlockBits(data);
			return b;
		}

		/// <summary>
		/// Draw the Mandelbrot set
		/// </summary>
		private Bitmap DrawMandel()
		{
			// Generate palette by concatenating transition from black 
			// to blue and from blue to green
			var colors = 
				Seq.Concat(
					Seq.Range(0, 127).Select(n => Color.FromArgb(0, n * 2, 0)),
					Seq.Range(0, 127).Select(n => Color.FromArgb(0, 255 - n * 2, n))).ToArray();

			// Calculate width and center of the image
			float dx = wid / this.Width;
			float dy = hgt / this.Height;
			float xmin = cx - wid / 2, ymin = cy - hgt / 2;
			
			return InitBitmap(this.Width, this.Height, (x, y) => {
					float xs = xmin + x * dx, ys = ymin + y * dy;

					// Count number of iterations with maximum number 100
					int count = GenerateMandel(xs, ys).CountMax(100);

					// Get color depending on the number of iterations
					int val = (int)((count / 100.0) * 255.0);
					return colors[val];
				});
		}

		/// <summary>
		/// Generate the sequence for a pixel in the image..
		/// </summary>
		/// <returns></returns>
		private static IEnumerable<PointF> GenerateMandel(float x, float y)
		{
			var init = new PointF(0.0f, 0.0f);
			return Seq.Generate(init, (t) => {
					// Calculate squares of X and Y
					float x2 = t.X * t.X, y2 = t.Y * t.Y;

					// If the sum is out of range then return 'null'
					if (Math.Sqrt(x2 + y2) >= 2)
						return null; 
					// Otherwise calculate the next point in the sequence
					else 
						return new PointF(x2 - y2 + x, 2 * t.X * t.Y + y);
				});
		}
	}


	/// <summary>
	/// Class with utility functions for working with sequences
	/// </summary>
	public static class Seq
	{
		/// <summary>
		/// Count number of iterations, but stop after specified maximal number.
		/// </summary>
		public static int CountMax<T>(this IEnumerable<T> en, int max)
		{
			return en.TakeWhile(_ => max-- > 0).Count();
		}

		/// <summary>
		/// Generates a sequence inductively. The first elemente in the sequence is
		/// given as a first argument and the next element is generated using the function
		/// given as a second argument. When the function returns 'null' the sequence ends.
		/// </summary>
		public static IEnumerable<T> Generate<T>(T initial, Func<T, T?> next) where T : struct
		{
			T? val = initial;
			while (val.HasValue)
			{
				yield return val.Value;
				val = next(val.Value);
			}
		}

		/// <summary>
		/// Generate sequence of integers in the specified range.
		/// </summary>
		public static IEnumerable<int> Range(int from, int to)
		{
			for (int i = from; i <= to; i++) yield return i;
		}

		/// <summary>
		/// Concatenate any number of sequences given as arguments
		/// </summary>
		public static IEnumerable<T> Concat<T>(params IEnumerable<T>[] args)
		{
			foreach (var en in args)
				foreach (var el in en) yield return el;
		}
	}
}