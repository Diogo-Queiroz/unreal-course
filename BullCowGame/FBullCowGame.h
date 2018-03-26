#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TODO make a more rich return value.
	int GetMyCurrentTry();
	int GetMyMaxTries();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); // TODO make a more rich return value.


// ^^ Care only for the code above ^^
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};