namespace Demos.Lazy.FontList
{
	partial class MainForm
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.fontCombo = new System.Windows.Forms.ComboBox();
			this.fontPreview = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(this.fontPreview)).BeginInit();
			this.SuspendLayout();
			// 
			// fontCombo
			// 
			this.fontCombo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
									| System.Windows.Forms.AnchorStyles.Right)));
			this.fontCombo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.fontCombo.FormattingEnabled = true;
			this.fontCombo.Location = new System.Drawing.Point(12, 12);
			this.fontCombo.Name = "fontCombo";
			this.fontCombo.Size = new System.Drawing.Size(260, 21);
			this.fontCombo.TabIndex = 0;
			this.fontCombo.SelectedIndexChanged += new System.EventHandler(this.fontCombo_SelectedIndexChanged);
			// 
			// fontPreview
			// 
			this.fontPreview.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
									| System.Windows.Forms.AnchorStyles.Left)
									| System.Windows.Forms.AnchorStyles.Right)));
			this.fontPreview.Location = new System.Drawing.Point(12, 39);
			this.fontPreview.Name = "fontPreview";
			this.fontPreview.Size = new System.Drawing.Size(260, 213);
			this.fontPreview.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
			this.fontPreview.TabIndex = 1;
			this.fontPreview.TabStop = false;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 264);
			this.Controls.Add(this.fontPreview);
			this.Controls.Add(this.fontCombo);
			this.Name = "MainForm";
			this.Text = "Font List";
			this.Load += new System.EventHandler(this.FontForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.fontPreview)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.ComboBox fontCombo;
		private System.Windows.Forms.PictureBox fontPreview;
	}
}

