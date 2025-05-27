/*
* Program Name: COP 2220 Project 2
*
* Description:  A program that produces sets of six random numbers that is input by the user.
*
* Author: John Micah Mercado (N01611717)
*
* Date: 10/05/2024
*/
// Pre Processors Directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Declarations
// Function Prototype
char* PromptUser(char* userInput);
void RandVal(void);

int main(void)
{

// Local Declarations
	char userInput[2];
	int numSets;

// Local Statements
	srand(time(NULL)); // new random sequence every loop
	PromptUser(userInput); // Calls the function to prompt the user for input
	printf("Your Input: %s\n", userInput); // Prints user's input

// Checks for 'q' or 'Q' to end the program
	while(userInput[0] != 'q' && userInput[0] != 'Q') {
		sscanf(userInput, "%d", &numSets); // Converts char to integer

// Checks if user's input within range
		if(numSets >= 0 && numSets <= 10) {
			int count = 1;
// Will loop based on number of sets that user input
			while(count <= numSets) {
				printf("* Set # %2d of six numbers is:  ", count);
				RandVal(); // Calls the random value generator function
				printf("\n");
				count++;
			} // end loop
			PromptUser(userInput); // ask user input again after the program executes
			printf("Your Input: %s\n", userInput);
		} else {
			printf("Wrong Input.\n");
			PromptUser(userInput);
			printf("Your Input: %s\n", userInput);
		}
	} // end outer loop

	printf("You have chosen to exit the application.\n");

	return 0;
} // end main

// User Defined Functions

// function that prompts user and then returns the string
char* PromptUser(char* userInput) {
	printf("**************************************************************************\n");
	printf("* Enter in the number of randomly generated sets of numbers you want or  *\n");
	printf("* enter in a 'q' or Q' to quit.                                          *\n");
	printf("**************************************************************************\n");
	scanf("%s", userInput);
	return userInput;
}

// function that generates 6 random numbers
void RandVal(void) {
	int count = 0, numValues[6], i, newNumber;

	while(count < 6) { // Will loop 6 times

		newNumber = (rand() % 53)+1; // Generate number between 1 - 53

		// Check for duplicates
		for(i = 0; i < count; i++) {
			if(numValues[i] == newNumber) {
				newNumber = (rand() % 53)+1; // duplicate found so generate another number
				i = -1; // resets the number check for duplicates
			}
		} // end inner loop
		numValues[count] = newNumber;
		count++;
	} // end outer loop
	for (count = 0; count < 6; count++) {
		printf("%2d ", numValues[count]); // Prints six random numbers
	}
	return;
}