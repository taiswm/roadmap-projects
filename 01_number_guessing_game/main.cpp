#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono> //Til tidtagning
#include <vector>
#include <cmath>    // for std::abs
#include <limits>   // for std::numeric_limits

using namespace std::chrono;


int getClosestGuess(const std::vector<int>& prevGuesses, int target) {
    int closestGuess = 0;
    int smallestDiff = std::numeric_limits<int>::max();

    for (int guess : prevGuesses) {
        int diff = std::abs(guess - target);
        if (diff < smallestDiff) {
            smallestDiff = diff;
            closestGuess = guess;
        }
    }

    return closestGuess;
}


int main()
{

    srand(time(0));
    

    int playAgain = 1;

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I am thinking of a number between 1 and 100" << std::endl;
    std::cout << "Depending on the difficulty, you will have a certain amount of guesses to guess the number" << std::endl;
    std::cout << "With each guess, i will tell you if my number is higher or lower than your guess" << std::endl;
    std::cout << "" << std::endl;

    do
        {
            int difficulty_lvl = 0;
            int startlives = 0;
            int guessHint = -1;

            int answer = rand() % 100 + 1;

            while (true)
            {

                std::cout << "Please select your difficulty:" << std::endl;
                std::cout << "1. Easy - 10 guesses" << std::endl;
                std::cout << "2. Medium - 5 guesses" << std::endl;
                std::cout << "3. Hard - 3 guesses (no hints)" << std::endl;
                std::cin >> difficulty_lvl;
                std::cout << "" << std::endl;

                if (difficulty_lvl == 1)
                {
                    startlives = 10;
                    guessHint = 5;
                    std::cout << "You have chosen easy mode" << std::endl;
                    std::cout << "Lets begin!" << std::endl;
                    break;
                }
                else if (difficulty_lvl == 2)
                {
                    startlives = 5;
                    guessHint = 2;
                    std::cout << "You have chosen medium mode" << std::endl;
                    std::cout << "Lets begin!" << std::endl;
                    break;
                }
                else if (difficulty_lvl == 3)
                {
                    startlives = 3;
                    std::cout << "You have chosen hard mode" << std::endl;
                    std::cout << "Lets begin!" << std::endl;
                    break;
                }
                else
                {
                    std::cout << "!!Invalid!!" << std::endl;
                    std::cout << difficulty_lvl << " is not an option." << std::endl;
                }
            }

            int lives = startlives;
            bool status2 = 0;
            auto start_timer = high_resolution_clock::now();
            int hintsUsed = 0;
            std::vector<int> prevGuesses = {};


            while (status2 == 0)
            {

                if(lives == guessHint){
                    int hintWant = 0;
                    std::cout << "Do you want a hint?\n1. Yes\n2. No\n";
                    std::cin >> hintWant;
                    if(hintWant == 1){
                        hintsUsed++;
                        int hint = getClosestGuess(prevGuesses, answer);
                        std::cout << "Hint: Your closest guess so far is " << hint << "." << std::endl;
                    }else{
                    }
                }


                int guess = 0;
                std::cout << "Enter your guess: " << std::endl;
                std::cin >> guess;
                prevGuesses.push_back(guess);


                if (guess < answer)
                {
                    std::cout << "The answer is greater than " << guess << std::endl;
                    lives--;
                }
                else if (guess > answer)
                {
                    std::cout << "The answer is less than " << guess << std::endl;
                    lives--;
                }
                else
                {
                    std::cout << "\nCongratulations! The answer was " << answer << std::endl;
                    std::cout << "It took you " << startlives - lives + 1 << " attemps to guess the number." << std::endl;
                    auto end_timer = high_resolution_clock::now();
                    duration<double> elapsed = end_timer - start_timer;
                    std::cout << "You completed the game in " << elapsed.count() << " seconds!" << std::endl;
                    if(hintsUsed == 0){
                        std::cout << "You used 0 hints!" << std::endl;
                    }else{
                        std::cout << "You used 1 hint!" << std::endl;
                    }
                    status2 = 1;
                }
                if (lives == 0)
                {
                    std::cout << "\nYou ran out of attempts! The answer was " << answer << std::endl;
                    status2 = 1;
                }
                


            }


            std::cout << "\nDo you want to play again?" << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;
            std::cin >> playAgain;

        }while (playAgain == 1);

        std::cout << "Thanks for playing!" <<std::endl;
    return 0;

}
