#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetMyCurrentTry() const;
	int32 GetMyMaxTries() const;
	bool IsGameWon() const;
	

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.
	// TODO create a new type to receive a guess, increase the counter of bulls and cows and go to next try #

// ^^ Care only for the code above ^^
private:
	// See constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
};