#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
void PrintGuess(std::string Guess);
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// entry point for the game
int main ()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0; // exit the game
}


void PrintIntro()
{
	// Introduce the game 
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?";
	std::cout << std::endl << std::endl;
	return;
}

void PlayGame()
{
	int MaxTries = BCGame.GetMyMaxTries();
	// Get a Guess from the Player
	for (int i = 1; i <= MaxTries; i++)
	{
		std::string Guess = GetGuess();
		PrintGuess(Guess);
	}
	return;
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetMyCurrentTry();
	std::string Guess = "";
	// Ask the Guess to playes
	std::cout << "Try " << CurrentTry << ". Enter your Guess: ";
	getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(std::string Guess)
{
	std::cout << "Your Guess was: " << Guess;
	std::cout << std::endl << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}