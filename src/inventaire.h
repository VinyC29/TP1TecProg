#pragma once

#include <stdint.h>
#include <assert.h>

typedef struct Node Node;

struct Node
{
	void* data;
	Node* next;
};

typedef struct objet_t
{
	char* name[256];
	size_t price;
} Objet;

void ajouterObjet(Node* currNode, void* nouvelleObjet);

void ajouterObjetHead(Node* currNode, void* nouvelleObjet);

Node* supprimerParNom(Node* head, char* name);

void sort(Node* head);

Objet* trouverParPosition(Node* head, int position);

Objet* trouverParNom(Node* head, char* name);

int quantitéItem(Node* head);

Node* ajouterItemAleatoire(Node* head, int itemQuantite, Objet* objets, int quantiteObjet);