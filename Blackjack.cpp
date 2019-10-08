//***********************************************
//This program contains the rules and setup to  *
//run a blackjack game between the user and a   *
//computer controlled opponent. It implements   *
//the class, deck, and player classes to        *
//simulate the game.                            *
//Name: Amilcar R Torres Quijano                *
//Last Revision: 11/19/2017                     *
//Class: CECS 2202                              *
//ID: 113164                                    *
//***********************************************

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "Deck.h"

using namespace std;

Deck deck;

Player player("player", 0); //corresponds to the user.
Player dealer("dealer", 0); //The opponent, dealer of the game.

char playAgain(char pl);
void startGame();
void gameLoop();

int main()
{
	startGame();
	gameLoop();
	cout << "Thank you for playing the game!\n";
}

//**********************************************
//Determines if the user would like to restart *
//the game.                                    *
//**********************************************
char playAgain(char pl)
{
	while (true)
	{
		cout << "\nWould you like to play again? (y/n)\n";
		cout << "Choice: ";
		cin >> pl;
		cout << endl;

		if (pl == 'y' || pl == 'n')
			break;
	}

	return pl;
}

//*************************************************
//Generates the starting parameters for the game. *
//These include player hands and a start msg.     *
//*************************************************
void startGame()
{
	cout << "Welcome to Blackjack! I am the dealer for this game.\n";
	cout << "I am designated as AI-N113\n";
	cout << "Let us begin!\n";

	cout << "Generating Deck...\n";
	deck.generate();
	deck.print();

	cout << endl << "Shuffling Deck...\n";
	deck.shuffle();
	deck.print();
	cout << endl;

	//Adds two cards to the player hand.
	player.addToHand(deck.deal());
	player.updateScore();
	player.addToHand(deck.deal());
	player.updateScore();

	//Adds two cards to the dealer hand.
	dealer.addToHand(deck.deal());
	dealer.updateScore();
	dealer.addToHand(deck.deal());
	dealer.updateScore();

}

//*************************************
//Contains the main logic and rules   *
//for the game.                       *
//*************************************
void gameLoop()
{
	const int MAX_SCORE = 21;
	const int DEAL_SCORE = 17;
	char choice;

	do
	{
		player.showHand();
		dealer.turnFaceDown();
		dealer.showHand();

		cout << "\nGame Options\n1. Hit\n2. Stand\n3. Exit Game\n";
		cout << "Choice: ";
		cin >> choice;
		cout << endl;

		switch(choice)
		{
			case '1':
			{
				cout << "Player hits!\n\n";
				player.addToHand(deck.deal()); //Add a card to players hand if 'hit'.
				player.updateScore();

				if (player.getScore() > MAX_SCORE) //If score greater than 21, player loses.
				{
					cout << "Player score greater than " << MAX_SCORE << "!\n";
					dealer.turnFaceUp();

					cout << endl << "Final Hands\n";
					player.showHand();
					dealer.showHand();

					cout << endl << dealer.getName() << " wins!\n";

					choice = playAgain(choice); //ask if player would like to restart.
				}
				break;
			}

			case '2':
			{
				cout << "Player stands!\n\n";
				dealer.turnFaceUp();
				player.showHand();
				dealer.showHand();

				//Add cards to dealers hand until score surpasses 17.
				while (true)
				{
					if (dealer.getScore() < DEAL_SCORE)
					{
						cout << "\nGetting additional card for dealer...\n";
						dealer.addToHand(deck.deal());
						dealer.updateScore();
						dealer.showHand();
					}
					else
						break;
				}

				cout << endl << "Final Hands\n";
				player.showHand();
				dealer.showHand();

				//Determine winner
				if (player.getScore() > dealer.getScore())
					cout << endl << player.getName() << " wins!\n";
				else if (dealer.getScore() > MAX_SCORE)
					cout << endl << player.getName() << " wins!\n";
				else
					cout << endl << dealer.getName() << " wins!\n";
				choice = playAgain(choice);

				break;
			}

			case '3':
			{
				cout << "Thank you for playing the game!\n";
				exit(0);
			}

			default:
			{
				cerr << "Incorrect option chosen. TRY AGAIN!\n";
				break;
			}
		}

		//Restart the game.
		if (choice == 'y')
		{
			//Clear both players hands.
			player.clearHand();
			dealer.clearHand();

			cout << endl << "Shuffling Deck...\n";
			deck.shuffle(); //reshuffle
			deck.print();
			cout << endl;

			//Set new hands for players.
			player.addToHand(deck.deal());
			player.updateScore();
			player.addToHand(deck.deal());
			player.updateScore();

			dealer.addToHand(deck.deal());
			dealer.updateScore();
			dealer.addToHand(deck.deal());
			dealer.updateScore();
		}

	}while(choice != 'n');
}