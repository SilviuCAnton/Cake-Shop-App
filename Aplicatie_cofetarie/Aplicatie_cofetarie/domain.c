#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domain.h"

Ingredient* createIngredient(char* name, char* manufacturer, float quantity) {
	Ingredient* ing = malloc(sizeof(Ingredient));

	ing->name = (char*) malloc(strlen(name)+1);
	strcpy(ing->name, name);

	ing->manufacturer = (char*) malloc(strlen(manufacturer)+1);
	strcpy(ing->manufacturer, manufacturer);

	ing->quantity = quantity;

	return ing;
}

void repr(Ingredient* ingr) {
	printf("%s - manufacturer: %s, quant: %f", ingr->name, ingr->manufacturer, ingr->quantity);
}

char* getName(Ingredient* ingr) {
	return ingr->name;
}

void setName(Ingredient* ingr, char* name) {
	free(ingr->name);
	ingr->name = (char*) malloc(strlen(name) + 1);
	strcpy(ingr->name, name);
}

char* getManufacturer(Ingredient* ingr) {
	return ingr->manufacturer;
}

void setManufacturer(Ingredient* ingr, char* manufacturer) {
	free(ingr->manufacturer);
	ingr->manufacturer = (char*) malloc(strlen(manufacturer) + 1);
	strcpy(ingr->manufacturer, manufacturer);
}

float getQuantity(Ingredient* ingr) {
	return ingr->quantity;
}

void setQuantity(Ingredient* ingr, float quantity) {
	ingr->quantity = quantity;
}

void destroyIngredient(Ingredient* ingr) {
	free(getName(ingr));
	free(getManufacturer(ingr));
}
