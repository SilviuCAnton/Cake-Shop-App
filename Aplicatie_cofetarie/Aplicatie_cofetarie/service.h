#pragma once
#include "utils.h"

int addIngredient(DynamicVect* v, char* name, char* manufacturer, float quantity);
int modifyIngredient(DynamicVect* v, char* name, char* manufacturer, float quantity);
int removeIngredient(DynamicVect* v, char* name);
DynamicVect* nameFilter(DynamicVect* v, char letter);
DynamicVect* quantityFilter(DynamicVect* v, float number);
void sortByName(DynamicVect* v);
void sortByQuantity(DynamicVect* v);