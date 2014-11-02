using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab8
{
    class Program
    {
        static void Main(string[] args)
        {
            String enteredData;
            int pyramidSlotNumber;
            char blockLetter;
            Boolean litOrNot;

            Console.WriteLine("Enter string in the format <pyramid slot number>,<block letter>,<whether or not the block should be lit> (x,y,z):");
            enteredData = Console.ReadLine();
            //Get variables from entered line
            pyramidSlotNumber = int.Parse(enteredData.Substring(0, enteredData.IndexOf(",")));
            blockLetter = enteredData[enteredData.IndexOf(",")+1];
            litOrNot = Boolean.Parse(enteredData.Substring(5));
            //Prints variables
            Console.WriteLine("\nPyramid Slot Number: "+pyramidSlotNumber);
            Console.WriteLine("Block Letter: "+blockLetter);
            if (litOrNot)
                Console.WriteLine("The block should be lit\n");
            else
                Console.WriteLine("The block should not be lit\n");
        }
    }
}
