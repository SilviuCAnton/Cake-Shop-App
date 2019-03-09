#pragma once

//Modul pentru definirea entitatilor din aplicatie

typedef struct {
	char* name;
	char* manufacturer;
	float quantity;
}Ingredient;

Ingredient createIngredient(char* name, char* manufacturer, float quantity);
void repr(Ingredient* ingr);
char* getName(Ingredient* ingr);
void setName(Ingredient* ingr, char* name);
char* getManufacturer(Ingredient* ingr);
void setManufacturer(Ingredient* ingr, char* manufacturer);
float getQuantity(Ingredient* ingr);
void setQuantity(Ingredient* ingr, float quantity);