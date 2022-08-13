/**
 * @file main.cpp
 * @author Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * HW #4 - Making A Difference
 * 
 * @brief The main test program that demonstrate the capabilities of the
 *      Computer-Assisted Instruction class
*/

#include <iostream>
#include "CAI.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


bool validateUserInput(int num){
    if (num < 1 || num >5){
        return false;
    }
    else{
        return true;
    }
}


void printBannerMessage(){
    // Print out banner message
    cout << endl;
    cout << "Welcome to the Computer-Assisted Instruction Program" << endl;
    cout << "********************************************************" << endl;
    cout << "This program helps you to learn arithemetic operations.\n"
            "Before we start, you need select which type of arithmetic operation "
            "you would like to study and the level of difficulty.\nPlease use the"
            " following table as a reference:\n Options for arithemetic operation: "
            "\n 1: Addition \n 2: Subtraction \n 3: Multiplication \n 4: Division"
            "\n 5: Random Mixture of Above Operations.\n \n Difficulty Level: \n"
            "1: Use single-digit only \n2: Numbers as large as two digits \n"
            "3: Numbers as large as three digits \n4: Numbers as large as four "
            "digits \n5: Numbers as large as five digits" << endl;
    cout << "********************************************************" << endl;
    cout << endl;
}


int captureUserInput(int inputType){

    bool isValidUserInput = false;
    int userInput;

    while (! isValidUserInput){
        switch(inputType){
            case 1:
                cout << "Please select the type of arithmetic operation you would"
                        " like to study:";
                break;
            case 2:
                cout << "Please select the level of difficulty: ";
                break;
        }
        cin >> userInput;
        isValidUserInput = validateUserInput(userInput);

        if (!isValidUserInput){
            cout << "Unsupported option. Please enter a new number" << endl;
        }
    }

    return userInput;

}


int main(){

    printBannerMessage();

    int problemType = captureUserInput(1);
    int difficultyLevel = captureUserInput(2);

    CAI cai(problemType, difficultyLevel);
    
    int answer = cai.generateQuestion();
    int userAnswer;
    cin >> userAnswer;

    if (userAnswer == answer){
        cai.displayPositiveResponse();
        cout << "positive" << endl;
    }
    else{
        cai.displayNegativeResponse();
        cout << "negative" << endl;
    }

    return 0;
}

