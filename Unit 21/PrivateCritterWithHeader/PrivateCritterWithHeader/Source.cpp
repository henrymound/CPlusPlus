#include <iostream>
#include "private_critter.hpp"

using namespace std;

Critter::Critter(int hunger) :
m_Hunger(hunger)
{
	cout << "A new critter has been born!" << endl;
}

int Critter::GetHunger() const
{
	return m_Hunger;
}

void Critter::SetHunger(int hunger)
{
	if (hunger < 0)
	{
		cout << "You can't set a critter's hunger to a negative number.\n\n";
	}
	else
	{
		m_Hunger = hunger;
	}
}

int main()
{
	Critter crit(5);
	//cout << crit.m_Hunger; -- illegal, m_Hunger is private!
	cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";

	cout << "Calling SetHunger() with -1.\n";
	crit.SetHunger(-1);

	cout << "Calling SetHunger() with 9.\n";
	crit.SetHunger(9);
	cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";

	system("pause");

	return 0;
}
