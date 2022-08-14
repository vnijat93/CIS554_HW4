/**
 * @file CAI.h
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * HW #4 - Making A Difference
 * 
**/

#ifndef CAI_H
#define CAI_H

/**
 * Implementation of the Computer  class for HW4.
 * 
 * A CAI class has two private data members
 * - problemType: an integer thats between 1 and 5 which represents the arithemetic
 *      operation a user want to study
 *      1 -> Addition
 *      2 -> Subtraction
 *      3 -> Multiplication
 *      4 -> Division
 *      5 -> Random Mixture of Above Operations
 * - difficultyLevel: an integer thats between 1 and 5 which represents the level
 *      of defificulty a user decided to study.
 *      1 -> All numbers are single digit
 *      2 -> Numbers as large as two digits
 *      3 -> Numbers as large as three digits
 *      4 -> Numbers as large as four digits
 *      5 -> Numbers as large as five digits
 * Provided Function:
 *  - Each private data member has its own setter and getter functions
 *  - Function displayAsterisks() can be used to display asterisks
**/
class CAI{

    private:

        int problemType;
        int difficultyLevel;

    public:
        /**
         * Clacc constructor specifying probelem typoes and the level of difficulty.
        */
        CAI(int problemType, int difficultyLevel);

        void setProblemType(int newProblemType);
        int getProblemType() const;

        void setDifficultyLevel(int newDifficultyLevel);
        int getDifficultyLevel() const;

        int generateRandomNumber(int lowerLimit, int upperLimit) const;
        int generateRandomNumberForQuestions(int offset=0) const;
        int generateQuestion(int questionNumber) const;

        void displayPositiveResponse();
        void displayNegativeResponse();

};

#endif
