#include <iostream>
#include <ctime>

void PrintIntroduction (int Difficulty)
{
     // First lines at start of each level
    std::cout << "\n\nYou are a tomb robber, breaking into a level " << Difficulty;
    std::cout << " secret crypt..\n\nYou need to enter the correct combination to open the door...\n\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You broke through, keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** The roof starts shaking, that was the wrong code! ***";
        return false;
    }
}

int main()    
{    
    srand(time(NULL)); // Create random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);// Tells us if player has completed level or not
        std::cin.clear();// Clears any errors
        std::cin.ignore();// Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n\n*** You're in, all the riches are yours! ***";
    return 0;
}