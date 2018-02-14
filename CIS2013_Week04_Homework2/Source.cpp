#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// made 3 seperate functions for getting a random number 1-13, interpreting that number into a character if necessary, and giving that number a blackjack value (face cards are 10, ace is 1)

int getRandom()
{
	return rand() % 13 + 1;
}


char getName(int input)
{
	char cardRank = 'A';

	switch (input)
	{
		case 1:
			cardRank = 'A';
			break;
		case 11:
			cardRank = 'J';
			break;
		case 12:
			cardRank = 'Q';
			break;
		case 13:
			cardRank = 'K';
			break;
		default:
			cardRank = ' ';
	}
	return cardRank;
}


int getValue(int input)
{
	char cardValue = 0;

	switch (input)
	{
	case 11:
		cardValue = 10;
		break;
	case 12:
		cardValue = 10;
		break;
	case 13:
		cardValue = 10;
		break;
	default:
		cardValue = input;
	}
	return cardValue;
}


int main() {

	srand(time(NULL));

	char cardName1 = 'A';
	char cardName2 = 'A';
	char cardName3 = 'A';
	int cardValue1 = 0;
	int cardValue2 = 0;
	int cardValue3 = 0;
	int cardRandom1 = 0;
	int cardRandom2 = 0;
	int cardRandom3 = 0;
	int yourTotal = 0;
	int dealerTotal = 0;

	int yourHitRandom = 0;
	char yourHitName = 'A';
	int yourHitValue = 0;

	int dealerHitRandom = 0;
	char dealerHitName = 'A';
	int dealerHitValue = 0;

	char action = 'h';
	bool hit = true;

	char play_again = 'y';
	while (play_again == 'y')
	{
		// randomize the player's first card, and set it's rank, value, and print it out
		cardRandom1 = getRandom();
		cardName1 = getName(cardRandom1);
		cardValue1 = getValue(cardRandom1);
		cout << "Your first card is " << cardName1;
		if (cardRandom1 < 11 && cardRandom1 > 1)
		{
			cout << cardRandom1;
		}
		cout << endl;

		// randomize the player's second card, and set it's rank, value, and print it out
		cardRandom2 = getRandom();
		cardName2 = getName(cardRandom2);
		cardValue2 = getValue(cardRandom2);
		cout << "Your second card is " << cardName2;
		if (cardRandom2 < 11 && cardRandom2 > 1)
		{
			cout << cardRandom2;
		}
		cout << endl;

		// randomize the dealer's card, and set it's rank, value, and print it out
		cardRandom3 = getRandom();
		cardName3 = getName(cardRandom3);
		cardValue3 = getValue(cardRandom3);
		cout << "The dealer's card is " << cardName3;
		if (cardRandom3 < 11 && cardRandom3 > 1)
		{
			cout << cardRandom3;
		}
		cout << endl << endl;

		// total the player's cards, the dealer's cards, and start the player part of the game
		yourTotal = cardValue1 + cardValue2;
		dealerTotal = cardValue3;
		hit = true;
		while (hit == true)
		{
			cout << "Total, you have " << yourTotal << endl;
			if (yourTotal > 21)
			{
				cout << "Bust! Since your total is greater than 21, You lose." << endl;
				hit = false;
			}
			else
			{
				cout << "Hit or Stay? (Type h or s): ";
				cin >> action;
				cout << endl;

				switch (action)
				{
				case 'h':
					yourHitRandom = getRandom();
					yourHitName = getName(yourHitRandom);
					yourHitValue = getValue(yourHitRandom);

					cout << "Your next card is " << yourHitName;
					if (yourHitRandom < 11 && yourHitRandom > 1)
					{
						cout << yourHitRandom;
					}
					cout << endl;
					yourTotal = yourTotal + yourHitValue;
					break;

				case 's': hit = false;
					break;

				default:
					cout << "I didn't understand that, try again." << endl;
				}
			}
		}

		// dealer part of the game, only plays out if the player has not bust
		if (yourTotal < 22)
		{
			while (dealerTotal < 17)
			{
				cout << "The dealer has " << dealerTotal << " and must Hit." << endl;
				dealerHitRandom = getRandom();
				dealerHitName = getName(dealerHitRandom);
				dealerHitValue = getValue(dealerHitRandom);
				dealerTotal = dealerTotal + dealerHitValue;
				cout << "The dealer's next card is " << dealerHitName;
				if (dealerHitRandom < 11 && dealerHitRandom > 1)
				{
					cout << dealerHitRandom;
				}
				cout << endl;
				cout << "The dealer's new total is " << dealerTotal << endl << endl;
			}
			if (dealerTotal > 21)
			{
				cout << "The dealer's total is greater than 21, the dealer busts. You win!" << endl;
			}
			else
			{
				cout << "The dealer has " << dealerTotal << " and must Stay." << endl << endl;
				cout << "Your total is " << yourTotal << " and the dealer's total is " << dealerTotal << endl;
				if (yourTotal == dealerTotal)
				{
					cout << "Your totals are the same. Ties go to the dealer. You lose." << endl;
				}
				else
					if (yourTotal < dealerTotal)
					{
						cout << "The dealer's total is greater. You lose." << endl;
					}
					else
					{
						cout << "Your total is greater. You win!" << endl;
					}
			}
		}
		// ask to restart
		cout << "Play again? (Type y for yes.)";
		cin >> play_again;
		cout << "----------------------" << endl << endl;
	}
	return 0;
}
