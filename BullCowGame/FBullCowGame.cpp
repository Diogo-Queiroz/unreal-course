#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

// Put the getters up in the document, following the patterns
int32 FBullCowGame::GetMyCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetMyMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "famish";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			// if the letter match includin place
			if (Guess[MHWChar] == MyHiddenWord[GChar] && MHWChar == GChar) 
			{
				
				BullCowCount.Bulls++; // increment bulls
			}
			else if (Guess[MHWChar] == MyHiddenWord[GChar])
			{
				BullCowCount.Cows++; // increment cows
			}
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
