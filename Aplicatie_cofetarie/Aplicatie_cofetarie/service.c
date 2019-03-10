#include "service.h"
#include "utils.h"
#include "domain.h"
#include <string.h>

int addIngredient(DynamicVect* v, char* name, char* manufacturer, float quantity) {
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
	int ok = -1;
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
	DynamicVect* resultV = createVector();
	for (int i = 0; i < v->size; i++) {
		if (getName(getElement(v, i))[0] == letter)
			append(resultV, getElement(v, i));
	}

	return resultV;
}

DynamicVect* quantityFilter(DynamicVect* v, float number) {
	DynamicVect* resultV = createVector();
	for (int i = 0; i < v->size; i++) {
		if (getQuantity(getElement(v, i)) < number)
			append(resultV, getElement(v, i));
	}

	return resultV;
}

void sortByName(DynamicVect* v) {
	for (int i = 0; i < v->size - 1; i++) {
		for (int j = i + 1; j < v->size; j++) {
			if (strcmp(getName(v->elems[i]), getName(v->elems[j])) > 0) {
				Ingredient* aux = v->elems[i];
				v->elems[i] = v->elems[j];
				v->elems[j] = aux;
			}
		}
	}
}

void sortByQuantity(DynamicVect* v) {
	for (int i = 0; i < v->size - 1; i++) {
		for (int j = i + 1; j < v->size; j++) {
			if (getQuantity(v->elems[i]) < getQuantity(v->elems[j])) {
				Ingredient* aux = v->elems[i];
				v->elems[i] = v->elems[j];
				v->elems[j] = aux;
			}
		}
	}
}