#include "TaxiCompany.h"

void freeCompany(taxiCompany* company)

{
	freeElements(company->driversArr,company->driversCount);
	generalArrayFunction(company->taxiArr, company->taxiCount, sizeof(Taxi), freeElements);
	generalArrayFunction(company->reviewsArr, company->reviewsCount, sizeof(Review), freeElements);
	generalArrayFunction(company->customerArr, company->customerCount, sizeof(Customer), freeElements);
	generalArrayFunction(company->tripReservationArr, company->tripReservationCount, sizeof(TripReservation), freeElements);
	free(company->name);
	free(company);


}

void	freeElements(Driver** elements, int count)
{
	for (int i = 0; i < count; i++)
		free(elements[i]);
	free(elements);
}
