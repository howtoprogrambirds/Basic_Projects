# Number Guessing Game

This is a simple number guessing game where the player tries to guess a randomly generated number within a specified range. The program will provide feedback on each guess, indicating whether the guessed number is higher or lower than the target number. The game continues until the player guesses the correct number.

## Features

- Random Number Generation: The program generates a random integer within a specified range.
- User Input Validation: The program validates the user's input to ensure it is within the given range and is an integer.
- Feedback on Guesses: The program provides feedback to the player, indicating whether their guess is higher or lower than the target number.
- Game Completion: The game ends when the player correctly guesses the target number.

## Usage

1. The program will generate a random number between the `minValue` and `maxValue` (inclusive).
2. Enter your guess for the number when prompted.
3. The program will provide feedback based on your guess:
   - If your guess is lower than the target number, the program will display "higher, try again."
   - If your guess is higher than the target number, the program will display "lower, try again."
   - If your guess matches the target number, the program will display "CORRECT!!!" and the game will end.
4. Continue guessing until you guess the correct number.

## Example

```
Guess the number (from 1, 9): 5
lower, try again
Guess the number (from 1, 9): 3
lower, try again
Guess the number (from 1, 9): 7
higher, try again
Guess the number (from 1, 9): 6
CORRECT!!!
```

Note: The range of numbers is defined by the `minValue` and `maxValue` variables in the code. Adjust these values to change the range of numbers for the game.

Please make sure to enter valid integer guesses within the specified range to play the game successfully.