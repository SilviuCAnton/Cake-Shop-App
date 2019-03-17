#pragma once
#include "utils.h"
#include "repo.h"

int addIngredient(Repository repo, char* name, char* manufacturer, float quantity);
int modifyIngredient(Repository repo, char* name, char* manufacturer, float quantity);
int removeIngredient(Repository repo, char* name);
DynamicVect* nameFilter(Repository repo, char letter);
DynamicVect* quantityFilter(Repository repo, float number);
void sortByName(Repository repo);
void sortByQuantity(Repository repo);