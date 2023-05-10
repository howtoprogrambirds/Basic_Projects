#include <iostream>
#include <string>
#include <iomanip>

const char YES = 'y';
const char NO = 'n';
const char PLUS = '+';
const char MINUS = '-';
const char MULTIPLY = '*';
const char DIVIDE = '/';

// This function performs a operation by the given numbers and the operator.
float performOperation(float firstNumber, float secondNumber, char operation){
    float operationResult;
    switch(operation){
        case PLUS: 
            operationResult = firstNumber + secondNumber;
            break;
        case MINUS: 
            operationResult = firstNumber - secondNumber;
            break;
        case MULTIPLY: 
            operationResult = firstNumber * secondNumber;
            break;
        case DIVIDE: 
            if (firstNumber == 0.0f || secondNumber == 0.0f){
                // If one of the 2 numbers is 0 by a dividing operator it can't workout correctly
                std::cout << "ERROR: The numbers you use are: " << firstNumber << ", " << secondNumber << " and the operation you use is: " << operation 
                << "\nIt's impossible to divide with zero.\n" << "The result of the operation will have the value of the default " << operationResult << std::endl;
                operationResult = 0.0f;
            }
            else {
                operationResult = firstNumber / secondNumber;
            }
            break;
        default:
            operationResult = 0.0f;
            break;
    }
    return operationResult;
}

// Makes an error message and resets the std::cin for a new input.
void makeCinErrorMessage(std::string errorMessage){
    std::cout << errorMessage;
    std::cin.clear();
    std::cin.ignore();
}

// It asks for a number by the std::cin and if it's not a float, it will send a error message and ask a number again.
float inputUserNumber(){
    float number;

    std::cout << "Enter a number: ";
    std::cin >> number;
    while(std::cin.fail()){
        makeCinErrorMessage("ERROR: a integer/float is expected \n");
        std::cout << "Enter a number: ";
        std::cin >> number;
    }
    return number;
}

// It asks for a specific operator char +, -, *, /. If it's not giving a error message will pop up and ask the question again.
char inputUserOperation(){
    char operation;

    std::cout << "choose an operator (+, -, *, /): ";
    std::cin >> operation;
    while(std::cin.fail() || operation != '+' && operation != '-' && operation != '*' && operation != '/'){
        makeCinErrorMessage("ERROR: a char(+, -, *, /) is expected \n");
        std::cout << "choose an operator (+, -, *, /): ";
        std::cin >> operation;
    }

    return operation;
}

// Show the result of the operation.
void showResult(float firstNumber, float secondNumber, char operation, float result){
    std::cout << "RESULT\n";
    std::cout << "First number: " << firstNumber << "\n";
    std::cout << "Second number: " << secondNumber << "\n";
    std::cout << "Operator: " << operation << "\n";
    std::cout << "Result: " << std::setprecision(4)<< result << "\n";
}
    
// A calculator with the operators plus, minus, multiply and divide. You can continue with the result of the previous calculation.
int main() {
    float firstNumber;
    float secondNumber;
    char operation;
    char continue_flag = YES;

    firstNumber = inputUserNumber();

    while(continue_flag == YES){

        secondNumber = inputUserNumber();
        operation = inputUserOperation();

        float result = performOperation(firstNumber, secondNumber, operation);
        showResult(firstNumber, secondNumber, operation, result);

        std::cout << "Continue? (y/n): ";
        std::cin >> continue_flag;

        switch (continue_flag){
            case YES:
                firstNumber = result;
                break;
            case NO:
                break;
            default:
                return 0;
                break;

        }
    }
    return 0;
}
