#pragma once
#include "biblioteca.h"
#include "repo.h"

class TestRepo {
private:
	void testGetSize();
	void testGetAll();
	void testAddCarte();
	void testUpdateCarte();
	void testDeleteCarte();
public:
	void testAll();
};