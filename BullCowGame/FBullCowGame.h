#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// two integers, initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame(); // Constructor

	int32 GetMyCurrentTry() const;
	int32 GetMyMaxTries() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString) const; // TODO make a more rich return value.
	// TODO create a new type to receive a guess, increase the counter of bulls and cows and go to next try #
	FBullCowCount SubmitGuess(FString);

// ^^ Care only for the code above ^^
private:
	// See constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};