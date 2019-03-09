#pragma once
#include "utils.h"

int addIngredient(DinamicVect* v, char* name, char* manufacturer, float quantity);
int modifyIngredient(DinamicVect* v, char* name, char* manufacturer, float quantity);
int removeIngredient(DinamicVect* v, char* name);