#pragma once

#include "GeneralList.h"
#include "Taxi.h"

typedef struct {

	char*	name;
	LIST	taxiList;

}Importer;


void	freeElements(char** elements, int count);