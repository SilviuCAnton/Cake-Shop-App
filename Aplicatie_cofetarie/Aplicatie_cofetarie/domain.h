#pragma once

//Modul pentru definirea entitatilor din aplicatie

typedef struct {
	char* name;
	char* manufacturer;
	float quantity;
}ingredient;

ingredient createIngredient(char* name, char* manufacturer, float quantity);
void repr(ingredient* ingr);
void getName(ingredient* ingr);
void setName(ingredient* ingr, char* name);
void getManufacturer(ingredient* ingr);
void setManufacturer(ingredient* ingr, char* manufacturer);
void getQuantity(ingredient* ingr);
void setQuantity(ingredient* ingr, float quantity);