#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
void PrintGuess(std::string Guess);
std::string GetGuess();
bool AskToPlayAgain();


// entry point for the game
int main ()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0; // exit the game
}


void PrintIntro()
{
	// Introduce the game 
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	// Get a Guess from the Player
	constexpr int MAX_TRIES = 5;
	for (int i = 1; i <= MAX_TRIES; i++)
	{
		std::string Guess = GetGuess();
		PrintGuess(Guess);
	}
	return;
}

std::string GetGuess()
{
	std::string Guess = "";
	// Ask the Guess to playes
	std::cout << "Enter your Guess: ";
	getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(std::string Guess)
{
	std::cout << "Your Guess was: " << Guess << std::endl << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}