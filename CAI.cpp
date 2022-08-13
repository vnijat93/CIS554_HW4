/**
 * @file CAI.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * HW #4 - Making A Difference
 *
 * @brief The implementation of the Computer-Assisted Instruction (CAI) class
**/

#include "CAI.h"
#include <time.h>
#include <iomanip>
#include <iostream>
#include <random>

// using std::srand;
using std::cout;
using std::endl;
// using std::rand;


/**
 * Clacc constructor specifying number of asterisks to display.
 * @param pt: int problem type
 * @param dl: int the level of difficulty
*/
CAI::CAI(int pt, int dl){
    problemType = pt;
    difficultyLevel = dl;
    // cout << "problemType: " << problemType << endl; 
}


void CAI::setProblemType(int newProblemmType){
    problemType = newProblemmType;
}


int CAI::getProblemType() const{
    return problemType;
}


void CAI::setDifficultyLevel(int newDifficultyLevel){
    difficultyLevel = newDifficultyLevel;
}


int CAI::getDifficultyLevel() const{
    return difficultyLevel;
}


int CAI::generateRandomNumber(int lowerLimit, int upperLimit) const{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randomInt(lowerLimit, upperLimit);

    int randomNumber = randomInt(gen);

    return randomNumber;
}


int CAI::generateRandomNumberForQuestions(int offset) const{

    int randomNumberForQuestion;

    switch(difficultyLevel){
        case 1:
            randomNumberForQuestion = generateRandomNumber(offset, 9);
            break;
        case 2:
            randomNumberForQuestion = generateRandomNumber(offset, 99);
            break;
        case 3:
            randomNumberForQuestion = generateRandomNumber(offset, 999);
            break;
        case 4:
            randomNumberForQuestion = generateRandomNumber(offset, 9999);
            break;
        case 5:
            randomNumberForQuestion = generateRandomNumber(offset, 99999);
            break;
    }
    return randomNumberForQuestion;
}


int CAI::generateQuestion() const{

    int rand1 = generateRandomNumberForQuestions();
    int rand2 = generateRandomNumberForQuestions();
    int answer;

    int probTy;

    if (problemType == 5){
        probTy = generateRandomNumber(1, 4); 
    }
    else{
        probTy = problemType;
    }

    switch(probTy){
        case 1:
            answer = rand1 + rand2;
            cout << "How much is " << rand1 << " plus " << rand2 << "?" << endl;
            break;
        case 2:
            answer = rand1 - rand2;
            cout << "How much is " << rand1 << " minus " << rand2 << "?" << endl;
            break;
        case 3:
            answer = rand1 * rand2;
            cout << "How much is " << rand1 << " times " << rand2 << "?" << endl;
            break;
        case 4:
            if (rand2 == 0){
                rand2 = generateRandomNumberForQuestions(1);
            }
            int product = rand1 * rand2;
            answer = rand1;
            cout << "How much is " << product << " divided by " << rand2 << "?" << endl;
            break;           
    }

    return answer;
}


void CAI::displayPositiveResponse(){

    int response = generateRandomNumber(0, 3);
    // cout << "response: " << response << endl;

    switch(response){
        case 0:
            cout << "Very good!";
            break;
        case 1:
            cout << "Excellent!";
            break;
        case 2:
            cout << "Nice work!";
            break;
        case 3:
            cout << "Keep up the good work!";
            break;
    }
}


void CAI::displayNegativeResponse(){

    int response = generateRandomNumber(0, 3);
    // cout << "response: " << response << endl;

    switch(response){
        case 0:
            cout << "You got it wrong. You will get it right next time";
            break;
        case 1:
            cout << "That was a wrong answer.";
            break;
        case 2:
            cout << "Wrong answer. But don't give up";
            break;
        case 3:
            cout << "No. That's not the answer";
            break;
    }
}
