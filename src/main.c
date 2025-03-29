//Bonne pratique, pour les includes systemes toujours utiliser <> et "" pour les includes de votre projet.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "definition.h"
#include "inventaire.h"

#define HEAP_SIZE 2048 * 2048 * 4
static uint8_t* heap = NULL;
static size_t heap_top = 0;                           
void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

int main(int argc, char** argv) {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);
	Objet objets[32] = { 0 };
	char buffer[2048];
	char* data;
	int objectCount = 0;

	FILE* input = fopen("tp1_data.csv", "r");

	while (fgets(buffer, sizeof(buffer), input))
	{
		Objet* obj;

		data = strtok(buffer, ",");

		data = strtok(NULL, ",");

		strcpy(objets[objectCount].name, data);

		data = strtok(NULL, ",");

		data = strtok(NULL, ",");

		int value = atoi(data);
		objets[objectCount].price = value;

		objectCount++;
	}

	fclose(input);

	Node* node = (Node*)allocate(sizeof(Node));
	node->data = NULL;
	node->next = NULL;

	Objet* nouvelleObjet = (Objet*)allocate(sizeof(Objet));
	strcpy(nouvelleObjet->name, "fiole");
	nouvelleObjet->price = 10;

	ajouterObjetHead(node, nouvelleObjet);

	ajouterItemAleatoire(node, 1, objets, objectCount);

	Node* current = node;
	while (current != NULL) {
		Objet* obj = (Objet*)current->data;
		printf("%s - %zu\n", obj->name, obj->price);
		current = current->next;
	}

	node = supprimerParNom(node, "fiole");

	sort(node);

	while (current != NULL) {
		Objet* obj = (Objet*)current->data;
		printf("%s - %zu\n", obj->name, obj->price);
		current = current->next;
	}


}