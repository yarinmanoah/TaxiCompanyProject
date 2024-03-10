#pragma once

#include "General.h"
#include "Driver.h"


typedef enum { ePrivateCar, eMinibus, eNofOpt } eType;
static const char* OptStr[eNofOpt];

typedef struct {

	char		carNumber[CAR_NUMBER_SIZE];
	eType		Type;
	Driver		driver;
}Taxi;
