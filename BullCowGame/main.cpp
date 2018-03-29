#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGuess(FText Guess);
void PrintBullCowCount(FBullCowCount BullCowCount);
FText GetValidGuess();
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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?";
	std::cout << std::endl << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMyMaxTries();
	// Get a Guess from the Player
	for (int32 i = 1; i <= MaxTries; i++) // TODO change from FOR to WHILE
	{
		FText Guess = GetValidGuess(); 

		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// print bulls and cows to player

		PrintGuess(Guess);
		PrintBullCowCount(BullCowCount);
	}
	return;
}

// loop continually until guess is valid
FText GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	int32 CurrentTry = BCGame.GetMyCurrentTry();
	FText Guess = "";
	do
	{
		std::cout << "Try " << CurrentTry << ". Enter your Guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a guess that is an isogram, no repeated letters." << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " word length." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a guess that is all lowercase." << std::endl;
			break;
		case EGuessStatus::Special_Character_Included:
			std::cout << "Please enter a guess that has no special character." << std::endl;
			break;
		default:
			// assume guess is correct
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // Keep looping until get no errors	
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

void PrintBullCowCount(FBullCowCount BullCowCount)
{
	std::cout << "Bulls: " << BullCowCount.Bulls;
	std::cout << " Cows: " << BullCowCount.Cows << std::endl;
}