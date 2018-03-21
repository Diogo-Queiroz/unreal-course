#include <iostream>
#include <string>

using namespace std;

int main ()
{
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH <<" letter isogram I'm thinking of?\n";
	cout << endl;

	// Get a Guess from the Player
	string Guess = "";
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	// Repeat the Guess back to them
	cout << "Your Guess was: " << Guess << endl;
	// Get a Guess from the Player
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	// Repeat the Guess back to them
	cout << "Your Guess was: " << Guess << endl;

	return 0;
}