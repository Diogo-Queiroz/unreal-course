#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main ()
{
	PrintIntro();

	// Get a Guess from the Player
	GetGuessAndPrintBack();
	GetGuessAndPrintBack();
	return 0;
}

void PrintIntro()
{
	// Introduce the game 
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

string GetGuessAndPrintBack()
{
	string Guess = "";
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	cout << "Your Guess was: " << Guess << endl;
	return Guess;
}