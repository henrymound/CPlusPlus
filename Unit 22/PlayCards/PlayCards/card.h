#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
public:
	Card(int rank = -1, int suit = -1);
	~Card(void);
	bool FaceUp(void);
	void FlipOver(void);
	bool Null(void);
	void Print();

private:
	int m_Rank;
	int m_Suit;
	bool m_FaceUp;
};

#endif

