using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace calculadoraWebService
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void AddNumberToTextBox(string number)
        {
            textBox1.Text += number;
        }


        private void button1_Click_1(object sender, EventArgs e)
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

        private void button15_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("-");
        }

        private void button16_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("+");
        }

        private void button17_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("*");
        }

        private void button18_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox("/");
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length > 0)
            {
                textBox1.Text = textBox1.Text.Substring(0, textBox1.Text.Length - 1);
            }
        }

        private void button14_Click(object sender, EventArgs e)
        {
            AddNumberToTextBox(" ");
        }
        //boton infija
        private void button12_Click(object sender, EventArgs e)
        {
            try
            {
                ServiceReference2.WebService1SoapClient sc1 = new ServiceReference2.WebService1SoapClient();
                String expression = textBox1.Text;
                String result = sc1.Calcular(expression);
                textBox2.Text = result;
            }
            catch (Exception){
                textBox2.Text = "Error";
            }
        }
        //boton prefija
        private void button13_Click(object sender, EventArgs e)
        {
            // ServiceReference2.hSoapClient sc1 = new ServiceReference2.WebServiceSoapClient();
            try
            {
                ServiceReference2.WebService1SoapClient sc1= new ServiceReference2.WebService1SoapClient(); 
                string expression = textBox1.Text;
                string result = sc1.CalcularExpresionPrefija(expression);
                textBox2.Text = result;
            }
            catch (Exception)
            {
                textBox2.Text = "Error";
            }
        }
    }
}
