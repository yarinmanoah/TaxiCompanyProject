#pragma once

typedef struct
{
	int		num;
	char*	street;
	char*	city;
}Address;

int		initAddress(Address* pAd);
int		checkElements(char** elements, int count);
char*	fixAddressParam(char* param);
void	freeElements(char** elements, int count);