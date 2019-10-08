//*********************************************
//This class defines the characteristics of a *
//Deck. These include generating the deck	  * 
//storing 52 cards, holding cards,  shuffling *
//the deck, and dealing cards for players.    *
//Name: Amilcar R Torres Quijano			  *
//Last Revision: 11/19/2017					  *
//Class: CECS 2202							  *
//ID: 113164								  *
//*********************************************

#include <iostream>

using namespace std;

class Deck
{

private:

	const static int DECK_SIZE = 52; //Sets the max size of the deck
	const static int SUIT_SIZE = 4; //Amount of suits in a deck.
	const static int LETTER_SIZE = 13; //Amount of letters in a deck.
	const static int VALUE_SIZE = 11; //The possible values of the cards in the deck.

	int count = 0; //Variable used to cycle through the deck.

	Card deck[DECK_SIZE] = {};

	char valid_suit[SUIT_SIZE] = {'S', 'H', 'C', 'D'};
	char valid_letter[LETTER_SIZE] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
	int valid_value[VALUE_SIZE] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10};

public:
	
	Deck();
	~Deck();

	void print();
	void generate();
	void shuffle();
	Card deal();	
};

Deck::Deck()
{
	//Generating Deck
}

Deck::~Deck()
{
	//Destroying Deck
}

//*********************************
//Shows the cards in the deck to  *
//the user.                       *
//*********************************
void Deck::print()
{
	const int SPACE = 4;

	for (int i = 0; i < DECK_SIZE; i++)
	{
		if (i%LETTER_SIZE == 0)
		{
			cout << endl;
			cout << setw(SPACE);
			deck[i].printCard();
		}
		else
		{
			cout << setw(SPACE);
			deck[i].printCard();
		}
	}
	cout << endl;
}

//**********************************
//Creates a deck in order to start *
//the game.                        *
//**********************************
void Deck::generate()
{
	for (int i = 0; i < DECK_SIZE; i++)
	{
		Card card;
		card.setSuit(valid_suit[i%SUIT_SIZE]);
		card.setLetter(valid_letter[i%LETTER_SIZE]);

		if (card.getLetter() == 'J' || card.getLetter() == 'Q' || card.getLetter() == 'K')
			card.setValue(VALUE_SIZE - 1);
		else
			card.setValue(valid_value[i%LETTER_SIZE]);
		deck[i] = card;
	}
}

//*********************************
//Shuffles the deck in order to   *
//simulate the randomness in card *
//draws.                          *
//*********************************
void Deck::shuffle()
{
	const int MIN_POS = 0; //deck min pos.
	const int MAX_POS = DECK_SIZE; //deck max pos.

	const int MIN_VALUE = 1; //Min value for shuffling of deck.
	const int MAX_VALUE = 10; //Max value for shuffling of deck.

	unsigned seed = time(0);
	srand(seed);

	//Generate a number which corresponds to how many times the deck
	//will be shuffled.
	int random_number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

	for (int i = 0; i < random_number; i++)
		random_shuffle(&deck[MIN_POS], &deck[MAX_POS]);
}

//***********************************
//Obtains the top card of the deck. *
//***********************************
Card Deck::deal()
{
	Card temp = deck[count];
	count++;
	return temp;
}