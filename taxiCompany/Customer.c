#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Customer.h"
#include "General.h"












void	freeElements(Customer* c1)//char** elements, int count)
{
	//for (int i = 0; i < count; i++)
		//free(elements[i]);
	free(c1->id);
	free(c1);
	//free(elements);
}