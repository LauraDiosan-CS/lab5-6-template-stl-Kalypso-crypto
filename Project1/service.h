#pragma once
#include "RepoFile.h"
#include "biblioteca.h"
#include <deque>

using namespace std;

//template <typename T>
class Service
{

private:
	RepoFile<Carte> repo;
public:
	Service();
	Service(RepoFile<Carte>&);
	void addC(char*, char*, bool);
	int deleteC(Carte);
	Carte getC(int);
	void updateC(Carte, char*, char*, bool);
	void updateT(char* titlu, char* newTitlu, char* newAutor, bool newStatus);
	void setRepo(RepoFile<Carte>&);
	int imprumut(char* titlu, deque<Carte> elemente);
	int retur(char* titlu, deque<Carte> elemente);
	int getCarteAtPos(Carte);
	int getSizeC();
	deque <Carte> getAll();
	~Service();
};