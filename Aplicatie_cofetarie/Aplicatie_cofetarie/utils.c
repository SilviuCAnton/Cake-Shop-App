#include "utils.h"
#include "domain.h"
#include <stdlib.h>
//Modulul utilitar al aplicatiei

/*
	Description: creeaza un vector dinamic

	In:
		- f - functia de distrugere a elementelor din vector
	Out:
		- v - pointer la vector
	*/
DynamicVect* createVector(DestroyFunction f) {
	
	DynamicVect* v = malloc(sizeof(DynamicVect));
	v->elems = malloc(sizeof(ElemType));
	v->size = 0;
	v->capacity = 1;
	v->destroy = f;
	return v;
}

/*
Description: sterge un element din vector

In:
	- v - pointer la vector
	- poz - pozitia elementului de sters
*/
void removeElement(DynamicVect* v, int poz) {

	if (poz != v->size - 1) {
		ElemType aux = v->elems[poz];
		v->elems[poz] = v->elems[v->size - 1];
		v->elems[v->size - 1] = aux;
	}

	v->destroy(v->elems[v->size - 1]);
	v->size -= 1;
}

/*
Description: elibereaza memoria ocupata de vector(distruge vectorul)

In:
	- v - pointer la vector
*/
void destroyVector(DynamicVect* v) {
	for (int i = 0; i < v->size; i++) {
		v->destroy(v->elems[i]);
	}
	free(v->elems);
	free(v);
}

/*
	Description: adauga un element la vector

	In:
		- v - pointer la vector
		- void* - pointer la element
	*/
void append(DynamicVect* v, ElemType elem) {
	
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->elems = realloc(v->elems, sizeof(ElemType) * v->capacity);
	}
	v->elems[v->size] = elem;
	v->size ++;
}

//Returneaza lungimea vectorului
int getSize(DynamicVect* v) {
	return v->size;
}

//Returneaza pointer-ul la elementul de pe pozitia poz
ElemType getElement(DynamicVect* v, int poz) {
	return v->elems[poz];
}