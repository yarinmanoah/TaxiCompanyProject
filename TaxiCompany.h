#pragma once

#include "Address.h"
#include "Driver.h"
#include "Taxi.h"
#include "Review.h"
#include "TripReservation.h"
#include "Customer.h"

typedef struct {

	char*		name;
	Address		address;
	int			taxiCount;
	int			driversCount;
	int			reviewsCount;
	int			customerCount;
	int			tripReservationCount;
	Driver**	driversArr;
	Taxi*		taxiArr;
	Review*		reviewsArr;
	Customer*	customerArr;
	TripReservation*	tripReservationArr;
}taxiCompany;