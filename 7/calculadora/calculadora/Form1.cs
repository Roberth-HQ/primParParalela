using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace calculadora
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void AddNumberToTextBox(string number)
        {
            textBox1.Text += number; 
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("1");
        }


        private void button2_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("2");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("3");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("4");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("5");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("6");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("7");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("8");
        }

        private void button9_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("9");
        }

        private void button10_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("0");
        }

        private void button11_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("+");
        }

        private void button12_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("-");
        }

        private void button13_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("*");
        }

        private void button14_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("/");
        }

        private void button17_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox(" ");
        }

        private void button18_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length > 0)
            {
                textBox1.Text = textBox1.Text.Substring(0, textBox1.Text.Length - 1);
            }
        }
        //boton infija
        private void button15_Click(object sender, EventArgs e)
        {
            Class1 c1 = new Class1();
            string expression = textBox1.Text;
            string result = c1.Calcular(expression);
            textBox2.Text = result;
        }
        //boton prefija
        private void button16_Click(object sender, EventArgs e)
        {
            try
            {
                Class2 calc = new Class2();
                string expression = textBox1.Text;
                string result = calc.CalcularExpresionPrefija(expression);
                textBox2.Text = result;
            }
            catch (Exception)
            {
                textBox2.Text = "Error";
            }
        }

    }
}
