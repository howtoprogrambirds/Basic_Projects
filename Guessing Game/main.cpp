#include <iostream>
#include <random>

const int minValue = 1;
const int maxValue = 9;

// generate a random integer from the minvalue and the maxvalue.
int generateRandomNumber(int minValue, int maxValue){
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(minValue, maxValue);

    return distribution(generator);
}

// Makes an error message and resets the std::cin for a new input.
void makeCinErrorMessage(std::string errorMessage){
    std::cout << "\n" << errorMessage << std::endl;
    std::cin.clear();
    std::cin.ignore();
}

// It asks the user for a integer inside the given range by minValue and maxValue.
int askUserInteger(int minValue, int maxValue){
    int resultInteger;

    std::cout << "Guess the number (from " << minValue << ", " << maxValue << "): ";
    std::cin >> resultInteger;
    if (resultInteger > minValue && resultInteger < maxValue){
        return resultInteger;
    }
    else {
        bool correctInput = false;

        while (correctInput == false){
            if (std::cin.fail()){
                makeCinErrorMessage("ERROR: the given answer is not an integer");
            }
            else if (resultInteger < minValue || resultInteger > maxValue){
                makeCinErrorMessage("ERROR: the given integer is not in the given range");
            }
            else{
                correctInput = true;
                return resultInteger;
            }
            std::cout << "Guess the number (from " << minValue << ", " << maxValue << "): ";
            std::cin >> resultInteger;
        }
    }
    return resultInteger;
}
    
int main(void){
    int guessingNumber = generateRandomNumber(minValue, maxValue);
    int userInput;
    bool guessed = false;

    while (guessed == false){
        userInput = askUserInteger(minValue, maxValue);
        if (userInput < guessingNumber){
            std::cout << "higher, try again" << std::endl;
        }
        else if (userInput > guessingNumber){
            std::cout << "lower, try again" << std::endl;
        }
        else {
            std::cout << "CORRECT!!!!" << std::endl;
            guessed = true;
        }
    }
    
    return 0;
}