#ifndef DECK_H
#define DECK_H
#pragma once

#include <vector>
#include "card.h"

class Deck
{
public:
	Deck(void);
	~Deck(void);

	void Cut(int location);
	void Shuffle(void);
	Card TakeTopCard(void);
	bool IsEmpty(void);

	int Size(void);
	void Print(void);

private:
	vector<Card> cards;
};

#endif

