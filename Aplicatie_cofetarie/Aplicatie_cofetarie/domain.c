#include <stdio.h>
#include "domain.h"

ingredient createIngredient(char* name, char* manufacturer, float quantity) {
	ingredient ing;
	ing.name = name;
	ing.manufacturer = manufacturer;
	ing.quantity = quantity;
	return ing;
}

void repr(ingredient* ingr) {
	printf("%s - manufacturer: %s, quant: %f", ingr->name, ingr->manufacturer, ingr->quantity);
}

void getName(ingredient* ingr) {
	return ingr->name;
}

void setName(ingredient* ingr, char* name) {
	ingr->name = name;
}

void getManufacturer(ingredient* ingr) {
	return ingr->manufacturer;
}

void setManufacturer(ingredient* ingr, char* manufacturer) {
	ingr->manufacturer = manufacturer;
}

void getQuantity(ingredient* ingr) {
	return ingr->quantity;
}

void setQuantity(ingredient* ingr, float quantity) {
	ingr->quantity = quantity;
}
