using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ConsoleCards;

namespace Lab14a
{
    class Program
    {
        static void Main(string[] args)
        {
            //Problem 2
            Deck deck = new Deck();
            List<Card> hand = new List<Card>();
            deck.Shuffle();

            //Problem 3
            for (int counter = 0; counter < 5; counter++) {
                hand.Add(deck.TakeTopCard());
            }
            for (int counter = 0; counter < hand.Count; counter++) {
                hand[counter].FlipOver();//flips over all cards in the hand
            }
            foreach(Card card in hand){
                card.Print();
            }
        }
    }
}
