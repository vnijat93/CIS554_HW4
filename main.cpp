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

/**
 * Validate if user entered an aceeptable number
 * @param num integer: the number to be validated
 * @return boolean: true if the number is valid false otherwise
*/
bool validateUserInput(int num){
    if (num < 1 || num >5){
        return false;
    }
    else{
        return true;
    }
}


/**
 * Print the banner message when program starts
*/
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


/**
 * Capture user input when asked about selecting the problem type and the level
 * of difficulty
 * @param inputType integer
 *     1 -> Select problem type
 *     2 -> Select difficulty level
 * @return userInput integer: a validated userInput
*/
int captureUserInput(int inputType){

    // initialize isValidUserInput and set it to false
    // initialize userInput integer
    bool isValidUserInput = false;
    int userInput;

    // Ask user to enter a number until the input is valid.
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

        // Capture user input and validate the number
        cin >> userInput;
        isValidUserInput = validateUserInput(userInput);

        // If the input is not a valid number, ask user to enter a new number
        if (!isValidUserInput){
            cout << "Unsupported option. Please enter a new number" << endl;
        }
    }

    return userInput;

}


/**
 * Display a user's result after they answering all 10 questions
 * @param correctAnswers integer: number of correct answers
 * @param wrongAnswers integer: number of wrong answers
 * @return userInput integer: a validated userInput
*/
void printResults(int correctAnswers, int wrongAnswers){
    cout << "Result:" << endl;
    cout << "\tCorrect Answers: " << correctAnswers <<endl;
    cout << "\tWrong Answers: " << wrongAnswers << endl;

    // Monitor student performance
    if (correctAnswers < 8){
        cout << "Please ask yout teacher for extra help.\n\n" << endl;
    }
    else{
        cout << "Congratulations, you are ready to go to the next level!\n\n" << endl;
    }
}


int main(){

    printBannerMessage();

    // Initialize exitCode. This integer will be used to determine if users
    // want to continue or exits the program.
    int exitCode = 0;
    cout << "Enter 0 to exit the program or 1 to start a new session: ";
    cin >> exitCode;

    // If a user enters 0, exit the program. 
    // If a user enters 1, continue/reset.
    while (exitCode == 1){

        // Initialize integers used to keep track of a user'e performance
        int totalQuestions = 10;
        int correctAnswers = 0;
        int wrongAnswers = 0;

        // Capture problemType and difficultyLevel from user
        int problemType = captureUserInput(1);
        int difficultyLevel = captureUserInput(2);
        cout << endl;

        // Construct CAI class
        CAI cai(problemType, difficultyLevel);

        // If a user hasnt answered 10 questions, keep asking question
        // otherwise, exit the while loop and provide an opportunity for user
        // to either exit or reset
        while ((correctAnswers + wrongAnswers) < totalQuestions){

            // Get questionNumber which is used by user to keep track of progress
            int questionNumber = correctAnswers + wrongAnswers + 1;

            // Ask a user a question and assign the correct answer to integer answer
            int answer = cai.generateQuestion(questionNumber);

            // Capture user's answer
            int userAnswer;
            cout << "Please enter your answer here: ";
            cin >> userAnswer;

            // If the user answered correctly, display a positive response and
            // and increment correctAnswer by 1
            if (userAnswer == answer){
                cai.displayPositiveResponse();
                correctAnswers = correctAnswers + 1;
            }

            // If the user answered incorrectly, display a negative response and
            // and increment wrongAnswers by 1
            else{
                cai.displayNegativeResponse();
                wrongAnswers = wrongAnswers + 1;
            }
        }

        // Once the user answered all 10 questions, display the result
        printResults(correctAnswers, wrongAnswers);

        // Ask the user whether they want to exit the program or start a new session
        cout << "Enter 0 to exit the program or 1 to start a new session: ";
        cin >> exitCode;
    }

    return 0;
}

