#include <iostream>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Status();
	void Eat(int food = 4);
	void Play(int fun = 4);
	int m_Hunger;
	int m_Boredom;

private:
	int GetMood() const;
	void PassTime(int time = 1);

};

Critter::Critter(int hunger, int boredom) :
m_Hunger(hunger),
m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	system("cls");
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	system("cls");
	cout << "I'm a critter and I feel ";

	int mood = GetMood();
	if (mood > 15)
	{
		cout << "mad.\n";
	}
	else if (mood > 10)
	{
		cout << "frustrated.\n";
	}
	else if (mood > 5)
	{
		cout << "okay.\n";
	}
	else
	{
		cout << "happy.\n";
	}

	PassTime();
}

void Critter::Eat(int food)
{
	system("cls");
	cout << "Brruppp.\n";

	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun)
{
	system("cls");
	cout << "Wheee!\n";

	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}

void Critter::Status()
{
	system("cls");
	cout << "_________________\n";
	cout << "Boredom: " << m_Boredom << "\n";
	cout << "Hunger:  " << m_Hunger << "\n";
	cout << "_________________\n";

}

int main()
{
	Critter crit;

	int choice = 1;  //start the critter off talking
	while (choice != 0)
	{
		//Hunger Hints
		if (crit.m_Hunger == 3 || crit.m_Hunger == 4)
			cout << "(stomach rumbling)\n";
		if (crit.m_Hunger == 5 || crit.m_Hunger == 6)
			cout << "I really could use a snack...\n";
		if (crit.m_Hunger == 7 || crit.m_Hunger == 8)
			cout << "When's my next meal?\n";
		if (crit.m_Hunger > 8)
			cout << "I'm starving!\n";

		//Boredom Hints
		if (crit.m_Boredom == 3 || crit.m_Boredom == 4)
			cout << "Where's my toy?\n";
		if (crit.m_Boredom == 5 || crit.m_Boredom == 6)
			cout << "I wish somebody would play with me...\n";
		if (crit.m_Boredom == 7 || crit.m_Boredom == 8)
			cout << "I haven't played in too long!\n";
		if (crit.m_Boredom > 8)
			cout << "Don't abandon me!!\n";

		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with your critter\n\n";
		cout << "";

		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4://Unlisted item for exact values
			crit.Status();
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	}

	return 0;
}
