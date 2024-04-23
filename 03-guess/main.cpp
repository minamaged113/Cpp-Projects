/**
 * @file main.cpp
 * @author Mina Ghobrial (minamaged113@gmail.com)
 * @brief Randomly generate a number unknown to the user.
 *  The user needs to guess what that number is.
 *
 * The program will first randomly generate a number unknown
 * to the user. The user needs to guess what that number is. (In other words,
 * the user needs to be able to input information.) If the user’s guess is
 * wrong, the program should return some sort of indication as to how wrong
 * (e.g. The number is too high or too low). If the user guesses correctly, a
 * positive indication should appear. You’ll need functions to check if the user
 * input is an actual number, to see the difference between the inputted number
 * and the randomly generated numbers, and to then compare the numbers. Concepts
 * to keep in mind:
 *  Random function
 *  Variables
 *  Integers
 *  Input/Output
 *  Print
 *  While loops
 *  If/Else statements
 *
 * Jumping off the first project, this project continues to build up the base
 * knowledge and introduces user-inputted data at its very simplest. With user
 * input, we start to get into a little bit of variability.
 *
 * @version 0.1
 * @date 2024-04-21
 *
 * @copyright Copyright (c) 2024
 * @
 */
#include <iostream>
#include <limits>
#include "number/number.h"

void clear_cin() {
    // remove error flags for future `cin` attempts
    std::cin.clear();

    // ignore every input until newline from the whole stream buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int max = 3;
    int min = 0;
    Number::Number userInput(0);
    Number::Number randNumber(min, max);

    while (true) {
        std::cout << "Enter a number(" << min << "," << max
                  << "): " << randNumber.value << ": ";

        // if requested type does not match the entered type
        // `cin` returns `false`
        if (!(std::cin >> userInput)) {
            clear_cin();
        } else {
            if (randNumber == userInput) {
                std::cout << "BRAVO!!" << std::endl;
                break;
            } else {
                std::cout << "Correction factor: "
                          << -Number::error(userInput, randNumber) << std::endl;
            }
        }
    }
    return 0;
}
