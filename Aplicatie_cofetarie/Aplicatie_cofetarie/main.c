//Modulul principal al aplicatiei
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "repo.h"
#include "ui.h"
#include "tests.h"

int main() {
	Repository myRepo = createRepo(createVector(destroyIngredient));
	testFunctions();
	run(myRepo);
	destroyRepo(myRepo);
	_CrtDumpMemoryLeaks();
	return 0;
}