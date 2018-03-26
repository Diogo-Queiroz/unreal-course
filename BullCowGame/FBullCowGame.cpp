#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

// Put the getters up in the document, following the patterns
int32 FBullCowGame::GetMyCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetMyMaxTries() const { return MyMaxTries; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

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
