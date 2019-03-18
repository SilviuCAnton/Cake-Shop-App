#include "service.h"
#include "repo.h"
#include "domain.h"
#include <string.h>
#include <stdlib.h>

//Modul pentru functionalitatile aplicatiei

Service* createService(Repository* repository) {
	Service* myService = malloc(sizeof(Service));
	myService->repo = repository;
	return myService;
}

int addIngredient(Service* service, char* name, char* manufacturer, float quantity) {
	int ok = 1;

	for (int i = 0; i < getNumberOfElems(service->repo); i++) {
		if (strcmp(getName(getElem(service->repo, i)), name) == 0) {
			setManufacturer(getElem(service->repo, i), manufacturer);
			setQuantity(getElem(service->repo, i), quantity);
			ok = 0;
			break;
		}
	}

	if (ok == 1) {
		Ingredient* ingredient = createIngredient(name, manufacturer, quantity);
		if (validate(ingredient))
			store(service->repo, ingredient);
		else {
			destroyIngredient(ingredient);
			ok = -1;
		}
	}

	return ok;
}

int modifyIngredient(Service* service, char* name, char* manufacturer, float quantity) {
	int ok = 0;

	Ingredient* ingredient = createIngredient(name, manufacturer, quantity);
	if (validate(ingredient))
		for (int i = 0; i < getNumberOfElems(service->repo); i++) {
			if (strcmp(getName(getElem(service->repo, i)), name) == 0) {
				setManufacturer(getElem(service->repo, i), manufacturer);
				setQuantity(getElem(service->repo, i), quantity);
				ok = 1;
				break;
			}
		}
	else {
		ok = -1;
	}

	destroyIngredient(ingredient);
	return ok;
}

int removeIngredient(Service* service, char* name) {
	int ok = 0;
	int poz = 0;

	for (int i = 0; i < getNumberOfElems(service->repo); i++) {
		if (strcmp(getName(getElem(service->repo, i)), name) == 0) {
			poz = i;
			ok = 1;
			break;
		}
	}

	if (ok == 1) {
		deleteElem(service->repo, poz);
	}
		
	return ok;
}

DynamicVect* nameFilter(Service* service, char letter) {
	DynamicVect* resultV = createVector(destroyIngredient);
	for (int i = 0; i < getNumberOfElems(service->repo); i++) {
		if (getName(getElem(service->repo, i))[0] == letter)
			append(resultV, getElem(service->repo, i));
	}

	return resultV;
}

DynamicVect* quantityFilter(Service* service, float number) {
	DynamicVect* resultV = createVector(destroyIngredient);
	for (int i = 0; i < getNumberOfElems(service->repo); i++) {
		if (getQuantity(getElem(service->repo, i)) < number)
			append(resultV, getElem(service->repo, i));
	}

	return resultV;
}

int cmpName(Ingredient* i1, Ingredient* i2 ) {
	return strcmp(getName(i1), getName(i2)) > 0;
}

int cmpQuantity(Ingredient* i1, Ingredient* i2) {
	return getQuantity(i2) > getQuantity(i1);
}

void sortByName(Service* service) {
	DynamicVect* vect = getAll(service->repo);
	sort(vect, cmpName);
}

void sortByQuantity(Service* service) {
	DynamicVect* vect = getAll(service->repo);
	sort(vect, cmpQuantity);
}