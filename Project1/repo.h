#pragma once
#include "biblioteca.h"
#include <deque>
using namespace std;
template <typename T>
class Repo {
protected:
	std::deque<T> elem;
public:
	Repo();
	void addCarte(T e);
	std::deque<T> getAll();
	~Repo();
	int size();
	int deleteCarte(T);
	int updateCarte(T, T);
	int findCarte(T);
	T getCarte(int);
};

template <typename T>
Repo<T>::Repo()
{
}

template<typename T>
void Repo<T>::addCarte(T e)
{
	this->elem.push_back(e);
	
}

template<typename T>
std::deque<T> Repo<T>::getAll()
{
	return this->elem;
}

template<typename T>
Repo<T>::~Repo()
{
}

template<typename T>
int Repo<T>::size()
{
	return this->elem.size();
}

template<typename T>
int Repo<T>::deleteCarte(T carte)
{
	deque<Carte>::iterator it = find(elem.begin(), elem.end(), carte);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	return -1;
}

template<typename T>
int Repo<T>::updateCarte(T carte, T carteNoua)
{
	deque<Carte>::iterator it = find(elem.begin(), elem.end(), carte);
	if (it != elem.end())
	{
		*it = carteNoua;
		return 0;
	}
	return -1;
}

template<typename T>
int Repo<T>::findCarte(T carte)
{
	deque<Carte>::iterator it = find(elem.begin(), elem.end(), carte);
	if (it != elem.end())
	{
		return distance(elem.begin(), it);
	}
	return -1;
}

template<typename T>
T Repo<T>::getCarte(int pos)
{
	return this->elem[pos];
}

