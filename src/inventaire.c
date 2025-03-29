#include "inventaire.h"
#include <stdbool.h>

void ajouterObjetHead(Node* head, void* newData)
{
	if (head->data == NULL) {
		head->data = newData;
		return;
	}

	Node* newNode = allocate(sizeof(Node));
	newNode->data = newData;
	newNode->next = head->next;
	head->next = newNode;
}
                                  
void ajouterObjet(Node* currNode, void* newData) {
	Node newNode = { 0 };
	newNode.data = newData;
	newNode.next = NULL;
	if (currNode->next != NULL) {
		newNode.next = currNode->next;
	}
	currNode->next = &newNode;
}

Node* supprimerParNom(Node* head, char* name) {
	Node* temp = head;
	Node* last = NULL;

	// Search for the node to delete
	while (temp != NULL && strcmp(name, ((Objet*)temp->data)->name) != 0) {
		last = temp;
		temp = temp->next;
	}

	if (last == NULL) {
		Node* newHead = temp->next;
		memset(temp, 0, sizeof(Node));
		return newHead;
	}
	else {
		last->next = temp->next;
		memset(temp, 0, sizeof(Node));
		return head;  
	}
}

void sort(Node* head)
{
	bool echanger = false;

	Node* pointeur = head;
	Node* lastpointeur = NULL;

	do {
		echanger = false;
		pointeur = head;

		while (pointeur->next != lastpointeur) {
			Objet* objet1 = (Objet*)pointeur->data;
			Objet* objet2 = (Objet*)pointeur->next->data;

			if (objet1->price > objet2->price) {
				void* temporaire = pointeur->data;
				pointeur->data = pointeur->next->data;
				pointeur->next->data = temporaire;
				echanger = true;
			}
			pointeur = pointeur->next;
		}
		lastpointeur = pointeur;
	} while (echanger);
}

Objet* trouverParPosition(Node* head, int position) {
	Node* current = head;
	int index = 0;

	while (current != NULL) {
		if (index == position) {
			return (Objet*)current->data;
		}

		current = current->next;
		index++;
	}

	return NULL;
}

Objet* trouverParNom(Node* head, char* name) {
	Node* current = head;

	while (current != NULL) {
		if (strcmp(name, ((Objet*)current->data)->name) == 0) {
			return (Objet*)current->data;
		}

		current = current->next;
	}

	return NULL;
}

int quantitéItem(Node* head)
{
	Node* current = head;
	int index = 0;

	if (head->data == NULL) {
		return 0;
	}

	while (current != NULL) {
		current = current->next;
		index++;
	}

	return index;
}


Node* ajouterItemAleatoire(Node* head, int itemQuantite, Objet* objets, int quantiteObjet)
{
	for (int i = 0; i < itemQuantite; i++) {
		int rd_num = rand() % quantiteObjet;
		ajouterObjet(head, &objets[rd_num]);
	}
	return head;
}