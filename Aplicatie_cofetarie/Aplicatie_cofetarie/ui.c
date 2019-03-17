#include "ui.h"
#include <stdlib.h>
#include "service.h"
#include <stdio.h>
//Modulul pentru interactiunea cu utilizatorul

void displayMenu() {
	printf("Alegeti una dintre urmatoarele optiuni: \n");
	printf("1 Adaugare materie prima \n2 Modificare materie prima \n3 Stergere materie prima \n4 Afisare produse care incep cu o litera data \n5 Afisare produse cu cantitatea mai mica decat un numar dat \n6 Sortare dupa nume \n7 Sortare dupa cantitate \n0 Inchideti aplicatia\n");
	printf("Introduceti o optiune: ");
}

void addIngredientUI(Repository repo) {
	char name[20];
	char manufacturer[20];
	float quantity;

	printf("Introduceti numele materiei prime: ");
	scanf_s("%s", &name, 20);

	printf("Introduceti numele producatorului: ");
	scanf_s("%s", &manufacturer, 20);

	printf("Introduceti cantitatea: ");
	scanf("%f", &quantity);

	if (quantity <= 0)
	{
		printf("Cantitatea trebuie sa fie pozitiva!!!");
		return;
	}

	if (addIngredient(repo, name, manufacturer, quantity))
		printf("\nIngredientul a fost adaugat!\n\n");
	else
		printf("\nIngredientul exista deja si a fost actualizat!\n\n");

	for (int i = 0; i < getNumberOfElems(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(getAll(repo), i)), getManufacturer(getElement(getAll(repo), i)), getQuantity(getElement(getAll(repo), i)));
	}
	printf("\n");
}

void modifyIngredientUI(Repository repo) {
	char name[20];
	char manufacturer[20];
	float quantity;

	printf("Introduceti numele materiei prime pe care doriti sa o modificati: ");
	scanf_s("%s", &name, 20);

	printf("Introduceti numele producatorului: ");
	scanf_s("%s", &manufacturer, 20);

	printf("Introduceti cantitatea: ");
	scanf("%f", &quantity);

	if (quantity <= 0)
	{
		printf("Cantitatea trebuie sa fie pozitiva!!!");
		return;
	}

	if (modifyIngredient(repo, name, manufacturer, quantity))
		printf("\nIngredientul a fost modificat!\n\n");
	else
		printf("\nIngredientul cu numele %s nu exista!!!\n\n", name);

	for (int i = 0; i < getNumberOfElems(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(getAll(repo), i)), getManufacturer(getElement(getAll(repo), i)), getQuantity(getElement(getAll(repo), i)));
	}
	printf("\n");
}

void removeIngredientUI(Repository repo) {
	char name[20];

	printf("Introduceti numele materiei prime pe care doriti sa o stergeti: ");
	scanf_s("%s", &name, 20);

	if (removeIngredient(repo, name))
		printf("\nIngredientul a fost sters!\n\n");
	else
		printf("\nIngredientul cu numele %s nu exista!!!\n\n", name);

	for (int i = 0; i < getNumberOfElems(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(getAll(repo), i)), getManufacturer(getElement(getAll(repo), i)), getQuantity(getElement(getAll(repo), i)));
	}
	printf("\n");
}

void nameFilterUI(Repository repo) {
	char letter;
	printf("Introduceti litera dupa care filtrati materiile prime: ");
	scanf(" %c", &letter);

	DynamicVect* resultList = nameFilter(repo, letter);

	if (resultList->size == 0)
		printf("Nu exista materii prime ce incep cu litera %c!!!", letter);
	else {
		printf("\nLista produse:\n");
		for (int i = 0; i < getSize(resultList); i++) {
			printf("%s - %s - %f \n", getName(getElement(resultList, i)), getManufacturer(getElement(resultList, i)), getQuantity(getElement(resultList, i)));
		}
		printf("\n");
	}

	free(resultList->elems);
	free(resultList);
}

void quantityFilterUI(Repository repo) {
	float number;
	printf("Introduceti cantitatea maxima: ");
	scanf("%f", &number);

	DynamicVect* resultList = quantityFilter(repo, number);

	if (resultList->size == 0)
		printf("Nu exista materii prime cu cantitatea mai mica decat %f!!!", number);
	else {
		printf("\nLista produse:\n");
		for (int i = 0; i < getSize(resultList); i++) {
			printf("%s - %s - %f \n", getName(getElement(resultList, i)), getManufacturer(getElement(resultList, i)), getQuantity(getElement(resultList, i)));
		}
		printf("\n");
	}

	free(resultList->elems);
	free(resultList);
}

void sortByNameUI(Repository repo) {
	sortByName(repo);

	printf("\nLista produse:\n");
	for (int i = 0; i < getNumberOfElems(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(getAll(repo), i)), getManufacturer(getElement(getAll(repo), i)), getQuantity(getElement(getAll(repo), i)));
	}
	printf("\n");
}

void sortByQuantityUI(Repository repo) {
	sortByQuantity(repo);

	printf("\nLista produse:\n");
	for (int i = 0; i < getNumberOfElems(repo); i++) {
		printf("%s - %s - %f \n", getName(getElement(getAll(repo), i)), getManufacturer(getElement(getAll(repo), i)), getQuantity(getElement(getAll(repo), i)));
	}
	printf("\n");
}

void run(Repository myRepo) {
	int optiune;
	while (1) {
		displayMenu();
		scanf("%d", &optiune);
		
		if (optiune == 0) {
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
			case 4:
				nameFilterUI(myRepo);
				break;
			case 5:
				quantityFilterUI(myRepo);
				break;
			case 6:
				sortByNameUI(myRepo);
				break;
			case 7:
				sortByQuantityUI(myRepo);
				break;
			default:
				printf("Optiunea nu exista!!!");
				break;
		}
	}
}