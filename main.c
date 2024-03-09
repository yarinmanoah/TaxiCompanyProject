#include <stdio.h>
#include <stdlib.h>
#include "General.h"

typedef enum
{
	eAddDriver, eAddTaxi, eAddReview, eAddCustomer, eAddTripReservation, ePrintCompany, ePrintRides,
	eShifts, eSortDrivers, eSearchDriver, eCalculateIncome, eCalculateOutcome, eFindEmployeeOfTheMonth, eNofOptions
} eMenuOptions;

const char* str[eNofOptions] = { "Add Driver","Add Taxi","Add Review", "Add Customer", "Add Trip Reservation",
								"Print Taxi Company", "Print all Rides",
								"Print all Shifts of specific driver", "Sort Drivers", "Search Driver", "Calculate income",
								""};

#define EXIT			-1
#define MANAGER_FILE_NAME "airport_authority.txt"
#define COMPANY_FILE_NAME "airline.bin"

#define MANAGER_FILE_NAME_DST "airport_authority_out.txt"
#define AIRLINE_FILE_NAME_DST "airline_out.bin"

int menu();

int main()
{
	AirportManager	manager;
	Airline			company;

	if (!initManagerAndAirline(&manager, &company))
		printf("error loading Airline from file");
	printf("file loaded successfully");

	int option;
	int stop = 0;


	do
	{
		option = menu();
		switch (option)
		{
		case eAddPlane:
			if (!addPlane(&company))
				printf("Error adding plane\n");
			break;

		case eAddAirport:
			if (!addAirport(&manager))
				printf("Error adding airport\n");
			break;

		case eAddFlight:
			if (!addFlight(&company, &manager))
				printf("Error adding flight\n");
			break;

		case ePrintCompany:
			printCompany(&company);
			break;

		case ePrintAirports:
			printAirports(&manager);
			break;

		case ePrintFlightsPlaneType:
			doPrintFlightsWithPlaneType(&company);
			break;

		case eSortFlights:
			sortFlight(&company);
			break;

		case eSearchFlight:
			findFlight(&company);
			break;

		case EXIT:
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);

	saveManagerToFile(&manager, MANAGER_FILE_NAME);
	saveAirlineToFile(&company, COMPANY_FILE_NAME);

	freeManager(&manager);
	freeCompany(&company);

	system("pause");
	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptions; i++)
		printf("%d - %s\n", i, str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}

int initManagerAndAirline(AirportManager* pManager, Airline* pCompany)
{
	int res;
	res = initManager(pManager, MANAGER_FILE_NAME_DST);
	if (!res)
	{
		printf("error init manager\n");
		return 0;
	}
	if (res == 1)
		return initAirlineFromFile(pCompany, pManager, AIRLINE_FILE_NAME_DST);
	else
		initAirline(pCompany);

	return 1;
}