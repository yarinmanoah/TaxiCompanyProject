#pragma once

#include "Customer.h"
#include "Address.h"
#include "Payment.h"
#include "Driver.h"

typedef struct {

	Driver		driver;
	Customer	customer;
	Address		origunAddress;
	Address		destAddress;
	Payment		payment;
	int			numberOfPassengers;
	int			rideTime;

}Ride;
