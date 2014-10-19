using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab4
{
    class Program
    {
        static void Main(string[] args)
        {

            //Problem 1 - Create the deck and print it
            Deck deck = new Deck();
            deck.Print();

            //Problem 2 - Shuffle the deck and print it
            deck.Shuffle();
            deck.Print();

            //Problem 3 - Take two cards from the deck and print them
            Card card1 = deck.TakeTopCard();
            Console.WriteLine("\nProblem 3:");
            Console.WriteLine("Top card - Suit: " + card1.Suit + ", Rank: " + card1.Rank);
            Card card2 = deck.TakeTopCard();
            Console.WriteLine("Following card - Suit: " + card2.Suit + ", Rank: " + card2.Rank);


        }
    }
}
