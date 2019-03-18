#include "utils.h"
#include "domain.h"
#include <stdlib.h>
//Modulul utilitar al aplicatiei

/*
	Description: creeaza un vector dinamic

	In:
		- f - functia de distrugere a elementelor din vector
	Out:
		- vect - pointer la vector
	*/
DynamicVect* createVector(DestroyFunction f) {
	
	DynamicVect* vect = malloc(sizeof(DynamicVect));
	vect->elems = malloc(sizeof(ElemType));
	vect->size = 0;
	vect->capacity = 1;
	vect->destroy = f;
	return vect;
}

/*
Description: sterge un element din vector

In:
	- vect - pointer la vector
	- poz - pozitia elementului de sters
*/
void removeElement(DynamicVect* vect, int poz) {

	if (poz != vect->size - 1) {
		ElemType aux = vect->elems[poz];
		vect->elems[poz] = vect->elems[vect->size - 1];
		vect->elems[vect->size - 1] = aux;
	}

	vect->destroy(vect->elems[vect->size - 1]);
	vect->size -= 1;
}

/*
Description: elibereaza memoria ocupata de vector(distruge vectorul)

In:
	- vect - pointer la vector
*/
void destroyVector(DynamicVect* vect) {
	for (int i = 0; i < vect->size; i++) {
		vect->destroy(vect->elems[i]);
	}
	free(vect->elems);
	free(vect);
}

/*
	Description: adauga un element la vector

	In:
		- vect - pointer la vector
		- void* - pointer la element
	*/
void append(DynamicVect* vect, ElemType elem) {
	
	if (vect->size == vect->capacity) {
		vect->capacity *= 2;
		vect->elems = realloc(vect->elems, sizeof(ElemType) * vect->capacity);
	}
	vect->elems[vect->size] = elem;
	vect->size ++;
}

//Returneaza lungimea vectorului
int getSize(DynamicVect* vect) {
	return vect->size;
}

//Returneaza pointer-ul la elementul de pe pozitia poz
ElemType getElement(DynamicVect* vect, int poz) {
	return vect->elems[poz];
}

//Seteaza un element al vectorului
void setElement(DynamicVect* vect, int poz, ElemType value) {
	vect->elems[poz] = value;
}