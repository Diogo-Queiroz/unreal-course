#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	return;
}

int FBullCowGame::GetMyCurrentTry()
{
	return MyCurrentTry;
}

int FBullCowGame::GetMyMaxTries()
{
	return MyMaxTries;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
