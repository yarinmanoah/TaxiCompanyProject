#pragma once

#include "General.h"

typedef struct {

	char*	name;
	char	id[ID_SIZE];
	char	phoneNumber[PHONE_NUMBER_SIZE];

}Customer;




void	freeElements(char** elements, int count);