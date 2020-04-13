#pragma once
#include "biblioteca.h"
#include "repo.h"
#include <deque>
#include <string.h>
#include <fstream>
using namespace std;

template <class T>
class RepoFile : public Repo<T>
{
private:
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	~RepoFile();
};

template<class T>
RepoFile<T>::RepoFile()
{
	fis = NULL;
}

template<class T>
RepoFile<T>::RepoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	char* autor = new char[10];
	this->loadFromFile(fis);

}



template<class T>
void RepoFile<T>::loadFromFile(const char* fileName)
{
	Repo<T>::elem.clear();
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	char* autor = new char[10];
	bool status;
	if (fis != NULL)
	{
		while (!f.eof())
		{
			f >> nume >> autor >> status;
			if (strlen(nume) != 0)
			{
				Carte c(nume, autor, status);
				Repo<T>::elem.push_back(c);
			}
		}
		delete[] nume;
		delete[] autor;
	}
}


template<class T>
RepoFile<T>::~RepoFile()
{
}
