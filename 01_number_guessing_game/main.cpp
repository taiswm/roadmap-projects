#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(){

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I am thinking of a number between 1 and 100" << std::endl;
    std::cout << "Depending on the difficulty, you will have a certain amount of guesses to guess the number" << std::endl;
    std::cout << "With each guess, i will tell you if my number is higher or lower than your guess" << std::endl;
    std::cout << "" << std::endl;

    int difficulty_lvl = 0;

    srand(time(0));
    int answer = rand() % 101;

    std::cout << "Please select your difficulty:" << std::endl;
    std::cout << "1. Easy - 10 guesses" << std::endl;
    std::cout << "2. Medium - 5 guesses" << std::endl;
    std::cout << "3. Hard - 3 guesses" << std::endl;

    std::cin >> difficulty_lvl;
    std::cout << "" << std::endl;

    if(difficulty_lvl == 1){
        int lives = 10;
        std::cout << "You have chosen easy mode" << std::endl;
        std::cout << "Lets begin!" << std::endl;
    }else if(difficulty_lvl == 2){
        int lives = 5;
        std::cout << "You have chosen medium mode" << std::endl;
        std::cout << "Lets begin!" << std::endl;
    }else if(difficulty_lvl == 3){
        int lives = 3;
        std::cout << "You have chosen hard mode" << std::endl;
        std::cout << "Lets begin!" << std::endl;
    }else{
        std::cout << "!!Invalid!!" << std::endl;
        std::cout << difficulty_lvl << " is not an option." << std::endl;
    }
    


    return 0;
}