//*********************************************
//This class obtains the characteristics that *
//define a Card. These include suit, letter,  *
//and particular values.					  *
//Name: Amilcar R Torres Quijano			  *
//Last Revision: 11/19/2017					  *
//Class: CECS 2202							  *
//ID: 113164								  *
//*********************************************

#include <iostream>

using namespace std;

class Card
{
private:

	char suit; //Represents the suit of a Card.
	char letter; //Represents the number or letter of a card. A, 2, etc.
	int value = 0; //Represents the value given for the card in blackjack.
	bool face_up = true; //Represents if a card is face up or down.

public:

	Card();
	Card (char s, char l, int v);
	~Card();

	void printCard();

	char getSuit();
	char setSuit(char s);
	char getLetter();
	char setLetter(char l);
	int getValue();
	int setValue(int v);
	bool getIsFaceUp();
	bool setIsFaceUp(bool f);	
	
};

//*************************************
//Define constructors and destructor. *
//*************************************

Card::Card(void)
{
	//cout << "Card is being created." << endl;
}

Card::Card(char s, char l, int v)
{
	suit = s;
	letter = l;
	value = v;
}

Card::~Card()
{
	//cout << "Card is being destroyed." << endl;
}

//*******************************************
//Prints Cards for the user as long as the  *
//card is face up.							*
//*******************************************
void Card::printCard()
{
	const int SPACE = 4;

	if (face_up)
	{
		cout << suit;
		cout << letter;
		// cout << value;
		cout << setw(SPACE);
	}
	else
		cout << " FD";
}

//*************************
//	Getters and setters.  *
//*************************

char Card::getSuit()
{
	return suit;
}

char Card::setSuit(char s)
{
	return suit = s;
}

char Card::getLetter()
{
	return letter;
}

char Card::setLetter(char l)
{
	return letter = l;
}

int Card::getValue()
{
	return value;
}

int Card::setValue(int v)
{
	return value = v;
}

bool Card::getIsFaceUp()
{
	return face_up;
}

bool Card::setIsFaceUp(bool f)
{
	return face_up = f;
}