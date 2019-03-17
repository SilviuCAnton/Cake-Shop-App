#include "tests.h"
#include "service.h"
#include "domain.h"
#include "utils.h"
#include "repo.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
	destroyIngredient(ing);

	printf("ENTITIES OK \n");
}

void testValidator() {
	Ingredient* ing1 = createIngredient("Halo", "ffff", -1);
	Ingredient* ing2 = createIngredient("5Halo", "ffff", 24);
	Ingredient* ing3 = createIngredient("Halo", "3ffff", 130);
	Ingredient* ing4 = createIngredient("Halo", "ffff", 12);
	assert(validate(ing1) == 0);
	assert(validate(ing2) == 0);
	assert(validate(ing3) == 0);
	assert(validate(ing4) == 1);
	destroyIngredient(ing1);
	destroyIngredient(ing2);
	destroyIngredient(ing3);
	destroyIngredient(ing4);
}

void testDynamicVect() {
		
	DynamicVect* v = createVector(destroyIngredient);

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
	Repository repo = createRepo(createVector(destroyIngredient));

	addIngredient(repo, "DA", "DA", 33.6);
	addIngredient(repo, "AU", "NU", 40);
	addIngredient(repo, "DA", "da", 45);
	assert(addIngredient(repo, "1A", "sdfa", 34) == -1);
	assert(strcmp(getManufacturer(getElem(repo, 0)), "da") == 0);

	modifyIngredient(repo, "AU", "ai", 20);
	assert(modifyIngredient(repo, "AU", "ai", -21) == -1);
	assert(getQuantity(getElem(repo, 1)) == 20);

	DynamicVect* resultFilter1 = nameFilter(repo, 'A');
	assert(getSize(resultFilter1) == 1);
	free(resultFilter1->elems);
	free(resultFilter1);

	DynamicVect* resultFilter2 = quantityFilter(repo, 25);
	assert(getSize(resultFilter2) == 1);
	free(resultFilter2->elems);
	free(resultFilter2);

	sortByName(repo);
	assert(getName(getElem(repo, 0))[0] == 'A');

	sortByQuantity(repo);
	assert(getQuantity(getElem(repo, 0)) == 45);

	removeIngredient(repo, "AU");
	assert(getNumberOfElems(repo) == 1);

	destroyRepo(repo);

	printf("SERVICE OK \n");
}

void testFunctions() {
	testEntity();
	testValidator();
	testDynamicVect();
	testService();
}