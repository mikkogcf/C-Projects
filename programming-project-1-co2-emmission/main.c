/*
* Program Name: COP 2220 Project 1
*
* Description:  A program that will calculate the total tonnage in CO2 emissions
* that vehicle T will produce over a lifespan of 150,000 miles of ownership
* as well as compute the added emissions from the battery manufacturing process.
*
* Author: John Micah Mercado (N01611717)
*
* Date: 08/29/2024
*/
// Pre Processors Directives
#include <stdio.h>

// Global Declarations
#define ELECTRICALGRID_RATE 650 // the rate of how much CO2 emitted per kWh when using the electrical grid (g/kWh)
#define LIFESPAN 150000 // the total lifespan of a car in kilometers (km)

int main()
{

// Local Declarations
	float minEmissions = 0;
	float maxEmissions = 0;
	float avgEmissions = 0;
	float batteryCapacity = 0;
	float carRange = 0;
	float lifespanEmissions = 0;


// Local Statements
	// program will prompt user to input minimum kg of emissions (kg/kWh)
	printf("Enter in data reflecting the kilograms of CO2\n");
	printf("produced per kWh of battery capacity.\n");
	printf("Minimum kg of CO2 per kWh: ");
	scanf("%f", &minEmissions);

	// program will prompt user to input maximum kg of emissions (kg/kWh)
	printf("Maximum kg of CO2 per kWh: ");
	scanf("%f", &maxEmissions);

	// program will compute the emission for minimum and maximum
	minEmissions = minEmissions*79/1000; // 1000 kg = 1 metric ton
	maxEmissions = maxEmissions*79/1000;

	// program will compute the average emission in battery manufacturing
	avgEmissions = (minEmissions + maxEmissions)/2;

	// program will prompt user to input the battery battery capacity (kWh)
	printf("Enter the capacity/size in kWh of the battery: ");
	scanf("%f", &batteryCapacity);

	// program will prompt user to enter the car range
	printf("Enter the range in km of the battery: ");
	scanf("%f", &carRange);
	printf("\n");

	// program will compute the total emissions used on the lifespan of a car (tons)
	// conversion of g to tons is 1,000,000kg = 1 metric ton
	lifespanEmissions = batteryCapacity/carRange*ELECTRICALGRID_RATE*LIFESPAN/1000000;

	// program will print the summary breakdown of emissions
	printf("Computing the emissions of CO2 making the battery in tons.\n");
	printf("The minimum CO2 for the battery is: %.2f tons.\n", minEmissions);
	printf("The maximum CO2 for the battery is: %.2f tons.\n", maxEmissions);
	printf("The average CO2 for the battery is: %.2f tons.\n\n", avgEmissions);
	printf("Computing the emissions of CO2 for the lifetime of the EV in tons.\n");
	printf("The total emissions to drive the EV 150000 km is: %.2f tons.\n\n", lifespanEmissions);
	printf("The End.\n");

	return 0;
}