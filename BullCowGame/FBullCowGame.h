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

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Special_Character_Included // TODO check if it is possible and needed.
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
	EGuessStatus CheckGuessValidity(FString) const;
	// TODO create a new type to receive a guess, increase the counter of bulls and cows and go to next try #
	FBullCowCount SubmitValidGuess(FString);

// ^^ Care only for the code above ^^
private:
	// See constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};