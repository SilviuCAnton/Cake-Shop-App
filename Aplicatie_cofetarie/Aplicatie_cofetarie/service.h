#pragma once
#include "utils.h"

int addIngredient(DynamicVect* v, char* name, char* manufacturer, float quantity);
int modifyIngredient(DynamicVect* v, char* name, char* manufacturer, float quantity);
int removeIngredient(DynamicVect* v, char* name);