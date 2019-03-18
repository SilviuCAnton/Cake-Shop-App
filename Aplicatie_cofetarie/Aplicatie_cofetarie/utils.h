#pragma once
#include "domain.h"

typedef void* ElemType;
typedef void(*DestroyFunction)(ElemType);

typedef struct {
	ElemType* elems;
	DestroyFunction destroy;
	int size;
	int capacity;
}DynamicVect;

DynamicVect* createVector(DestroyFunction f);
void destroyVector(DynamicVect* vect);
ElemType getElement(DynamicVect* vect, int poz);
int getSize(DynamicVect* vect);
void append(DynamicVect* vect, ElemType elem);
void removeElement(DynamicVect* vect, int poz);
void setElement(DynamicVect* vect, int poz, ElemType value);