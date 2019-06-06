#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>

using namespace std;

int start(int&, int&);
void draw(int);
string gamerTurn(int&, int);
string easyBotsTurn(int&, int);
string hardBotTurn(int&, int);
string mediumBotTurn(int&, int);
bool gameOver(int numberOfStones) { return numberOfStones; };

int main() {
	int numberOfStones;
	int maxStonesInTurn;
	int counterOfTurns = 0;
	int levelOfBot = start(numberOfStones, maxStonesInTurn);
	string winner;

	while (gameOver(numberOfStones)) {
		draw(numberOfStones);
		if (counterOfTurns % 2 == 0) {
			winner = gamerTurn(numberOfStones, maxStonesInTurn);
			counterOfTurns++;
		}
		else {
			if (levelOfBot == 1) {
				winner = easyBotsTurn(numberOfStones, maxStonesInTurn);
			}
			if (levelOfBot == 2) {
				winner = mediumBotTurn(numberOfStones, maxStonesInTurn);
			}
			if (levelOfBot == 3) {
				winner = hardBotTurn(numberOfStones, maxStonesInTurn);
			}
			counterOfTurns++;
		}
		system("cls");
	}

	cout << winner << endl;
	cout << "Game over." << endl;
	system("pause");
	return 0;
}

int start(int& numberOfStones, int& maxStonesInTurn) {
	cout << "\t\t\t\t\tBASHE\n";
	cout << "Rules of the game:" << endl;
	cout << "1. You have N-numbers of stones. Each player takes from 1 to M stones." << endl;
	cout << "2. In this game you can set the numbers of stones and the maximum number of stones per move that a player can take.\n";
	cout << "3. Lost one who has nothing to take." << endl;
	system("pause");
	system("cls");
	cout << "Now input number of stones: "; cin >> numberOfStones;
	cout << "Then input maximum number of stones per move that a player can take: "; cin >> maxStonesInTurn;
	int level;
	cout << "Change level of bot:\n"; cout << "1.Easy\n"; cout << "2.Medium\n"; cout << "3.Hard" << endl;
	cout << "Input number: "; cin >> level;
	system("cls");
	return level;
}

void draw(int numberOfStones) {
	int count = 1;
	cout << "You have " << numberOfStones << " stones." << endl;
	for (int i = 0; i < numberOfStones; i++) {
		for (int j = 0; j < count; j++) {
			cout << "@";
		}
		cout << endl;
		numberOfStones -= count;
		count++;
	}
	if (numberOfStones) {
		for (int i = 0; i < numberOfStones; i++) {
			cout << "@";
		}
		cout << endl;
	}
}

string gamerTurn(int &numberOfStones, int maxStonesInTurn)
{
	int stones;
	cout << "Input how many stones you wanna take: "; cin >> stones;
	if(stones < 1 || stones > maxStonesInTurn) {
		while (true) {
			cout << "Input how many stones you wanna take: "; cin >> stones;
			if (stones >= 1 && stones <= maxStonesInTurn) break;
		}
	}
	numberOfStones -= stones;
	if (!gameOver(numberOfStones)) { return "The player wins!!!"; }
	return "";
}

string easyBotsTurn(int &numberOfStones, int maxStonesInTurn)
{
	cout << "Bot thinking..." << endl;
	Sleep(3000);
	if (numberOfStones <= maxStonesInTurn) {
		numberOfStones = 0;
	}
	else {
		if (numberOfStones <= 2 * maxStonesInTurn) {
			if (numberOfStones == maxStonesInTurn + 1) {
				numberOfStones -= 1;
			}
			else {
				numberOfStones -= maxStonesInTurn - 1;
			}
		}
		else {
			int stones = rand() % (maxStonesInTurn - 1) + 1;
			numberOfStones -= stones;
		}
	}
	if (!gameOver(numberOfStones)) { return "The bot wins!!!"; }
	return "";
}

string hardBotTurn(int &numberOfStones, int maxStonesInTurn)
{
	return "";
}

string mediumBotTurn(int &numberOfStones, int maxStonesInTurn)
{
	return "";
}
