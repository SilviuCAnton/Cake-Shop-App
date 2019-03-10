#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domain.h"

// Modulul pentru entitatile din aplicatie

Ingredient* createIngredient(char* name, char* manufacturer, float quantity) {
	/*
	Description: creeaza o materie prima

	In:
		- name - numele
		- manufacturer - producatorul
		- quantity - cantitatea

	Out:
		- ing - pointer la materia prima
	*/
	Ingredient* ing = malloc(sizeof(Ingredient));

	ing->name = (char*) malloc(strlen(name)+1);
	strcpy(ing->name, name);

	ing->manufacturer = (char*) malloc(strlen(manufacturer)+1);
	strcpy(ing->manufacturer, manufacturer);

	ing->quantity = quantity;

	return ing;
}

char* getName(Ingredient* ingr) {
	//returneaza numele materiei prime
	return ingr->name;
}

void setName(Ingredient* ingr, char* name) {
	//seteaza numele materiei prime
	free(ingr->name);
	ingr->name = (char*) malloc(strlen(name) + 1);
	strcpy(ingr->name, name);
}

char* getManufacturer(Ingredient* ingr) {
	//returneaza producatorul materiei prime
	return ingr->manufacturer;
}

void setManufacturer(Ingredient* ingr, char* manufacturer) {
	//seteaza producatorul materiei prime
	free(ingr->manufacturer);
	ingr->manufacturer = (char*) malloc(strlen(manufacturer) + 1);
	strcpy(ingr->manufacturer, manufacturer);
}

float getQuantity(Ingredient* ingr) {
	//returneaza cantitatea materiei prime
	return ingr->quantity;
}

void setQuantity(Ingredient* ingr, float quantity) {
	//seteaza cantitatea materiei prime
	ingr->quantity = quantity;
}

void destroyIngredient(Ingredient* ingr) {
	//Elibereaza memoria unei materii prime(distruge materia prima)
	free(getName(ingr));
	free(getManufacturer(ingr));
}
