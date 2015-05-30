#include <iostream>
#include <algorithm>
#include "deck.h"
#include "suit.h"
#include "rank.h"

Deck::Deck(void)
{
	for (int suit = 0; suit < NUMBER_OF_SUITS; suit++)
	{
		for (int rank = 0; rank < NUMBER_OF_RANKS; rank++)
		{
			Card card(rank, suit);
			cards.push_back(card);
		}
	}

}


Deck::~Deck(void)
{
}

void Deck::Cut(int location)
{
	int cutIndex = cards.size() - location;
	vector<Card> newCards;
	for (int i = cutIndex; i < cards.size(); i++)
	{
		newCards.push_back(cards[i]);
	}
	for (int i = 0; i < cutIndex; i++)
	{
		newCards.push_back(cards[i]);
	}
	cards = newCards;
}

void Deck::Shuffle()
{
	random_shuffle(cards.begin(), cards.end());
}

Card Deck::TakeTopCard()
{
	if (!IsEmpty())
	{
		Card topCard = cards[cards.size()-1];
		cards.pop_back();
		return topCard;
	} else {
		Card card;
		return card;
	}
}

bool Deck::IsEmpty()
{
	return cards.empty();
}

int Deck::Size()
{
	return cards.size();
}

void Deck::Print()
{
	for (int i = 0; i < cards.size(); i++)
	{
		cards[i].Print();
	}
}

