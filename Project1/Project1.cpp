#include <iostream>
#include "teste.h"
#include "biblioteca.h"
#include "testeService.h"
#include "repo.h"
#include <iostream>
#include "UI.h"
#include "RepoFile.h"
#include "testeRepoFile.h"


using namespace std;

int main()
{
    TesteRepoFile tt;
    tt.testAll3();
    cout << "merge    ";
    TestRepo test;
    TestService testS;
    test.testAll();
    cout << "A mers testRepo" << endl;
    testS.testAll();
    cout << "A mers si testService" << endl << "Sa vedem acum programul cum merge...." << endl;
    RepoFile<Carte> repo("Carti.txt");
    Service serv(repo);
    UI ui(serv);
    ui.showUI();
    return 0;
}
