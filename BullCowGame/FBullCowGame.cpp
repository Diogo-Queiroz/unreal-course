#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

// Put the getters up in the document, following the patterns
int32 FBullCowGame::GetMyCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetMyMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "famish";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (GetHiddenWordLength() != Guess.length()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// if the letter match includin place
			if (Guess[i] == MyHiddenWord[j] && i == j)
			{
				// increment bulls
				BullCowCount.Bulls++;
			}
			// else
			else if (Guess[i] == MyHiddenWord[j])
			{
				// increment cows
				BullCowCount.Cows++;
			}
		}
	}
	return BullCowCount;
}
