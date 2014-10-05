using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab2
{
    class Program
    {
        static void Main(string[] args)
        {
            int age;
            age = 16;
            Console.WriteLine("I am "+age+" years old.");

            const int MAX_SCORE = 100;
            int score = 35;
            float percent = (float)score / MAX_SCORE;
            Console.WriteLine("The percentage is: " + percent);
        }
    }
}
