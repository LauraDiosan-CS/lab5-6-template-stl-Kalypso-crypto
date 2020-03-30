#pragma once

class Carte{
private:
	char* nume, *autor;
	bool status;
public:
	Carte();
	Carte(char*, char*, bool);
	Carte(const Carte&);

	char* getNume();
	char* getAutor();
	bool getStatus();

	void setNume(char*);
	void setAutor(char*);
	void setStatus(bool);

	Carte& operator = (const Carte&);
	bool operator == (const Carte&);
	friend std::ostream& operator << (std::ostream&, const Carte&);
	~Carte();

};