#pragma once
#include "domain.h"

typedef struct {
	void** elems;
	int size;
	int capacity;
}DynamicVect;

DynamicVect* createVector();
void destroyVector(DynamicVect* v);
void* getElement(DynamicVect* v, int poz);
int getSize(DynamicVect* v);
void append(DynamicVect* v, void* elem);
void removeElement(DynamicVect* v, int poz);