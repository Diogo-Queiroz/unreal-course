#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
void PrintGuess(string Guess);
string GetGuess();
bool AskToPlayAgain();


// entry point for the game
int main ()
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();
	return 0; // exit the game
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

void PlayGame()
{
	// Get a Guess from the Player
	constexpr int MAX_TRIES = 5;
	for (int i = 1; i <= MAX_TRIES; i++)
	{
		string Guess = GetGuess();
		PrintGuess(Guess);
	}
	return;
}

string GetGuess()
{
	string Guess = "";
	// Ask the Guess to playes
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	return Guess;
}

void PrintGuess(string Guess)
{
	cout << "Your Guess was: " << Guess << endl << endl;
	return;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}