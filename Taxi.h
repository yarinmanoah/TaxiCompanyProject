#pragma once

#include "General.h"
#include "Driver.h"


typedef enum { ePrivateCar, eMinibus, eNofOpt } eOption;
static const char* OptStr[eNofOpt];

typedef struct {

	char		carNumber[CAR_NUMBER_SIZE];
	eOption		Opt;
	Driver		driver;
}Taxi;
