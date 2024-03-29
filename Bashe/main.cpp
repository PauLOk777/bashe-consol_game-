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
string mediumBotTurn(int&, int, bool&);
string unrealBotTurn(int&, int);
bool gameOver(int numberOfStones) { return numberOfStones; }
bool firstTurn();

int main() {
	int numberOfStones;
	int maxStonesInTurn;
	string winner;
	int botsScore = 0;
	int playerScore = 0;
	while (true) {
		int levelOfBot = start(numberOfStones, maxStonesInTurn);
		bool flag = firstTurn();
		bool mediumFlag = true;
		while (gameOver(numberOfStones)) {
			draw(numberOfStones);
			if (flag) {
				winner = gamerTurn(numberOfStones, maxStonesInTurn);
				flag = false;
			}
			else {
				if (levelOfBot == 1) {
					winner = easyBotsTurn(numberOfStones, maxStonesInTurn);
				}
				if (levelOfBot == 2) {
					winner = mediumBotTurn(numberOfStones, maxStonesInTurn, mediumFlag);
				}
				if (levelOfBot == 3) {
					winner = hardBotTurn(numberOfStones, maxStonesInTurn);
				}
				if (levelOfBot == 4) {
					winner = unrealBotTurn(numberOfStones, maxStonesInTurn);
				}
				flag = true;
			}
			system("cls");
		}
		if (winner == "The bot wins!!!") {
			botsScore++;
		}
		else {
			playerScore++;
		}
		cout << winner << endl;
		cout << "Game over." << endl;
		cout << "Score (player - bot): " << endl;
		cout << playerScore << " - " << botsScore << endl;
		string trying = "";
		cout << "Do you wanna play more? If yes type 1, no - any key: "; cin >> trying;
		system("cls");
		if (trying != "1") break;
	}
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
	cout << "Change level of bot:\n"; cout << "1.Easy\n"; cout << "2.Medium\n"; cout << "3.Hard\n"; cout << "4.Unreal" << endl;
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
	cout << "Bot thinking..." << endl;
	Sleep(3000);
	if (numberOfStones % (maxStonesInTurn + 1) == 0) {
		int random = rand() % (maxStonesInTurn - 1) + 1;
		numberOfStones -= random;
	}
	else {
		int num;
		for (int i = 1; i <= maxStonesInTurn; i++) {
			if ((numberOfStones - i) % (maxStonesInTurn + 1) == 0) {
				numberOfStones -= i;
			}
		}
	}
	if (!gameOver(numberOfStones)) { return "The bot wins!!!"; }
	return "";
}

string mediumBotTurn(int &numberOfStones, int maxStonesInTurn, bool &flag)
{
	if (flag) {
		easyBotsTurn(numberOfStones, maxStonesInTurn);
		flag = false;
	}
	else {
		hardBotTurn(numberOfStones, maxStonesInTurn);
		flag = true;
	}
	if (!gameOver(numberOfStones)) { return "The bot wins!!!"; }
	return "";
}

string unrealBotTurn(int& numberOfStones, int maxStonesInTurn)
{
	cout << "Bot thinking..." << endl;
	Sleep(3000);
	if (numberOfStones % (maxStonesInTurn + 1) == 0) {
		numberOfStones -= (maxStonesInTurn + 1);
	}
	else {
		int num;
		for (int i = 1; i <= maxStonesInTurn; i++) {
			if ((numberOfStones - i) % (maxStonesInTurn + 1) == 0) {
				numberOfStones -= i;
			}
		}
	}
	if (!gameOver(numberOfStones)) { return "The bot wins!!!"; }
	return "";
}

bool firstTurn() {
	int num;
	cout << "If you wanna start first type 1, if no - any number: "; cin >> num;
	if (num == 1) {
		system("cls");
		return true;
	}
	else {
		system("cls");
		return false;
	}
}