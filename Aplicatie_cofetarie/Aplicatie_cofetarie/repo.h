#pragma once
#include "utils.h"


typedef struct {
	DynamicVect* list;
}Repository;

Repository createRepo(DynamicVect* v);
void store(Repository repo, ElemType elem);
int getNumberOfElems(Repository repo);
void destroyRepo(Repository repo);
DynamicVect* getAll(Repository repo);
ElemType getElem(Repository repo, int index);
void deleteElem(Repository repo, int index);