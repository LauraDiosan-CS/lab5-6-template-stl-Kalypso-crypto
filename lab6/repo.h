#pragma once
#include "biblioteca.h"
#include <deque>
template <typename T>
class Repo {
private:
	std::deque<T> elem;
public:
	Repo();
	bool addCarte(T e);
	std::deque<T> getAll();
	~Repo();
	int size();
};

template <typename T>
Repo<T>::Repo()
{
}

template<typename T>
bool Repo<T>::addCarte(T e)
{
	this->elem.push_back(e);
	return 1;
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
	this->elem.size();
}
