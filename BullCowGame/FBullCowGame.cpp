#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

// Put the getters up in the document, following the patterns
int32 FBullCowGame::GetMyCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetMyMaxTries() const { return MyMaxTries; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// recieves a VALID guess, increments turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	BullCowCount BullCowCount;
	// loop through all letters in the guess
		// compare letters against the hidden word
	
	
	return BullCowCount;
}
