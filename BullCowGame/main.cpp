#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGuess(FText Guess);
void PrintBullCowCount(FBullCowCount bullCowCount);
FText GetGuess();
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

		// TODO sumarise the game
	} while (bPlayAgain);
	return 0; // exit the game
}


void PrintIntro()
{
	// Introduce the game 
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?";
	std::cout << std::endl << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMyMaxTries();
	// Get a Guess from the Player
	// TODO change from FOR to WHILE loop when we are validating guess
	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetGuess(); // TODO make loop check validity of the guess

		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print bulls and cows to player

		PrintGuess(Guess);
		PrintBullCowCount(BullCowCount);
	}
	return;
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetMyCurrentTry();
	FText Guess = "";
	// Ask the Guess to playes
	std::cout << "Try " << CurrentTry << ". Enter your Guess: ";
	getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(FText Guess)
{
	std::cout << "Your Guess was: " << Guess;
	std::cout << std::endl << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintBullCowCount(FBullCowCount bullCowCount)
{
	std::cout << "Bulls: " << bullCowCount.Bulls;
	std::cout << " Cows: " << bullCowCount.Cows << std::endl;
}