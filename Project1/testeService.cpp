#include "testeService.h"
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

void TestService::testAddCarte()
{
	Repo<Carte> repo;
	Service serv;
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
	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);
	assert(serv.getSizeC() == 2);
}

void TestService::testUpdateCarte()
{
	Repo<Carte> repo;
	Service serv;

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

	serv.addC(titlu1, autor1, true);

	serv.updateC(c1, titlu2, autor2, false);
	
	assert(serv.getC(0).getStatus() == false);
	assert(strcmp(serv.getC(0).getNume(), "baaab") == 0);
	assert(strcmp(serv.getC(0).getAutor(), "annna") == 0 );
}

void TestService::testDeleteCarte()
{
	Repo<Carte> repo;
	Service serv;

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

	serv.addC(titlu1, autor1, true);
	serv.addC(titlu2, autor2, false);

	assert(serv.getSizeC() == 2);

	serv.deleteC(c1);
	assert(serv.getSizeC() == 1);
}

void TestService::testRetur()
{
	RepoFile<Carte> repo;
	Service serv;
	serv.setRepo(repo);
	char* t = new char[10];
	char* a = new char[10];
	char* t2 = new char[10];
	char* a2 = new char[10];

	strcpy_s(a, sizeof "ana","ana");
	strcpy_s(a2, sizeof "dana", "dana");
	strcpy_s(t, sizeof "bac", "bac");
	strcpy_s(t2, sizeof "info", "info");

	serv.addC(t, a, true);
	serv.addC(t2, a2, false);

	deque<Carte> elemente = serv.getAll();
	int stare = serv.retur(t, elemente);

	assert(stare == 2);
	assert(serv.getAll()[0].getStatus() == false);

	int stare2 = serv.retur(t2, elemente);
	assert(stare2 == 1);
	assert(serv.getAll()[0].getStatus() == false);

}

void TestService::testImprumut()
{
	RepoFile<Carte> repo;
	Service serv;
	serv.setRepo(repo);
	char* t = new char[10];
	char* a = new char[10];
	char* t2 = new char[10];
	char* a2 = new char[10];

	strcpy_s(a, sizeof "ana", "ana");
	strcpy_s(a2, sizeof "dana", "dana");
	strcpy_s(t, sizeof "bac", "bac");
	strcpy_s(t2, sizeof "info", "info");

	serv.addC(t, a, true);
	serv.addC(t2, a2, false); 

	deque<Carte> elemente = serv.getAll();
	int stare = serv.imprumut(t, elemente);

	assert(stare == 1);
	assert(serv.getAll()[0].getStatus() == true);

	int stare2 = serv.imprumut(t2, elemente);
	assert(stare2 == 0);
	assert(serv.getAll()[0].getStatus() == true);

}



void TestService::testAll()
{
	testAddCarte();
	testUpdateCarte();
	testDeleteCarte();
	testRetur();
}
