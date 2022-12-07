// Copyright (c) 2022 Marcus Wehbi All rights reserved.
//
// Created by: Marcus Wehbi
// Created on: Nov 29 2022
// This program asks the user for three parameters
// The parameters are an operation and two numbers.
// Then it calculates and displays the results

#include <cmath>
#include <iomanip>
#include <iostream>

// This function performs the calculations
double calculate(char sign, float firstNum, float secondNum) {
    // Declare a variable for the result of the calculations
    float result;

    // If the sign is modulus, get the remainder
    if (sign == '%') {
        result = fmod(firstNum, secondNum);
    } else if (sign == '/') {
    // If the sign is division, divide the numbers
        result = firstNum / secondNum;
    } else if (sign == '*') {
    // If the sign is multiplication, multiply the numbers
        result = firstNum * secondNum;
    } else if (sign == '-') {
    // If the sign is subtraction, subtract the numbers
        result = firstNum - secondNum;
    } else {
    // Otherwise it has to be addition, so add the numbers
        result = firstNum + secondNum;
    }
    // Return the result of the calculation
    return result;
}

// Function to ge the numbers and operation
int main() {
    // Explain what the program does
    std::cout << "This program will perform calculations between two numbers!";
    std::cout << std::endl;
    std::cout << std::endl;
    // Declare variables (sign, numbers as strings, numbers as floats)
    char userSign;
    std::string firstNumString, secondNumString;
    float firstNumFloat, secondNumFloat;
    // Get the result as a double
    double resultUser;

    // Get the users operation of choice
    std::cout << "Enter the operation you want to perform (+, -, *, /, %): ";
    std::cin >> userSign;

    // Check if invalid operator was entered
    if (userSign == '+' || userSign == '-' || userSign == '*' ||
        userSign == '/' || userSign == '%') {
        // Get the users first number
        std::cout << "Enter the first number: ";
        std::cin >> firstNumString;

        try {
            // Convert the first number to a float
            firstNumFloat = std::stof(firstNumString);
            // Get the users second number
            std::cout << "Enter the second number: ";
            std::cin >> secondNumString;

            try {
                // Convert the second number to a float
                secondNumFloat = std::stof(secondNumString);

                // Assign the returned value to this variable
                resultUser = calculate(userSign, firstNumFloat, secondNumFloat);

                // Display the result of the calculations
                std::cout << std::endl;
                std::cout << "The result of " << firstNumFloat << "";
                std::cout << userSign << "" << secondNumFloat;
                std::cout << " is " << resultUser;

                // Determines if the input is valid
            } catch (std::invalid_argument) {
                // Tells the user they did not input a valid number
                std::cout << secondNumString << " is not a valid number.";
            }
        } catch (std::invalid_argument) {
            // Catches invalid number input
            std::cout << firstNumString << " is an invalid number.";
        }
    } else {
        // Catches invalid sign input
        std::cout << "Error. " << userSign << " is not a recognized operation.";
    }
}
