#include "tests.h"
#include "service.h"
#include "domain.h"
#include "utils.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//Modul pentru teste

void testEntity() {
	Ingredient* ing = createIngredient("Halo", "ffff", 40);
	assert(strcmp(getName(ing), "Halo") == 0);
	assert(strcmp(getManufacturer(ing), "ffff") == 0);
	assert(getQuantity(ing) == 40);
	setName(ing, "DA");
	setManufacturer(ing, "NU");
	setQuantity(ing, 2.5);
	assert(strcmp(getName(ing), "DA") == 0);
	assert(strcmp(getManufacturer(ing), "NU") == 0);
	assert(getQuantity(ing) == 2.5);
	destroy(ing);

	printf("ENTITIES OK \n");
}

void testDynamicVect() {
		
	DynamicVect* v = createVector();

	Ingredient* x = createIngredient("da", "da", 15);
	Ingredient* y = createIngredient("nu", "nu", 10);

	append(v, x);
	append(v, y);
	assert(getSize(v) == 2);

	int* g = getElement(v, 1);
	assert(getQuantity(g) == 10);

	removeElement(v, 0);
	assert(getSize(v) == 1);

	destroyVector(v);

	printf("UTILITIES OK \n");
}

void testService() {
	DynamicVect* repo = createVector();

	addIngredient(repo, "DA", "DA", 33.6);
	addIngredient(repo, "AU", "NU", 40);
	addIngredient(repo, "DA", "da", 45);
	assert(strcmp(getManufacturer(getElement(repo, 0)), "da") == 0);

	modifyIngredient(repo, "AU", "ai", 20);
	assert(getQuantity(getElement(repo, 1)) == 20);

	DynamicVect* resultFilter1 = nameFilter(repo, 'A');
	assert(getSize(resultFilter1) == 1);
	free(resultFilter1->elems);
	free(resultFilter1);

	DynamicVect* resultFilter2 = quantityFilter(repo, 25);
	assert(getSize(resultFilter2) == 1);
	free(resultFilter2->elems);
	free(resultFilter2);

	sortByName(repo);
	assert(getName(getElement(repo, 0))[0] == 'A');

	sortByQuantity(repo);
	assert(getQuantity(getElement(repo, 0)) == 45);

	removeIngredient(repo, "AU");
	assert(getSize(repo) == 1);

	destroyVector(repo);

	printf("SERVICE OK \n");
}

void testFunctions() {
	testEntity();
	testDynamicVect();
	testService();
}