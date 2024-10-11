using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace calculadora
{
    internal class Class2
    {
        public string ConvertPrefixToInfix(string prefix)
        {
            Stack<string> stack = new Stack<string>();
            string[] tokens = prefix.Split(' ');

            for (int i = tokens.Length - 1; i >= 0; i--)
            {
                string token = tokens[i];

                if (IsOperator(token))
                {
                    string operand1 = stack.Pop();
                    string operand2 = stack.Pop();
                    string infix = "(" + operand1 + " " + token + " " + operand2 + ")";
                    stack.Push(infix);
                }
                else
                {
                    stack.Push(token);
                }
            }
            return stack.Pop();
        }

        private bool IsOperator(string token)
        {
            return token == "+" || token == "-" || token == "*" || token == "/";
        }

        public string CalcularExpresionPrefija(string prefix)
        {
            string infixExpression = ConvertPrefixToInfix(prefix);
            DataTable dt = new DataTable();
            var result = dt.Compute(infixExpression, "");
            return result.ToString();
        }
    }
}