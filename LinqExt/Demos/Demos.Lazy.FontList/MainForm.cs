using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Demos.Lazy.FontList
{
	public partial class MainForm : Form
	{
		public MainForm()
		{
			InitializeComponent();
		}


		/// <summary>
		/// Type used to store name and preview (as a lazy value) of a font family
		/// </summary>
		private class FontInfo
		{
			public Lazy<Bitmap> Preview { get; set; }
			public string Name { get; set; }
		}
	

		/// <summary>
		/// Draw preview of a font family on a specified bitmap
		/// </summary>
		private void DrawFontPreview(FontFamily f, Bitmap bmp)
		{
			Rectangle rc = new Rectangle(0, 0, 300, 200);
			StringFormat sf = new StringFormat();
			sf.Alignment = StringAlignment.Center;
			sf.LineAlignment = StringAlignment.Center;
			string lipsum = "Lorem ipsum dolor sit amet, consectetuer " +
				"adipiscing elit. Etiam ut mi blandit turpis euismod malesuada. " +
				"Mauris congue pede vitae lectus. Ut faucibus dignissim diam. ";

			using (Font fnt = new Font(f, 15, FontStyle.Regular))
			using (Graphics gr = Graphics.FromImage(bmp))
			{
				gr.FillRectangle(Brushes.White, rc);
				gr.DrawString(lipsum, fnt, Brushes.Black, rc, sf);
			}
		}


		/// <summary>
		/// Populate the font list 
		/// </summary>
		private void FontForm_Load(object sender, EventArgs e)
		{
			var fontInfo = FontFamily.Families.Select(f => {
					// Create a lazy value for drawing the preview
					var preview = Lazy.New(() => {
							Bitmap bmp = new Bitmap(300, 200);
							DrawFontPreview(f, bmp);
							return bmp;
						});

					// Return a font info with the family name and the preview
					return new FontInfo { Name = f.Name, Preview = preview };
				});

			// Use data-binding to populate the drop down list
			fontCombo.DataSource = fontInfo.ToList();
			fontCombo.DisplayMember = "Name";
		}


		/// <summary>
		/// Display preview for a selected font (forces execution of the
		/// lazy value if it wasn't calculated already)
		/// </summary>
		private void fontCombo_SelectedIndexChanged(object sender, EventArgs e)
		{
			FontInfo fnt = (FontInfo)fontCombo.SelectedItem;
			fontPreview.Image = fnt.Preview.Value;
		}
	}
}
