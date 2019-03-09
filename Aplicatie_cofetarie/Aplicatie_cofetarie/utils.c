#include "utils.h"
#include "domain.h"
#include <stdlib.h>

DynamicVect* createVector() {
	DynamicVect* v = malloc(sizeof(DynamicVect));
	v->elems = malloc(sizeof(void*));
	v->size = 0;
	v->capacity = 1;
	return v;
}

void destroyVector(DynamicVect* v) {
	for (int i = 0; i < getSize(v); i++) {
		free(v->elems[i]);
	}
	free(v->elems);
	free(v);
}

void append(DynamicVect* v, void* elem) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->elems = realloc(v->elems, sizeof(void*) * v->capacity);
	}
	v->elems[v->size] = elem;
	v->size ++;
}

int getSize(DynamicVect* v) {
	return v->size;
}

void* getElement(DynamicVect* v, int poz) {
	return v->elems[poz];
}

void decSize(DynamicVect* v) {
	v->size -= 1;
}