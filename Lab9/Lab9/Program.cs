using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab9
{
    class Program
    {
        static void Main(string[] args)
        {
            int inputChoice = 0;

            //Keeps the program running until the user chooses to quit
            while (inputChoice != 4)
            {

                Console.WriteLine(
                    "\n\n1 – New Game" +
                    "\n2 – Load Game" +
                    "\n3 – Options" +
                    "\n4 – Quit" +
                    "\n**************\n"
                    );
                Console.WriteLine("What would you like to do? (Enter corresponding menus number)");
                inputChoice = int.Parse(Console.ReadLine());

                //Responses based on conditionals
                if (inputChoice == 1)
                    Console.WriteLine("Starting a new game...");
                else if (inputChoice == 2)
                    Console.WriteLine("Loading game...");
                else if (inputChoice == 3)
                    Console.WriteLine("Displaying option menu...");
                else if (inputChoice == 4)
                    Console.WriteLine("Quitting...");
                else if (inputChoice > 4 || inputChoice < 1)
                    Console.WriteLine("Your response must be: 1, 2, 3, or 4. See menu.");

                //Responses based on switch statement
                switch (inputChoice)
                {
                    case 1:
                        Console.WriteLine("Starting a new game...");
                        break;
                    case 2:
                        Console.WriteLine("Loading game...");
                        break;
                    case 3:
                        Console.WriteLine("Displaying option menu...");
                        break;
                    case 4:
                        Console.WriteLine("Quitting...");
                        break;
                    default:
                        Console.WriteLine("Your response must be: 1, 2, 3, or 4. See menu.");
                        break;
                }

            }

        }
    }
}
