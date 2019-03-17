#include "repo.h"
#include "utils.h"

Repository createRepo(DynamicVect* v) {
	Repository repo;
	repo.list = v;
	return repo;
}

void store(Repository repo, ElemType elem) {
	append(repo.list, elem);
}

int getNumberOfElems(Repository repo) {
	return getSize(repo.list);
}

void destroyRepo(Repository repo) {
	destroyVector(repo.list);
}

DynamicVect* getAll(Repository repo) {
	return repo.list;
}

ElemType getElem(Repository repo, int index) {
	return getElement(repo.list, index);
}

void deleteElem(Repository repo, int index) {
	removeElement(repo.list, index);
}