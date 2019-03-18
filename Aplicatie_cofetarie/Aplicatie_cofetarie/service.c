#include "service.h"
#include "repo.h"
#include "domain.h"
#include <string.h>

//Modul pentru functionalitatile aplicatiei

/*
Description: adauga o materie prima intr-o lista

In:
	- repo - repository de materii prime
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
		if (validate(ingredient))
			store(repo, ingredient);
		else {
			destroyIngredient(ingredient);
			ok = -1;
		}
	}

	return ok;
}

/*
Description: modifica o materie prima din lista

In:
	- repo - repository de materii prime
	- name - numele materiei prime
	- manufacturer - numele producatorului
	- quantity - cantitatea

Out:
	- ok - 0 daca materia prima este inexistenta si 1 in caz contrar
*/
int modifyIngredient(Repository repo, char* name, char* manufacturer, float quantity) {
	int ok = 0;

	Ingredient* ingredient = createIngredient(name, manufacturer, quantity);
	if (validate(ingredient))
		for (int i = 0; i < getNumberOfElems(repo); i++) {
			if (strcmp(getName(getElem(repo, i)), name) == 0) {
				setManufacturer(getElem(repo, i), manufacturer);
				setQuantity(getElem(repo, i), quantity);
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


/*
Description: sterge o materie prima din lista

In:
	- repo - repository de materii prime
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
	- repo - repository de materii prime
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
	- repo - repository de materii prime
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

int cmpName(Ingredient* i1, Ingredient* i2 ) {
	return strcmp(getName(i1), getName(i2)) > 0;
}

int cmpQuantity(Ingredient* i1, Ingredient* i2) {
	return getQuantity(i2) - getQuantity(i1);
}

/*
Description: sorteaza materiile prime

In:
	- repo - repository de materii prime
	- cmpFct - functie de comparare
*/
void sort(DynamicVect* vect, int(*cmpFct)(ElemType e1, ElemType e2)) {
	for (int i = 0; i < getSize(vect) - 1; i++) {
		for (int j = i + 1; j < getSize(vect); j++) {
			ElemType el1 = getElement(vect, i);
			ElemType el2 = getElement(vect, j);
			if (cmpFct(el1, el2)) {
				setElement(vect, i, el2);
				setElement(vect, j, el1);
			}
		}
	}
}

/*
Description: sorteaza materiile prime crescator dupa nume

In:
	- repo - repository de materii prime
*/
void sortByName(Repository repo) {
	DynamicVect* vect = getAll(repo);
	sort(vect, cmpName);
}

/*
Description: sorteaza materiile prime descrescator dupa cantitate

In:
	- repo - repository de materii prime
*/
void sortByQuantity(Repository repo) {
	DynamicVect* vect = getAll(repo);
	sort(vect, cmpQuantity);
}