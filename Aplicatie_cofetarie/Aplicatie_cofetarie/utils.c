#include "utils.h"
#include "domain.h"
#include <stdlib.h>

DinamicVect createVector() {
	DinamicVect v;
	v.elems = (int*)malloc(sizeof(Ingredient));
	v.size = 0;
	v.capacity = 1;
	return v;
}

void append(DinamicVect* v, Ingredient ing) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->elems = (Ingredient*) realloc(v->elems, sizeof(Ingredient) * v->capacity);
	}
	v->elems[v->size] = ing;
	v->size ++;
}

int getSize(DinamicVect* v) {
	return v->size;
}

void decSize(DinamicVect* v) {
	v->size -= 1;
}