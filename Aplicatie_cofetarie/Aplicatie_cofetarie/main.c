//Modulul principal al aplicatiei
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "ui.h"
#include "tests.h"

int main() {
	testFunctions();
	run();
	_CrtDumpMemoryLeaks();
	return 0;
}