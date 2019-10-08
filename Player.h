//*********************************************
//This class defines the characteristics of a *
//Player. These include the name and total    *
//score earned by the player.			      *
//Name: Amilcar R Torres Quijano			  *
//Last Revision: 11/19/2017					  *
//Class: CECS 2202							  *
//ID: 113164								  *
//*********************************************

#include <iostream>

using namespace std;

class Player
{

private:

	string name; //Name of the player.
	int score; //Stores the players blackjack score.
	int count; //Used to cycle through a players hand.

	vector<Card> hand; //Vector which contains a given players hand.

public:

	Player();
	Player(string n, int s);
	~Player();

	void addToHand(Card ca);
	void updateScore();
	void showHand();
	void clearHand();
	void turnFaceDown();
	void turnFaceUp();
	vector<Card> getHand();
	string getName();
	string setName(string n);
	int getScore();
	int setScore(int s);
	int getCount();
	int setCount (int c);
 	
};

//*************************************
//Define constructors and destructor. *
//*************************************

Player::Player()
{
	//Generating player.
}

Player::Player(string n, int s)
{
	name = n;
	score = s;
}

Player::~Player()
{
	//Destroying player;
}

//*******************************
//Obtains a card from the deck  *
//and adds it to the players    *
//hand.                         *
//*******************************
void Player::addToHand(Card ca)
{
	hand.push_back(ca);
}

//*******************************
//Clears a players hand when    *
//starting a new game.          *
//*******************************
void Player::clearHand()
{
	hand.clear();
	score = 0;
	count = 0;
}

//*******************************
//Updates a players score,      *
//usually after a new card is   *
//added to the players hand.    *
//*******************************
void Player::updateScore()
{
	score += hand.at(count).getValue();
	count++;
	//cout << name << " score: " << score << endl;
}

//*******************************
//Prints the cards in a players *
//hand.                         *
//*******************************
void Player::showHand()
{
	cout << getName() << " hand: ";
	for (int i = 0; i < hand.size(); i++)
		hand.at(i).printCard();
	cout << endl;
}

//*******************************
//Turns the second card in a    *
//players hand face down.       *
//*******************************
void Player::turnFaceDown()
{
	const int CARD_POS = 1;
	hand.at(CARD_POS).setIsFaceUp(false);
}

//*******************************
//Turns the second card in a    *
//players hand face up.         *
//*******************************
void Player::turnFaceUp()
{
	const int CARD_POS = 1;
	hand.at(CARD_POS).setIsFaceUp(true);
}

//*************************
//	Getters and setters.  *
//*************************

vector<Card> Player::getHand()
{
	return hand;
}

string Player::getName()
{
	return name;
}

int Player::getScore()
{
	return score;
}

string Player::setName(string n)
{
	return name = n;
}

int Player::setScore(int s)
{
	return score = s;
}

int Player::getCount()
{
	return count;
}

int Player::setCount(int c)
{
	return count = c;
}