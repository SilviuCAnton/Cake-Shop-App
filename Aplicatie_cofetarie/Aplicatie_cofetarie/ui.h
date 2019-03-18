#pragma once
#include "utils.h"
#include "repo.h"

//Modulul pentru interactiunea cu utilizatorul

void run(Repository myRepo);
void addIngredientUI(Repository repo);
void removeIngredientUI(Repository repo);
void displayMenu();
void nameFilterUI(Repository repo);
void quantityFilterUI(Repository repo);
void sortByNameUI(Repository repo);
void sortByQuantityUI(Repository repo);