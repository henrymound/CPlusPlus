using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab14a
{
    class Program
    {
        static void Main(string[] args)
        {
            //Problem 1
            int lowerBound = 0;
            int upperBound = 0;
            Console.Write("Enter the lower bound number:");
            lowerBound = int.Parse(Console.ReadLine());
            Console.Write("\nEnter the upper bound number:");
            upperBound = int.Parse(Console.ReadLine());
            Console.WriteLine("\nPrinting ints from lower to upper bound (inclusive)...");
            for (int counter = lowerBound; counter <= upperBound; counter++) {
                Console.WriteLine(counter);
            }
            Console.WriteLine();

        }
    }
}
