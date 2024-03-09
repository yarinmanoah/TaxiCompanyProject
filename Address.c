#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Address.h"
#include "General.h"

int		initAddress(Address* pAd)
{
	char allData[MAX_STR_LEN];
	char** elements = NULL;
	int count;
	int ok = 1;
	int totalLength;
	char msg[MAX_STR_LEN];
	sprintf(msg, "Enter address data\nFormat: street%shouse number%scity\nstreet and city can have spaces\n",
		"#", "#");
	do {

		getsStrFixSize(allData, sizeof(allData), msg);
		int countSep = countCharInString(allData, "#");
		if (countSep > 2)
		{
			printf("Wrong address format\n");
			ok = 0;
		}
		else {
			elements = splitCharsToWords(allData, &count, "#", &totalLength);
			if (!elements)
				continue;
			ok = checkElements(elements, count);
			if (!ok)
			{
				printf("Wrong address format\n");
				freeElements(elements, count);
			}
		}
	} while (!ok);

	//get the house number
	sscanf(elements[1], "%d", &pAd->num);
	pAd->street = fixAddressParam(elements[0]);
	if (!pAd->street)
	{
		freeElements(elements, count);
		return 0;
	}

	pAd->city = fixAddressParam(elements[2]);
	if (!pAd->city)
	{
		free(pAd->street);
		freeElements(elements, count);
		return 0;
	}

	freeElements(elements, count);
	return 1;
}

int		checkElements(char** elements, int count)
{
	if (count != 3)
		return 0;
	//check second word is a number;
	char* streetNum = elements[1];
	while (*streetNum)
	{
		if (!isdigit(*streetNum))
			return 0;
		streetNum++;
	}

	if (checkEmptyString(elements[0]))
		return 0;
	if (checkEmptyString(elements[2]))
		return 0;

	return 1;
}

char* fixAddressParam(char* param)
{
	char* fixParamStr;
	char** wordsArray = NULL;
	int totalLength;
	int count;

	wordsArray = splitCharsToWords(param, &count, " ", &totalLength);
	if (!wordsArray)
		return NULL;
	//add size for the WORD_SEP between words and for '\0'
	size_t length = (count - 1) * strlen("  ") + 1;
	fixParamStr = (char*)calloc(totalLength + length, sizeof(char));
	if (!fixParamStr)
	{
		freeElements(wordsArray, count);
		return NULL;
	}

	if (count == 1)
		wordsArray[0][0] = toupper(wordsArray[0][0]); //upper
	else {
		for (int i = 0; i < count - 1; i++)
		{
			wordsArray[i][0] = toupper(wordsArray[i][0]); //upper
		}
		wordsArray[count - 1][0] = tolower(wordsArray[count - 1][0]); //lower
	}
	for (int i = 0; i < count - 1; i++)
	{
		strcat(fixParamStr, wordsArray[i]);
		strcat(fixParamStr, "#");
	}
	strcat(fixParamStr, wordsArray[count - 1]);

	freeElements(wordsArray, count);
	return fixParamStr;
}

void	freeElements(char** elements, int count)
{
	for (int i = 0; i < count; i++)
		free(elements[i]);
	free(elements);
}