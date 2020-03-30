#include "teste.h"
#include "biblioteca.h"
#include <deque>
#include <vector>
#include <iostream>
#include <cassert>
#include "repo.h"

void teste_repo() {
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	Carte c1(titlu1, autor1, true);
	repo.addCarte(c1);
	assert(repo.size() == 1);
}

void teste() {
	Carte* c;
	c = new Carte();

	assert((c->getNume() == NULL) && (c->getAutor() == NULL) && (c->getStatus == false));

	char* autor1 = new char[10];
	char* titlu1 = new char[10];

	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");

	Carte* c1 = new Carte(titlu1, autor1, true);

	assert((strcmp(c1->getNume(), "bab") == 0) && (strcmp(c1->getAutor(), "ana") == 0) && (c1->getStatus() == true));
	c1->setStatus(false);

	assert((strcmp(c1->getNume(), "bab") == 0) && (strcmp(c1->getAutor(), "ana") == 0) && (c1->getStatus() == false));
	if (c1 != NULL) {
		delete c1;
		c1 = NULL;
	}
	teste_repo();
}