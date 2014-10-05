using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab3
{
    class Program
    {
        static void Main(string[] args)
        {

            float originalFahrenheit;
            float calculatedCelsius;
            float calculatedFahrenheit;

            Console.Write("Enter temperature (Fahrenheit): ");
            originalFahrenheit = float.Parse(Console.ReadLine());

            calculatedCelsius = originalFahrenheit - 32;
            calculatedCelsius = calculatedCelsius / 9;
            calculatedCelsius = calculatedCelsius * 5;

            Console.WriteLine(originalFahrenheit + " fahrenheit is " + calculatedCelsius + " celsius.");

            calculatedFahrenheit = calculatedCelsius * 9;
            calculatedFahrenheit = calculatedFahrenheit / 5;
            calculatedFahrenheit = calculatedFahrenheit + 32;
            Console.WriteLine(calculatedCelsius + " celsius is " + calculatedFahrenheit + " farenheit");


        }
    }
}
