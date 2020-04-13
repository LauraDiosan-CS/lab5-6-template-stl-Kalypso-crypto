#include "service.h"
using namespace std;

Service::Service()
{
}

Service::Service(RepoFile<Carte>& r)
{
	repo = r;
}

void Service::addC(char* titlu, char* autor, bool status)
{
	Carte c(titlu, autor, status);
	repo.addCarte(c);
}

int Service::deleteC(Carte c)
{
	return repo.deleteCarte(c);
}

Carte Service::getC(int pos)
{
	return repo.getCarte(pos);
}

void Service::updateC(Carte c, char* titlu, char* autor, bool status)
{
	
	repo.updateCarte(c,Carte(titlu, autor, status));
}

void Service::updateT(char* titlu, char* newTitlu, char* newAutor, bool newStatus)
{
}

void Service::setRepo(RepoFile<Carte>& r)
{
	repo = r;
}



int Service::imprumut(char* titlu, deque<Carte> elemente)
{
	int stare;
	for (Carte current : elemente)
	{
		
		if (strcmp(current.getNume(), titlu) == 0) stare = 1;
		else stare = 0;
		if ((current.getStatus() == false) && stare == 1)
		{
			repo.updateCarte(current, Carte(titlu, current.getAutor(), 1));
			stare = 2;
		}
		if (stare) return stare;
	}
	return 0;
}

int Service::retur(char* titlu, deque<Carte> elemente)
{
	int stare;
	for (Carte current : elemente)
	{
		if (strcmp(current.getNume(), titlu) == 0) stare = 1;
		else stare = 0;
		if ((current.getStatus() == true) && stare == 1)
		{
			repo.updateCarte(current, Carte(titlu, current.getAutor(), 0));
			stare = 2;
		}
		if (stare) return stare;
	}
	return 0;
}

int Service::getCarteAtPos(Carte c)
{
	return this->repo.findCarte(c);
}

int Service::getSizeC()
{
	return this->repo.size();
}

deque<Carte> Service::getAll()
{
	deque<Carte> rez = repo.getAll();
	deque<Carte> v(rez.begin(), rez.end());
	return v;
}

Service::~Service()
{
}
