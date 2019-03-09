#pragma once
#include "domain.h"

typedef struct {
	Ingredient* elems;
	int size;
	int capacity;
}DinamicVect;

DinamicVect createVector();
int getSize(DinamicVect* v);
void append(DinamicVect* v, Ingredient ing);
void decSize(DinamicVect* v);