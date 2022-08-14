# Computer-Assisted Instruction Program

This is a program that will help an elementary school student to pick a type of arithemetic problem to study. It uses the `rand` function to produce two positive integers and then prompt the user with a question such as "*How much is 6 times 7?*". Then the student inputs the answer. The program display messages corresponding to the correctness of the answer.

## Requirements

- ### Varying the Types of Problems

  | Number | Arithmetic Operation               |
  | ------ | ---------------------------------- |
  | 1      | Addition                           |
  | 2      | Subtraction                        |
  | 3      | Multiplication                     |
  | 4      | Division                           |
  | 5      | Random Mixture of Above Operations |

- ### Difficulty Levels

  | Number | Difficulty Level                 |
  | ------ | -------------------------------- |
  | 1      | Use single-digit numbers         |
  | 2      | Numbers as large as two digits   |
  | 3      | Numbers as large as three digits |
  | 4      | numbers as large as four digits  |
  | 5      | numbers as large as five digits  |

- ### Monitor Student Performance

    Count the number of correct and incorrect responses typed by the student. After student types 10 answers, the program calculates the percentage that are correct. If the percentage is lower than 75%, the program displays "*Please ask your teacher for extra help.*". If the percentage is higher than 75%, it displays "*Congratulations, you are ready to go to the next level!*". After displaying either of the messages, the program resets so another student can try it.

- ### Reducing Student Fatigue

    Display various comments for each answer. Use random-number generation to choose a number from 1 to 4 that will be used to select one of the four appropriate responses to each correct or incorrect answer. Use a switch statement to issue the responses.

    Possible responses to a correct answer:
    - Very good!
    - Excellent!
    - Nice work!
    - Keep up the good work!

    Possible responses to an incorrect answer:
    - No. Please try again.
    - Wrong. Try once more.
    - Don't give up!
    - No. Keep trying.
