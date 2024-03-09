#pragma once

#include "Customer.h"
#include "Address.h"
#include "Date.h"
#include "Payment.h"
#include "Driver.h"

typedef struct {

	Customer	customer;
	Driver		driver;
	Address		originAddress;
	Address		destAddress;
	Date		date;
	int			numOfPassenger;
	Payment		payment;
	int			 time;


}TripReservation;
