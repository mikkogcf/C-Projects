/*
* Program Name: COP 2220 Project 3
*
* Description:  A program that counts the number of words and vowels of the user's input
*
* Author: John Micah Mercado (N01611717)
*
* Date: 11/06/2024
*/
// Pre processor directives
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Global declarations
#define SENTENCES  40
#define CHARACTERS 80
#define LIMIT 20

// function prototype
int WordCount(char [][CHARACTERS+2], int);
int VowelCount(char [][CHARACTERS+2], int);
void UserPrompt(char [][CHARACTERS+2], int, int);

int main()
{
	// local declarations
	int rows = SENTENCES;
	int cols = CHARACTERS + 2; // plus 2 to account for newline and terminator characters
	char arrayWords[SENTENCES][CHARACTERS+2] = {'\0'};
	int totalWords = 0;
	int totalVowels = 0;

	// local statements
	UserPrompt(arrayWords, rows, cols);
	totalWords = WordCount(arrayWords, rows);
	totalVowels = VowelCount(arrayWords, rows);
	printf("%d words and %d vowels\n", totalWords, totalVowels);

	return 0;
}
// User defined funtions
/*
* Function Name: UserPrompt
*
* Input Parameters: Takes array buffer, rows, and cols
*
* Description: User inputs strings
*
* Return Value: returns void
*/
void UserPrompt(char arrayWords[][CHARACTERS+2], int rows, int cols) {
	int i = 0;
	int length = 0;
	int c = 0;
	
	printf("Up to %d characters per sentence, please enter sentences until you have entered more than %d sentences or EOF to quit:\n", CHARACTERS, LIMIT);
	for(i = 0; i < rows; i++) {

		if(fgets(arrayWords[i], cols, stdin) != NULL) {
			length = strlen(arrayWords[i]);

			if(arrayWords[i][length-1] == '\n') { // change newline to terminator
				arrayWords[i][length-1] = '\0';
			}
			else {

				while ((c = getchar()) != '\n' && c != EOF) {
					// flushes input buffer after \n or ends input after EOF
				}
				if(length > cols-2) {
					printf("You entered more than %d characters! Only the first %d characters will be used.\n", cols-2, cols-2);
				}
				// truncates strings in max allowed characters
		   	arrayWords[i][cols-2] = '\0';
			}


			if(i+1 > LIMIT) { // checks if more than the limit
				printf("You have entered more than %d sentences.\n", LIMIT);
				break;
			}
		}
	}
	return;
}
/*
* Function Name: WordCount
*
* Input Parameters: Takes array buffer, rows, and cols
*
* Description: Counts all the words in an array
*
* Return Value: Returns the total number of words
*/
int WordCount(char arrayWords[][CHARACTERS+2], int rows) {
	int counter = 0;
	int inWord = 0;
	int i, j = 0;

	for(i = 0; i < rows; i++) { // move to next sentence
		inWord = 0; // reset inWord to 0 every new sentences
		for(j = 0; arrayWords[i][j] != '\0'; j++) { // move to next character
			if (isspace(arrayWords[i][j])) { // checks if true for space
				inWord = 0; // if space is present sets inWord to 0
			} else if(isalpha(arrayWords[i][j])) { // checks if true for letters
				if (!inWord) { // checks if inWord is 0 is true
					counter++; // counter for words
					inWord = 1; // resets inWord to 1
				}
			}
		}
	}
	return counter;
}
/*
* Function Name: VowelCount
*
* Input Parameters: Takes array buffer, rows, and cols
*
* Description: Counts all the vowels in an array
*
* Return Value: Returns the total number of vowels
*/
int VowelCount(char arrayWords[][CHARACTERS+2], int rows) {
	int counter = 0;
	int i, j = 0;

	for(i = 0; i < rows; i++) { // move to next sentence
		for(j = 0; arrayWords[i][j] != '\0'; j++) { // move to next character
			if(arrayWords[i][j] == 'a' || arrayWords[i][j] == 'e' || arrayWords[i][j] == 'i' ||
			        arrayWords[i][j] == 'o' || arrayWords[i][j] == 'u' || arrayWords[i][j] == 'A' || arrayWords[i][j] == 'E' || arrayWords[i][j] == 'I' || arrayWords[i][j] == 'O' || arrayWords[i][j] == 'U') {
				counter++;
			}
		}
	}
	return counter;
}