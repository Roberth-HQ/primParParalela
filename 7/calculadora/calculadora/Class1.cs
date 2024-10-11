using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace calculadora
{
    internal class Class1
    {
        public string Calcular(string expression)
        {
            try
            {
                DataTable dt = new DataTable();
                var result = dt.Compute(expression, "");  // Calcula el resultado de la expresión
                return result.ToString(); 
            }
            catch (Exception)
            {
                return "Error";  
            }
        }
    }
}
