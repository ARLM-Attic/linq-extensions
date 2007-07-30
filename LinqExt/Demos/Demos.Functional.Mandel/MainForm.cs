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

		double cx = -0.55, wid = 3.1;
		double cy = 0, hgt = 2.6;

		protected override void OnResize(EventArgs e)
		{
			var res = this.BackgroundImage;
			this.BackgroundImage = DrawMandel();
			if (res != null) res.Dispose();
			base.OnResize(e);
		}

		protected override void OnMouseDown(MouseEventArgs e)
		{
			cx = wid * (e.X - Width / 2) / Width + cx;
			cy = hgt * (e.Y - Height / 2) / Height + cy;
			if (e.Button == MouseButtons.Left)
			{
				wid = wid / 1.5;
				hgt = hgt / 1.5;
			}
			else if (e.Button == MouseButtons.Right)
			{
				wid = wid * 1.5;
				hgt = hgt * 1.5;
			}
			this.OnResize(EventArgs.Empty);
			base.OnMouseDown(e);
		}

		private Bitmap InitBitmap_Safe(int width, int height, Func<int, int, Color> f)
		{
			Bitmap b = new Bitmap(width, height);
			for (int x = 0; x < this.Width; x++)
				for (int y = 0; y < this.Height; y++)
					b.SetPixel(x, y, f(x,y));
			return b;				
		}

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

		private Bitmap DrawMandel()
		{
			var colors = 
				Seq.Concat(
					Seq.Range(0, 127).Select(n => Color.FromArgb(0, n * 2, 0)),
					Seq.Range(0, 127).Select(n => Color.FromArgb(0, 255 - n * 2, n))).ToArray();


			double dx = wid / this.Width;
			double dy = hgt / this.Height;
			double xmin = cx - wid / 2, ymin = cy - hgt / 2;
			return InitBitmap(this.Width, this.Height, (x, y) => {
					int count = GenerateMandel(xmin + x * dx, ymin + y * dy).CountMax(100);
					int val = (int)((count / 100.0) * 255.0);
					return colors[val];
				});
		}

		private static IEnumerable<Tuple<double, double>> GenerateMandel(double x, double y)
		{
			return Seq.Generate(Tuple.New(0.0, 0.0), (t) => {
					double x2 = t.First * t.First, y2 = t.Second * t.Second;
					if (Math.Sqrt(x2 + y2) >= 2)
						return null; 
					else 
						return Tuple.New(x2 - y2 + x, 2 * t.First * t.Second + y);
				});
		}
	}

	public static class Seq
	{
		public static int CountMax<T>(this IEnumerable<T> en, int max)
		{
			return en.TakeWhile((_) => max-- > 0).Count();
		}

		public static IEnumerable<T> Generate<T>(T initial, Func<T, T?> next) where T : struct
		{
			T? val = initial;
			while (val.HasValue)
			{
				yield return val.Value;
				val = next(val.Value);
			}
		}

		public static IEnumerable<int> Integers()
		{
			int i = 0;
			while (true) yield return i++;
		}

		public static IEnumerable<int> Range(int from, int to)
		{
			for (int i = from; i <= to; i++) yield return i;
		}

		public static IEnumerable<T> Concat<T>(params IEnumerable<T>[] args)
		{
			foreach (var en in args)
				foreach (var el in en) yield return el;
		}
	}


}