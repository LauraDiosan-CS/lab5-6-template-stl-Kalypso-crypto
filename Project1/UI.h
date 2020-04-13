#pragma once
#include <iostream>
#include "service.h"

using namespace std;

class UI {
private:
	Service serv;
	void addCartea();
	void delCartea();
	void updCartea();
	void showAll();
	void returCarte();
	void imprumutareCarte();
public:
	UI();
	UI(Service&);
	void showUI();
};
