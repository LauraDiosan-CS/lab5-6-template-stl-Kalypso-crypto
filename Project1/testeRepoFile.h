#pragma once
#include "RepoFile.h"
#include <assert.h>
#include <iostream>

class TesteRepoFile {
private:
	void loadFromFile();
public:
	void testAll3();
};

void TesteRepoFile::loadFromFile()
{
	RepoFile<Carte> repo;
	assert(repo.size() == 0);
	repo.loadFromFile("Carti.txt");
	assert(repo.size() == 1);
}

void TesteRepoFile::testAll3() {
	loadFromFile();
}
