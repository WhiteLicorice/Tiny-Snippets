//  This is a small subprogram written by Rene Andre B. Jocsing in C
//  Input: String
//  Process: Check if the string is a positive integer
//  Output: Prompt whether the string is a positive integer or not, underlying integer representation of the string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int checkPositiveInteger(char *inputString);

int main()
{
    char userInput[100];                                        //  Declare a 100-character array for storing user input
    printf("Input a number: ");                                 //  Ask for user input
    scanf("%[^\n]s", userInput);                                //  Read user input and store in userInput
    int isPositiveInteger = checkPositiveInteger(userInput);    //  Check if the user input is a positive integer
    
    //  Check result of checkPositiveInteger
    if (isPositiveInteger != 0) {
        return 1;   //  Terminate program with an error -> user input is not a positive integer
    } else {
        int positiveInput = atoi(userInput);    //  Cast user input from string into an integer
        printf("The number is: ");              //  Printing prompt "The number is: ..."
        printf("%d\n", positiveInput);          //  Print out the integer representation of the user input
        return 0;                               //  Terminate program with 0 errors
    }
}

int checkPositiveInteger(char *inputString){
    //  Variable used to store the length of the string.
    int stringLength = strlen(inputString);
    
    //  Iterator -> Iterate through the string and increment the length until null character is found.
    //  Use this if <string.h> is not allowed
    //for (stringLength = 0 ; inputString[stringLength] != '\0' ; ++stringLength);

    //  Check each character if they are in the range of the character representations of integers from 0--9.
    for (int i = 0 ; i < stringLength ; i++) {
        //  If character is not from '0' to '9', reject input
        if(inputString[i] < '0' || inputString[i] > '9'){
            printf("Input should be only non-negative integers.\n");
            return 1;   //  Return status 1 signifies failure -> Input is not a positive integer
        }
    }
    printf("Input is a non-negative integer.\n");
    return 0;   //  Return status 0 signifies success -> the input is a positive integer
}
