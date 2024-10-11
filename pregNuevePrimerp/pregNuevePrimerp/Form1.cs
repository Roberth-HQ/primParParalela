using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace pregNuevePrimerp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom; 
            pictureBox2.SizeMode = PictureBoxSizeMode.Zoom;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "Archivos png|*.png|Archivos jpg|*.jpg";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Bitmap bmp = new Bitmap(openFileDialog1.FileName);
                pictureBox1.Image = bmp;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Bitmap bmp = new Bitmap(pictureBox1.Image);
            Bitmap bmp2 = new Bitmap(bmp.Width, bmp.Height);

            for (int i = 1; i < bmp.Width - 1; i++)
            {
                for (int j = 1; j < bmp.Height - 1; j++)
                {
                    Color current = bmp.GetPixel(i, j);
                    Color right = bmp.GetPixel(i + 1, j);
                    Color down = bmp.GetPixel(i, j + 1);

                    int diffR = Math.Abs(current.R - right.R) + Math.Abs(current.R - down.R);
                    int diffG = Math.Abs(current.G - right.G) + Math.Abs(current.G - down.G);
                    int diffB = Math.Abs(current.B - right.B) + Math.Abs(current.B - down.B);

                    int edgeValue = (diffR + diffG + diffB) / 3;
                    edgeValue = Math.Min(255, Math.Max(0, edgeValue));

                    bmp2.SetPixel(i, j, Color.FromArgb(edgeValue, edgeValue, edgeValue));
                }
            }

            pictureBox2.Image = bmp2; 
        }
    }
}