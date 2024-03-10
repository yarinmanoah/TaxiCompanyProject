#pragma once

#include "General.h"
#include "Ride.h"
#include "Shift.h"
#include "Taxi.h"

typedef struct {

	char	id[ID_SIZE];
	char*	name;
	char	licenseNumber[LICENSE_NUMBER_SIZE];
	Taxi	taxi;
	int		ridesCount;
	int		shiftCount;
	Ride*	ridesArr;
	Shift*	shiftArr;
	int		availability; // 1 - true , 0 - false
	int		rating;

}Driver;


//void	freeElements(char** elements, int count);
void	freeElements(Driver* d1, int countShift, int countRides);//char** elements, int count)
