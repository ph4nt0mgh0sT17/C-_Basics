using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Matrix
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] matrix = new int[,] {
                { 1, 2, 5, 4 },
                { 5, 4, 9, 1 },
                { 9, 5, 1, 5 }
            };

            int[,] matrix1 = new int[,] {
                { 8, 9, 1 },
                { 8, 5, 1 },
                { 4, 7, 1 },
                { 1, 2, 3 }
            };

            int[,] result = MultiplyMatrix(matrix, matrix1);

            Console.WriteLine(DisplayMatrix(matrix));

            Console.ReadKey();
        }

        static int[,] MultiplyMatrix(int[,] firstMatrix, int[,] secondMatrix)
        {
            int[,] multipliedMatrix = new int[firstMatrix.GetUpperBound(0)+1, secondMatrix.GetUpperBound(1)+1];

            for (int rows = 0; rows <= multipliedMatrix.GetUpperBound(0); rows++)
            {
                for (int count = 0; count <= multipliedMatrix.GetUpperBound(0); count++)
                {
                    for (int columns = 0; columns <= multipliedMatrix.GetUpperBound(1); columns++)
                    {
                        multipliedMatrix[rows, count] += firstMatrix[rows, columns] * secondMatrix[columns, count];
                    }
                }
            }

            return multipliedMatrix;
        }

        public static string DisplayMatrix(int[,] matrix)
        {
            string matrixDisplay = "";

            for (int rows = 0; rows <= matrix.GetUpperBound(0); rows++)
            {
                for (int columns = 0; columns <= matrix.GetUpperBound(1); columns++)
                {
                    matrixDisplay += matrix[rows, columns] + "\t";
                }

                matrixDisplay += "\n";
            }

            return matrixDisplay;
        }
    }
}
