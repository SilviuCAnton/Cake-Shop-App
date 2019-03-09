#include "ui.h"
#include <stdlib.h>
#include "service.h"
#include <stdio.h>

void displayMenu() {
	printf("Alegeti una dintre urmatoarele optiuni: \n");
	printf("1 Adaugare materie prima \n2 Modificare materie prima \n3 Stergere materie prima \n0 Inchideti aplicatia\n");
	printf("Introduceti o optiune: ");
}

void addIngredientUI(DynamicVect* repo) {
	char name[20];
	char manufacturer[20];
	float quatity;

	printf("Introduceti numele materiei prime: ");
	scanf_s("%s", &name, 20);

	printf("Introduceti numele producatorului: ");
	scanf_s("%s", &manufacturer, 20);

	printf("Introduceti cantitatea: ");
	scanf("%f", &quatity);

	if (addIngredient(repo, name, manufacturer, quatity))
		printf("\nIngredientul a fost adaugat!\n\n");
	else
		printf("\nIngredientul exista deja si a fost actualizat!\n\n");

	for (int i = 0; i < getSize(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(repo, i)), getManufacturer(getElement(repo, i)), getQuantity(getElement(repo, i)));
	}
	printf("\n");
}

void modifyIngredientUI(DynamicVect* repo) {
	char name[20];
	char manufacturer[20];
	float quatity;

	printf("Introduceti numele materiei prime pe care doriti sa o modificati: ");
	scanf_s("%s", &name, 20);

	printf("Introduceti numele producatorului: ");
	scanf_s("%s", &manufacturer, 20);

	printf("Introduceti cantitatea: ");
	scanf("%f", &quatity);

	if (modifyIngredient(repo, name, manufacturer, quatity))
		printf("\nIngredientul a fost modificat!\n\n");
	else
		printf("\nIngredientul cu numele %s nu exista!!!\n\n", name);

	for (int i = 0; i < getSize(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(repo, i)), getManufacturer(getElement(repo, i)), getQuantity(getElement(repo, i)));
	}
	printf("\n");
}

void removeIngredientUI(DynamicVect* repo) {
	char name[20];

	printf("Introduceti numele materiei prime pe care doriti sa o stergeti: ");
	scanf_s("%s", &name, 20);

	if (removeIngredient(repo, name))
		printf("\nIngredientul a fost sters!\n\n");
	else
		printf("\nIngredientul cu numele %s nu exista!!!\n\n", name);

	for (int i = 0; i < getSize(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(repo, i)), getManufacturer(getElement(repo, i)), getQuantity(getElement(repo, i)));
	}
	printf("\n");
}

void run() {
	DynamicVect* myRepo = createVector();
	int optiune;
	while (1) {
		displayMenu();
		scanf("%d", &optiune);
		
		if (optiune == 0) {
			for (int i = 0; i < getSize(myRepo); i++)
				destroyIngredient(myRepo->elems[i]);

			destroyVector(myRepo);
			printf("Se inchide aplicatia...");
			break;
		}

		switch(optiune){
			case 1:
				addIngredientUI(myRepo);
				break;
			case 2:
				modifyIngredientUI(myRepo);
				break;
			case 3:
				removeIngredientUI(myRepo);
				break;
			default:
				printf("Optiunea nu exista!!!");
				break;
		}
	}
}