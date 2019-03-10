#include "service.h"
#include "utils.h"
#include "domain.h"
#include <string.h>

int addIngredient(DynamicVect* v, char* name, char* manufacturer, float quantity) {
	/*
	Description: adauga o materie prima intr-o lista

	In:
		- v - lista de materii prime
		- name - numele materiei prime
		- manufacturer - numele producatorului
		- quantity - cantitatea

	Out:
		- ok - 0 daca materia prima este exista si 1 in caz contrar
	*/
	int ok = 1;

	for (int i = 0; i < getSize(v); i++) {
		if (strcmp(getName(getElement(v, i)), name) == 0) {
			setManufacturer(getElement(v, i), manufacturer);
			setQuantity(getElement(v, i), quantity);
			ok = 0;
			break;
		}
	}

	if (ok == 1) {
		Ingredient* ingredient = createIngredient(name, manufacturer, quantity);
		append(v, ingredient);
	}

	return ok;
}

int modifyIngredient(DynamicVect* v, char* name, char* manufacturer, float quantity) {
	/*
	Description: modifica o materie prima din lista

	In:
		- v - lista de materii prime
		- name - numele materiei prime
		- manufacturer - numele producatorului
		- quantity - cantitatea

	Out:
		- ok - 0 daca materia prima este inexistenta si 1 in caz contrar
	*/
	int ok = 0;

	for (int i = 0; i < getSize(v); i++) {
		if (strcmp(getName(getElement(v, i)), name) == 0) {
			setManufacturer(getElement(v, i), manufacturer);
			setQuantity(getElement(v, i), quantity);
			ok = 1;
			break;
		}		
	}

	return ok;
}

int removeIngredient(DynamicVect* v, char* name) {
	/*
	Description: sterge o materie prima din lista

	In:
		- v - lista de materii prime
		- name - numele materiei prime

	Out:
		- ok - 0 daca materia prima este inexistenta si 1 in caz contrar
	*/
	int ok = 0;
	int poz = 0;

	for (int i = 0; i < getSize(v); i++) {
		if (strcmp(getName(getElement(v, i)), name) == 0) {
			poz = i;
			ok = 1;
			break;
		}
	}

	if (ok == 1) {
		removeElement(v, poz);
	}
		
	return ok;
}

DynamicVect* nameFilter(DynamicVect* v, char letter) {
	/*
	Description: filtreaza materiile prime dupa nume (numele care incep cu o litera data)

	In:
		- v - lista de materii prime
		- letter - litera pentru filtrare
	*/
	DynamicVect* resultV = createVector();
	for (int i = 0; i < getSize(v); i++) {
		if (getName(getElement(v, i))[0] == letter)
			append(resultV, getElement(v, i));
	}

	return resultV;
}

DynamicVect* quantityFilter(DynamicVect* v, float number) {
	/*
	Description: filtreaza materiile prime dupa cantitate (au cantitatea mai mica decat cea data)

	In:
		- v - lista de materii prime
		- number - cantitatea pentru filtrare
	*/
	DynamicVect* resultV = createVector();
	for (int i = 0; i < getSize(v); i++) {
		if (getQuantity(getElement(v, i)) < number)
			append(resultV, getElement(v, i));
	}

	return resultV;
}

void sortByName(DynamicVect* v) {
	/*
	Description: sorteaza materiile prime crescator dupa nume

	In:
		- v - lista de materii prime
	*/
	for (int i = 0; i < getSize(v) - 1; i++) {
		for (int j = i + 1; j < getSize(v); j++) {
			if (strcmp(getName(v->elems[i]), getName(v->elems[j])) > 0) {
				Ingredient* aux = v->elems[i];
				v->elems[i] = v->elems[j];
				v->elems[j] = aux;
			}
		}
	}
}

void sortByQuantity(DynamicVect* v) {
	/*
	Description: sorteaza materiile prime descrescator dupa cantitate

	In:
		- v - lista de materii prime
	*/
	for (int i = 0; i < getSize(v) - 1; i++) {
		for (int j = i + 1; j < getSize(v); j++) {
			if (getQuantity(v->elems[i]) < getQuantity(v->elems[j])) {
				Ingredient* aux = v->elems[i];
				v->elems[i] = v->elems[j];
				v->elems[j] = aux;
			}
		}
	}
}