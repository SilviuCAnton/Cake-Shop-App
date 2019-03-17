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
void destroyVector(DynamicVect* v);
ElemType getElement(DynamicVect* v, int poz);
int getSize(DynamicVect* v);
void append(DynamicVect* v, ElemType elem);
void removeElement(DynamicVect* v, int poz);