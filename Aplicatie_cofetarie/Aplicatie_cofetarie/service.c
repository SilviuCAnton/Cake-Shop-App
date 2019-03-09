#include "service.h"
#include "utils.h"
#include "domain.h"
#include <string.h>

int addIngredient(DinamicVect* v, char* name, char* manufacturer, float quantity) {
	int ok = 1;

	for (int i = 0; i < getSize(v); i++) {
		if (strcmp(getName(&(v->elems[i])), name) == 0) {
			setManufacturer(&(v->elems[i]), manufacturer);
			setQuantity(&(v->elems[i]), quantity);
			ok = 0;
			break;
		}
	}

	if (ok == 1) {
		Ingredient ingredient = createIngredient(name, manufacturer, quantity);
		append(v, ingredient);
	}

	return ok;
}

int modifyIngredient(DinamicVect* v, char* name, char* manufacturer, float quantity) {
	int ok = 0;

	for (int i = 0; i < getSize(v); i++) {
		if (strcmp(getName(&(v->elems[i])), name) == 0) {
			setManufacturer(&(v->elems[i]), manufacturer);
			setQuantity(&(v->elems[i]), quantity);
			ok = 1;
			break;
		}		
	}

	return ok;
}

int removeIngredient(DinamicVect* v, char* name) {
	int ok = 0;
	int poz = 0;

	for (int i = 0; i < getSize(v); i++) {
		if (strcmp(getName(&(v->elems[i])), name) == 0) {
			poz = i;
			ok = 1;
			break;
		}
	}

	if (ok == 1) {
		for (int i = poz; i < getSize(v) - 1; i++) {
			v->elems[i] = v->elems[i + 1];
		}
		decSize(v);
	}
		
	return ok;
}