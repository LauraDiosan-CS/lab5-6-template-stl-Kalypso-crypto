#include <string.h>
#include <iostream>
#include "biblioteca.h"

Carte::Carte()
{
	this->nume = NULL;
	this->autor = NULL;
	this->status = false;
}

Carte::Carte(char* nume, char* autor, bool status)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
	this->status = status;
}

Carte::Carte(const Carte& c)
{
	this->nume = new char[strlen(c.nume) + 1];
	strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
	this->autor = new char[strlen(c.autor) + 1];
	strcpy_s(this->autor, strlen(c.autor) + 1, c.autor);
	this->status = c.status;
}

char* Carte::getNume()
{
	return this->nume;
}

char* Carte::getAutor()
{
	return this->autor;
}

bool Carte::getStatus()
{
	return this->status;
}

void Carte::setNume(char* numeNou)
{
	if (this->nume) { delete[] this->nume; this->nume = NULL; }
	this->nume = new char[strlen(numeNou) + 1];
	strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);
}

void Carte::setAutor(char* autorNou)
{
	if (this->autor) { delete[] this->autor; this->autor = NULL; }
	this->autor = new char[strlen(autorNou) + 1];
	strcpy_s(this->autor, strlen(autorNou) + 1, autorNou);
}

void Carte::setStatus(bool statusNou)
{
	this->status = statusNou;
}

Carte& Carte::operator=(const Carte& c)
{
	this->setNume(c.nume);
	this->setAutor(c.autor);
	this->setStatus(c.status);
	return *this;
}

bool Carte::operator==(const Carte& c)
{
	if (strcmp(this->nume, c.nume) == 0) return true;
	else return false;
}


std::ostream& operator<<(std::ostream& os, const Carte& c)
{
	os << " Nume: " << c.nume << " Autor: " << c.autor << " Status: " << c.status << std::endl;
	return os;
}
istream& operator>>(istream& is, Carte& c)
{
	cout << "Dati titlul: ";
	char* titlu = new char[10];
	is >> titlu;
	cout << "Dati autor: ";
	char* autor = new char[10];
	is >> autor;
	cout << "Dati status: ";
	bool status;
	is >> status;
	c.setNume(titlu);
	c.setAutor(autor);
	c.setStatus(status);
	delete[] titlu;
	delete[] autor;
	return is;
}
Carte::~Carte()
{
	if (this->nume) {
		delete[] this->nume;
		this->nume = NULL;
	}
	if (this->autor) {
		delete[] this->autor;
		this->autor = NULL;
	}
	this->status = false;
}
