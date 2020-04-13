#include "teste.h"
#include <iostream>
#include "repo.h"
#include <assert.h>
#include <cassert>
#include <ostream>
using namespace std;

//void teste_repo() {
//	Repo<Carte> repo;
//	char* titlu1 = new char[10];
//	char* autor1 = new char[10];
//	strcpy_s(autor1, sizeof "ana", "ana");
//	strcpy_s(titlu1, sizeof "bab", "bab");
//	Carte c1(titlu1, autor1, true);
//	repo.addCarte(c1);
//	assert(repo.size() == 1);
//}



//void teste()
//{
//	Carte* c;
//	c = new Carte();
//
//	assert((c->getNume() == NULL) && (c->getAutor() == NULL) && (c->getStatus() == false));
//
//	char* autor1 = new char[10];
//	char* titlu1 = new char[10];
//
//	strcpy_s(autor1, sizeof "ana", "ana");
//	strcpy_s(titlu1, sizeof "bab", "bab");
//
//	Carte* c1 = new Carte(titlu1, autor1, true);
//
//	assert((strcmp(c1->getNume(), "bab") == 0) && (strcmp(c1->getAutor(), "ana") == 0) && (c1->getStatus() == true));
//	c1->setStatus(false);
//
//	assert((strcmp(c1->getNume(), "bab") == 0) && (strcmp(c1->getAutor(), "ana") == 0) && (c1->getStatus() == false));
//	if (c1 != NULL) {
//		delete c1;
//		c1 = NULL;
//	}
//}

void TestRepo::testGetSize()
{
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	Carte c1(titlu1, autor1, true);
	repo.addCarte(c1);
	assert(repo.size() == 1);
}

void TestRepo::testGetAll()
{
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	strcpy_s(autor2, sizeof "annna", "annna");
	strcpy_s(titlu2, sizeof "baaab", "baaab");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	repo.addCarte(c1);
	repo.addCarte(c2);
	assert(repo.findCarte(c1) == 0);
	assert(repo.findCarte(c2) == 1);
}

void TestRepo::testAddCarte()
{
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	strcpy_s(autor2, sizeof "annna", "annna");
	strcpy_s(titlu2, sizeof "baaab", "baaab");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	repo.addCarte(c1);
	repo.addCarte(c2);
	assert(repo.size() == 2);
}

void TestRepo::testUpdateCarte()
{
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	strcpy_s(autor2, sizeof "annna", "annna");
	strcpy_s(titlu2, sizeof "baaab", "baaab");
	Carte c1(titlu1, autor1, true);
	repo.addCarte(c1);
	repo.updateCarte(c1, Carte(titlu2, autor2, false));
	assert(strcmp(repo.getAll()[0].getAutor(), "annna") == 0);
	assert(strcmp(repo.getAll()[0].getNume(), "baaab") == 0);
	assert(repo.getAll()[0].getStatus() == false);

	assert(strcmp(repo.getCarte(0).getAutor(), "annna") == 0);
	assert(strcmp(repo.getCarte(0).getNume(), "baaab") == 0);
	assert(repo.getCarte(0).getStatus() == false);
}

void TestRepo::testDeleteCarte()
{
	Repo<Carte> repo;
	char* titlu1 = new char[10];
	char* autor1 = new char[10];
	char* titlu2 = new char[10];
	char* autor2 = new char[10];
	strcpy_s(autor1, sizeof "ana", "ana");
	strcpy_s(titlu1, sizeof "bab", "bab");
	strcpy_s(autor2, sizeof "annna", "annna");
	strcpy_s(titlu2, sizeof "baaab", "baaab");
	Carte c1(titlu1, autor1, true);
	Carte c2(titlu2, autor2, false);
	repo.addCarte(c1);
	repo.addCarte(c2);
	assert(repo.size() == 2);
	repo.deleteCarte(c2);
	assert(repo.size() == 1);
}

void TestRepo::testAll()
{
	this->testAddCarte();
	this->testUpdateCarte();
	this->testGetSize();
	this->testDeleteCarte();
	this->testGetAll();
}
