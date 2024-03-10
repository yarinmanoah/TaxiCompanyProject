#pragma once

#include "Customer.h"
#include "Address.h"
#include "Payment.h"
#include "Driver.h"

typedef struct {

	Driver		driver;
	Customer	customer;
	Address		originAddress;
	Address		destAddress;
	Payment		payment;
	int			numberOfPassengers;
	int			rideTime;

}Ride;
