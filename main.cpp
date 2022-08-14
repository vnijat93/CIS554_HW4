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
using std::left;


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
    cout << left;
    cout << "Welcome to the Computer-Assisted Instruction Program" << endl;
    cout << "********************************************************" << endl;
    cout << "This program helps you to learn arithemetic operations.\n"
            "Before we start, you need select which type of arithmetic operation "
            "you would like to study and the level of difficulty.\n";
    cout << "Please use the following tables as a reference:\n\n";
    cout << "Options for arithemetic operation:\n"
            "\t1: Addition \n"
            "\t2: Subtraction \n"
            "\t3: Multiplication \n"
            "\t4: Division\n"
            "\t5: Random Mixture of Above Operations.\n\n"
            "Difficulty Level: \n"
            "\t1: Use single-digit only \n"
            "\t2: Numbers as large as two digits \n"
            "\t3: Numbers as large as three digits \n"
            "\t4: Numbers as large as four digits \n"
            "\t5: Numbers as large as five digits" << endl;
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


void printResults(int correctAnswers, int wrongAnswers){
    cout << "Result:" << endl;
    cout << "\tCorrect Answers: " << correctAnswers <<endl;
    cout << "\tWrong Answers: " << wrongAnswers << endl;

    if (correctAnswers < 8){
        cout << "Please ask yout teacher for extra help.\n\n" << endl;
    }
    else{
        cout << "Congratulations, you are ready to go to the next level!\n\n" << endl;
    }
}


int main(){

    printBannerMessage();

    int exitCode = 0;
    cout << "Enter 0 to exit the program or 1 to start a new session: ";
    cin >> exitCode;

    while (exitCode == 1){
        int totalQuestions = 10;
        int correctAnswers = 0;
        int wrongAnswers = 0;

        int problemType = captureUserInput(1);
        int difficultyLevel = captureUserInput(2);
        cout << endl;

        CAI cai(problemType, difficultyLevel);

        while ((correctAnswers + wrongAnswers) < totalQuestions){
            int questionNumber = correctAnswers + wrongAnswers + 1;
            int answer = cai.generateQuestion(questionNumber);
            int userAnswer;
            cout << "Please enter your answer here: ";
            cin >> userAnswer;

            if (userAnswer == answer){
                cai.displayPositiveResponse();
                correctAnswers = correctAnswers + 1;
            }
            else{
                cai.displayNegativeResponse();
                wrongAnswers = wrongAnswers + 1;
            }
        }
        printResults(correctAnswers, wrongAnswers);

        cout << "Enter 0 to exit the program or 1 to start a new session: ";
        cin >> exitCode;
    }

    return 0;
}

