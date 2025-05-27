/*
* Program Name: COP 2220 Project 4
*
* Description:  A program that reads the data of students grades then computes
*               for the average for each student then saves it on another file.
*
* Author: John Micah Mercado (N01611717)
*
* Date: 11/18/2024
*/

// Pre processor directives
#include <stdio.h>
#include <stdlib.h>

// Global declarations (none)
// function prototype
void UserPrompt(char*);
float** ReadStudentData(char*, int*, int*);
void OutputAvgGrade(char*, int, int, float**);

int main(void)
{
	// local declarations
	char userInputFile[101];
	char userOutputFile[101];
	int studentNumber = 0;
	int size = 0;
	float** inputArray;
	int i = 0;

	// local statements
	printf("Maximum of 100 characters. Please enter a file name to read or ctrl+D to quit.\n");
	UserPrompt(userInputFile);

	// program exits when EOF is detected
	if(feof(stdin)) {
		printf("Good Bye!\n");
		return 0;
	}

	inputArray = ReadStudentData(userInputFile, &studentNumber, &size);

	if(inputArray == NULL) {
		printf("Good Bye!\n");
		return 0;
	}

	printf("Please enter the name of the file you want to save to.\n");

	UserPrompt(userOutputFile);

	if(feof(stdin)) {
		printf("No file name entered so file was not processed and saved. Good bye!\n");
		for (i = 0; i < studentNumber; i++) {
			free(inputArray[i]);
		}
		free(inputArray);
		return 0;
	}

	OutputAvgGrade(userOutputFile, studentNumber, size, inputArray);

	// Free the array of pointers
	for (i = 0; i < studentNumber; i++) {
		free(inputArray[i]);
	}
	free(inputArray);

	return 0;

}
// User defined functions
/*
* Function Name: UserPrompt
*
* Input Parameters: Takes a string pointer
*
* Description: Takes a string from user input
*
* Return Value: Returns none
*/
void UserPrompt(char* userInput) {

	fscanf(stdin, "%s", userInput);

	return;
}
/*
* Function Name: ReadStudentData
*
* Input Parameters: Takes a string pointer, and 2 integer pointers
*
* Description: Gets the studentNumber and size size.
*
* Return Value: Returns double pointer float
*/
float** ReadStudentData(char* userInputFile, int* studentNumber, int* size) {
	FILE* inFile = NULL;
	int i = 0, j = 0;
	float** inputArray;

	inFile = fopen(userInputFile, "r");

	printf("The input file name is %s\n", userInputFile);

	while(inFile == NULL) {
		if(inFile == NULL) {
			printf("Could not open %s.\n", userInputFile);
			printf("Please enter another file name.\n");
			UserPrompt(userInputFile);
			inFile = fopen(userInputFile, "r");
		}
		if(feof(stdin)) {
			return NULL;
		}
	}

	fscanf(inFile, "%d %d", studentNumber, size);

	// Allocate memory for a 2D array of doubles
	inputArray = (float**)calloc(*studentNumber, sizeof(float*));

	// Allocate memory for each studentNumber
	for (i = 0; i < *studentNumber; i++) {
		inputArray[i] = (float*)calloc(*size, sizeof(float));
	}

	for (i = 0; i < *studentNumber; i++) {
		for (j = 0; j < *size; j++) {
			fscanf(inFile, "%f", &inputArray[i][j]);
		}
	}

	fclose(inFile);

	return inputArray;
}
/*
* Function Name: OutputAvgGrade
*
* Input Parameters: Takes a string pointer, 2 integers, and one double pointer float
*
* Description: Computes for the average for each student then save on a new file
*
* Return Value: Returns none
*/
void OutputAvgGrade(char* userOutputFile, int studentNumber, int size, float** inputArray) {
	FILE* outFile = NULL;
	int i = 0, j = 0;
	float sum = 0,  avg = 0;

	size++;
	// Reallocate memory for each studentNumber
	for ( i = 0; i < studentNumber; i++) {
		inputArray[i] = (float*)realloc(inputArray[i], (size) * sizeof(float));
	}
	// Calculation to get averages per student's grades
	for (i = 0; i < studentNumber; i++) {
		for (j = 1; j < size-1; j++) {
			sum += inputArray[i][j];
		}
		avg = sum/(size-2);
		inputArray[i][(size)-1] = avg;
		avg = 0;
		sum = 0;
	}

	outFile = fopen(userOutputFile, "w");

	printf("The output file name is %s\n", userOutputFile);

	fprintf(stdout, "\n%d\n", studentNumber);
	fprintf(stdout, "%d\n", size);

	for (i = 0; i < studentNumber; i++) {
		fprintf(stdout, "%08.0f ", inputArray[i][0]);
		for (j = 1; j < size; j++) {
			fprintf(stdout, "%6.2f ", inputArray[i][j]);
		}
		fprintf(stdout, "\n");

	}
	fprintf(stdout, "\n");
	printf("Your file was processed and saved, good bye!\n");

	fclose(outFile);

	return;
}
