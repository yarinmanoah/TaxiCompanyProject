#include "General.h"
#include "Ride.h"
#include "Shift.h"
#include "Taxi.h"
#include "Driver.h"


void	freeElements(Driver* d1,int countShift, int countRides){//char** elements, int count)

	for (int i = 0; i < countShift; i++) {
		free(d1->shiftArr[i]);
	}
	free(d1->shiftArr);
	for (int i = 0; i < countRides; i++) {
		free(d1->ridesArr[i]);
	}
	free(d1->ridesArr);
	free(d1->name);
	free(d1);
}

