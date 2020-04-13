#include "UI.h"
#include <iostream>

using namespace std;

void UI::addCartea()
{
	cout << "Dati cartea: ";
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	cout << "Dati titlu: ";
	cin >> titlu;
	cout << "Dati autor: ";
	cin >> autor;
	cout << "Dati status(true/false): ";
	cin >> status;
	serv.addC(titlu, autor, status);
	cout << "Carte adaugata!" << endl;
	delete[] titlu;
	delete[] autor;
}

void UI::delCartea()
{
	Carte carte;
	cout << "Dati cartea: ";
	cin >> carte;
	int rez = serv.deleteC(carte);
	if (rez == 0)cout << "Carte stearsa!";
	else cout << "Cartea NU a fost stearsa!";
}

void UI::updCartea()
{
	Carte carte;
	cout << "Dati cartea: ";
	cin >> carte;
	char* titlu = new char[10];
	char* autor = new char[10];
	bool status;
	cout << "Dati titlu: ";
	cin >> titlu;
	cout << "Dati autor: ";
	cin >> autor;
	cout << "Dati status(true/false): ";
	cin >> status;
	serv.updateC(carte, titlu, autor, status);
	cout << "Modificat cu succes!";
	delete[] titlu;
	delete[] autor;
}

void UI::showAll()
{
	cout << endl << "Elementele cozii sunt" << endl;
	for (int i = 0; i < serv.getSizeC(); i++)
	{
		cout << serv.getAll()[i];
	}
}

void UI::returCarte()
{
	char* titlu = new char[10];
	char* autor = new char[10];
	deque<Carte> a;
	bool opt = 1;
	while (opt)
	{
		deque<Carte> elemente = serv.getAll();
		cout << "Dati titlul pe care il cautati: ";
		cin >> titlu;
		int stare = serv.retur(titlu, elemente);
		if (stare == 0) cout << "Titlul NU a fost gasit!" << endl;
		if (stare == 1) cout << "Cartea nu este imprumutata!" << endl;
		if (stare == 2) cout << "Cartea a fost gasita si returnata cu succes!" << endl;
		cout << "Daca doriti sa continuati dati 1, altfel 0: ";
		cin >> opt;
	}
}

void UI::imprumutareCarte()
{
	char* titlu = new char[10];
	char* autor = new char[10];
	deque<Carte> a;
	bool opt = 1;
	while (opt)
	{
		deque<Carte> elemente = serv.getAll();
		cout << "Dati titlul pe care il cautati: ";
		cin >> titlu;
		char* autor = new char[10];
		for (int i = 0; i < serv.getSizeC(); i++)
		{
			if (strcmp(elemente[i].getNume(), titlu) == 0)  autor = elemente[i].getAutor();
		}
		int stare = serv.imprumut(titlu, elemente);
		if (stare == 0) cout << "Titlul NU a fost gasit!";
		if (stare == 1)
		{
			cout << "Cartea nu este disponibila!";
			int exista = 0;
			for (int i = 0; i < serv.getSizeC(); i++)
			{
				cout << "Alta carti disponibile: " << endl;
				if (strcmp(elemente[i].getAutor(), autor) == 0 && elemente[i].getStatus() == false)
				{
					exista = 1;
					cout << serv.getAll()[i];
				}
			}
			if (exista == 0) cout << "nu exista alte carti disponibile scrise de acest autor" << endl;
		}
		if (stare == 2) cout << "Cartea a fost gasita si imprumutata cu succes!" << endl;
		cout << "Daca doriti sa continuati dati 1, altfel 0: ";
		cin >> opt;
	}
}

UI::UI()
{
}

UI::UI(Service& serv)
{
	this->serv = serv;
}

void UI::showUI()
{
	bool gata = false;
	int opt = 1;
	while (opt)
	{
		cout << "Optiuni: " << endl;
		cout << "0.Exit " << endl;
		cout << "1.Add " << endl;
		cout << "2.Delete " << endl;
		cout << "3.Update " << endl;
		cout << "4.Afisare " << endl;
		cout << "5.Imprumutare " << endl;
		cout << "6.Returnare " << endl;
		cout << "Dati optiunea: " << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			addCartea();
			break;
		case 2:
			delCartea();
			break;
		case 3:
			updCartea();
			break;
		case 4:
			showAll();
			break;
		case 5:
			imprumutareCarte();
			break;
		case 6:
			returCarte();
			break;
		case 0:
			cout << "Ceau pa!";
			break;
		}
	}
	

}
