#include "repo.h"
#include "utils.h"

/*
Description: functie de creare a unui repository

In: vect - vector dinamic

Out: repo - repository
*/
Repository createRepo(DynamicVect* vect) {
	Repository repo;
	repo.list = vect;
	return repo;
}

/*
Description: stocheaza un element in repo

In: 
	- repo - repository
	- elem - elementul de stocat
*/
void store(Repository repo, ElemType elem) {
	append(repo.list, elem);
}

//Description: returneaza numarul de elemente din repo
int getNumberOfElems(Repository repo) {
	return getSize(repo.list);
}

//Description: distruge repo(elibereaza memoria)
void destroyRepo(Repository repo) {
	destroyVector(repo.list);
}

//Description: returneaza un dynamic array cu toate elementele din repo
DynamicVect* getAll(Repository repo) {
	return repo.list;
}

//Description: returneaza un element din repo, avand indexul dat
//In: repo, index
//Out: elementul
ElemType getElem(Repository repo, int index) {
	return getElement(repo.list, index);
}

//Description: sterge un element din repo de la un index dat
void deleteElem(Repository repo, int index) {
	removeElement(repo.list, index);
}