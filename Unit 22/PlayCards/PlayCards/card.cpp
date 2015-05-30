#include <iostream>
#include <string>
#include <vector>
#include "rank.h"
#include "suit.h"
#include "card.h"

using namespace std;

Card::Card(int rank, int suit): 
m_Rank(rank), m_Suit(suit), m_FaceUp(false)
{
}

Card::~Card(void)
{
}

bool Card::FaceUp()
{
	return m_FaceUp;
}

void Card::FlipOver()
{
	m_FaceUp = !m_FaceUp;
}

bool Card::Null()
{
	return m_Rank == -1 && m_Suit == -1;
}

void Card::Print()
{
	cout << RANK_NAMES[m_Rank];
	cout << " of ";
	cout << SUIT_NAMES[m_Suit];
	cout << endl;
}

