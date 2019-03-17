#include "service.h"
#include "repo.h"
#include "domain.h"
#include <string.h>

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
int addIngredient(Repository repo, char* name, char* manufacturer, float quantity) {
	int ok = 1;

	for (int i = 0; i < getNumberOfElems(repo); i++) {
		if (strcmp(getName(getElem(repo, i)), name) == 0) {
			setManufacturer(getElem(repo, i), manufacturer);
			setQuantity(getElem(repo, i), quantity);
			ok = 0;
			break;
		}
	}

	if (ok == 1) {
		Ingredient* ingredient = createIngredient(name, manufacturer, quantity);
		store(repo, ingredient);
	}

	return ok;
}

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
int modifyIngredient(Repository repo, char* name, char* manufacturer, float quantity) {
	int ok = 0;

	for (int i = 0; i < getNumberOfElems(repo); i++) {
		if (strcmp(getName(getElem(repo, i)), name) == 0) {
			setManufacturer(getElem(repo, i), manufacturer);
			setQuantity(getElem(repo, i), quantity);
			ok = 1;
			break;
		}		
	}

	return ok;
}


/*
Description: sterge o materie prima din lista

In:
	- v - lista de materii prime
	- name - numele materiei prime

Out:
	- ok - 0 daca materia prima este inexistenta si 1 in caz contrar
*/
int removeIngredient(Repository repo, char* name) {
	int ok = 0;
	int poz = 0;

	for (int i = 0; i < getNumberOfElems(repo); i++) {
		if (strcmp(getName(getElem(repo, i)), name) == 0) {
			poz = i;
			ok = 1;
			break;
		}
	}

	if (ok == 1) {
		deleteElem(repo, poz);
	}
		
	return ok;
}


/*
Description: filtreaza materiile prime dupa nume (numele care incep cu o litera data)

In:
	- v - lista de materii prime
	- letter - litera pentru filtrare
*/
DynamicVect* nameFilter(Repository repo, char letter) {
	DynamicVect* resultV = createVector(destroyIngredient);
	for (int i = 0; i < getNumberOfElems(repo); i++) {
		if (getName(getElem(repo, i))[0] == letter)
			append(resultV, getElem(repo, i));
	}

	return resultV;
}

/*
Description: filtreaza materiile prime dupa cantitate (au cantitatea mai mica decat cea data)

In:
	- v - lista de materii prime
	- number - cantitatea pentru filtrare
*/
DynamicVect* quantityFilter(Repository repo, float number) {
	DynamicVect* resultV = createVector(destroyIngredient);
	for (int i = 0; i < getNumberOfElems(repo); i++) {
		if (getQuantity(getElem(repo, i)) < number)
			append(resultV, getElem(repo, i));
	}

	return resultV;
}

/*
Description: sorteaza materiile prime crescator dupa nume

In:
	- v - lista de materii prime
*/
void sortByName(Repository repo) {
	DynamicVect* v = getAll(repo);
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

/*
Description: sorteaza materiile prime descrescator dupa cantitate

In:
	- v - lista de materii prime
*/
void sortByQuantity(Repository repo) {
	DynamicVect* v = getAll(repo);
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