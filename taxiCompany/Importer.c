#include "GeneralList.h"
#include "Taxi.h"
#include "Importer.h"


void	freeElements(Importer* importer){//char** elements, int count) {

	free(importer->name);
	free(importer);

}