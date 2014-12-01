using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ConsoleCards;

namespace Lab13
{
    class Program
    {
        static void Main(string[] args)
        {
            //Problem 1
            Deck deck = new Deck();
            Card[] cardArray = new Card[5];
            deck.Shuffle();

            //Problem 2
            cardArray[0] = deck.TakeTopCard();
            cardArray[0].FlipOver();
            cardArray[0].Print();

            //Problem 3
            cardArray[1] = deck.TakeTopCard();
            cardArray[1].FlipOver();
            Console.Write("\nCard at array location 0: ");
            cardArray[0].Print();
            Console.Write("Card at array location 1: ");
            cardArray[1].Print();
        }
    }
}
