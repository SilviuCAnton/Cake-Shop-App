#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domain.h"

// Modulul pentru entitatile din aplicatie


/*
	Description: creeaza o materie prima

	In:
		- name - numele
		- manufacturer - producatorul
		- quantity - cantitatea

	Out:
		- ing - pointer la materia prima
*/
Ingredient* createIngredient(char* name, char* manufacturer, float quantity) {
	Ingredient* ing = malloc(sizeof(Ingredient));

	ing->name = (char*) malloc(strlen(name)+1);
	strcpy(ing->name, name);

	ing->manufacturer = (char*) malloc(strlen(manufacturer)+1);
	strcpy(ing->manufacturer, manufacturer);

	ing->quantity = quantity;

	return ing;
}

//returneaza numele materiei prime
char* getName(Ingredient* ingr) {
	return ingr->name;
}

//seteaza numele materiei prime
void setName(Ingredient* ingr, char* name) {
	free(ingr->name);
	ingr->name = (char*) malloc(strlen(name) + 1);
	strcpy(ingr->name, name);
}

//returneaza producatorul materiei prime
char* getManufacturer(Ingredient* ingr) {
	return ingr->manufacturer;
}

//seteaza producatorul materiei prime
void setManufacturer(Ingredient* ingr, char* manufacturer) {
	free(ingr->manufacturer);
	ingr->manufacturer = (char*) malloc(strlen(manufacturer) + 1);
	strcpy(ingr->manufacturer, manufacturer);
}

//returneaza cantitatea materiei prime
float getQuantity(Ingredient* ingr) {
	return ingr->quantity;
}

//seteaza cantitatea materiei prime
void setQuantity(Ingredient* ingr, float quantity) {
	ingr->quantity = quantity;
}

//Elibereaza memoria unei materii prime(distruge materia prima)
void destroyIngredient(Ingredient* ingr) {
	free(getName(ingr));
	free(getManufacturer(ingr));
	free(ingr);
}

//Valideaza o materie prima
int validate(Ingredient *ingr) {
	if (ingr->quantity <= 0)
		return 0;
	if (strlen(ingr->name) < 1 || strlen(ingr->manufacturer) <= 1)
		return 0;
	if ((ingr->name[0] >= 48 && ingr->name[0] <= 64) || (ingr->manufacturer[0] >= 48 && ingr->manufacturer[0] <= 64))
		return 0;
	return 1;
}