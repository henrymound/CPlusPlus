#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

int main()
{
	Deck deck;

	cout << "\nThe size of the cards is: ";
	cout << deck.Size() << "\n";

	cout << "\nThe cards in the deck are: " << endl;
	deck.Print();

	cout << "\nCutting the cards at location 13\n";
	deck.Cut(13);

	cout << "\nThe cards in the deck are: " << endl;
	deck.Print();

	deck.Shuffle();

	cout << "\nAfter shuffling, the cards in the deck are: " << endl;
	deck.Print();

	Card card = deck.TakeTopCard();

	cout << "\n\nTop card is ";
	card.Print();

	Card card2 = deck.TakeTopCard();

	cout << "\nTop card is ";
	card2.Print();

	for (int i = 0; !deck.TakeTopCard().Null(); i++) ;

	if (deck.IsEmpty()) {
		cout << "No more cards!" << endl << endl;
	}

	system("pause");
	return 0;
}
