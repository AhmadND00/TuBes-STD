#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iomanip>
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define nextChild(P) (P)->nextChild
#define first(LN) ((LN).first)

typedef struct negara infotypeNegara;
typedef struct pemain infotypePemain;
typedef struct elmNegara *adrNegara;
typedef struct elmPemain *adrPemain;

struct negara{
    string namaNegara, konfiderasi;
    int finish, totJuara;
};

struct pemain{
    string namaPemain, klub, posisi;
    int no, umur, totGoal;
};

struct elmNegara{
    infotypeNegara info;
    adrNegara next;
    adrPemain nextChild;
};

struct elmPemain{
    infotypePemain info;
    adrPemain next;
};

struct listNegara{
    adrNegara first;
};

void createListNegara(listNegara &LN);
adrNegara newNegara(infotypeNegara X);
void insertFirstNegara(listNegara &LN, adrNegara P);
void insertLastNegara(listNegara &LN, adrNegara P);
void insertAfterNegara(listNegara &LN, adrNegara Prec, adrNegara P);
void insertAscNegara(listNegara &LN, adrNegara P);
adrPemain newPemain(infotypePemain X);
void insertPemain(listNegara &LN, adrPemain P, string namaNegara);
adrNegara findNegara(listNegara LN, string namaNegara);
void printNegara(listNegara LN);
void printListPemain(listNegara LN);
void mainMenu();
void menuInsert();
void menuShow();
#endif // MLL_H_INCLUDED