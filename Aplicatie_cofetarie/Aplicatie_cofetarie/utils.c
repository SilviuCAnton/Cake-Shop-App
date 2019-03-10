#include "utils.h"
#include "domain.h"
#include <stdlib.h>
//Modulul utilitar al aplicatiei

DynamicVect* createVector() {
	/*
	Description: creeaza un vector dinamic

	Out:
		- v - pointer la vector
	*/
	DynamicVect* v = malloc(sizeof(DynamicVect));
	v->elems = malloc(sizeof(void*));
	v->size = 0;
	v->capacity = 1;
	return v;
}

void removeElement(DynamicVect* v, int poz) {
	/*
	Description: sterge un element din vector

	In:
		- v - pointer la vector
		- poz - pozitia elementului de sters
	*/
	if (poz != v->size - 1) {
		void* aux = v->elems[poz];
		v->elems[poz] = v->elems[v->size - 1];
		v->elems[v->size - 1] = aux;
	}

	destroy(v->elems[v->size - 1]);
	v->size -= 1;
}

void destroyVector(DynamicVect* v) {
	/*
	Description: elibereaza memoria ocupata de vector(distruge vectorul)

	In:
		- v - pointer la vector
	*/
	for (int i = 0; i < v->size; i++) {
		destroy(v->elems[i]);
	}
	free(v->elems);
	free(v);
}

void append(DynamicVect* v, void* elem) {
	/*
	Description: adauga un element la vector

	In:
		- v - pointer la vector
		- void* - pointer la element
	*/
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->elems = realloc(v->elems, sizeof(void*) * v->capacity);
	}
	v->elems[v->size] = elem;
	v->size ++;
}

int getSize(DynamicVect* v) {
	//Returneaza lungimea vectorului
	return v->size;
}

void* getElement(DynamicVect* v, int poz) {
	//Returneaza pointer-ul la elementul de pe pozitia poz
	return v->elems[poz];
}