#pragma once

typedef enum { eCredit, eCash, eNofOpt } eOption;
static const char* OptStr[eNofOpt];

typedef struct {

	eOption		Opt;
	int		price;
}Payment;
