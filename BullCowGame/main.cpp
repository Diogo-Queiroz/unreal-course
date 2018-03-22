#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main ()
{
	PrintIntro();

	// Get a Guess from the Player
	constexpr int MAX_TRIES = 5;
	for (int i = 1; i <= MAX_TRIES; i++)
	{
		GetGuessAndPrintBack();
	}

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
	// Ask the Guess to playes
	cout << "Enter your Guess: ";
	getline(cin, Guess);

	// Print guess back to Player
	cout << "Your Guess was: " << Guess << endl << endl;
	return Guess;
}