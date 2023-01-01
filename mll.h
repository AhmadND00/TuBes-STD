#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iomanip>
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextChild(P) (P)->nextChild
#define first(LN) ((LN).first)
#define last(LN) ((LN).last)

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
    adrNegara prev;
    adrPemain nextChild;
};

struct elmPemain{
    infotypePemain info;
    adrPemain next;
};

struct listNegara{
    adrNegara first;
    adrNegara last;
};

// Procedure and Function for Negara
void createListNegara(listNegara &LN);
adrNegara newNegara(infotypeNegara X);
void insertFirstNegara(listNegara &LN, adrNegara P);
void insertLastNegara(listNegara &LN, adrNegara P);
void insertAfterNegara(listNegara &LN, adrNegara Prec, adrNegara P);
void insertAscNegara(listNegara &LN, adrNegara P);
void deleteFirstNegara(listNegara &LN, adrNegara &P);
void deleteLastNegara(listNegara &LN, adrNegara &P);
void deleteAfterNegara(listNegara &LN, adrNegara &P);
void deleteAllNegara(listNegara LN);
void inputNegara(listNegara &LN, adrNegara P, infotypeNegara X);
adrNegara findNegara(listNegara LN, string namaNegara);
void printNegara(listNegara LN);

// Procedure and Function for Pemain
adrPemain newPemain(infotypePemain X);
void insertPemainFirst(listNegara &LN, adrPemain P, adrNegara Q, adrPemain R);
void insertPemainLast(listNegara &LN, adrPemain P, adrNegara Q, adrPemain R);
void deletePemain(listNegara &LN, string namaNegara);
void insertPemain(listNegara &LN, adrPemain P, string namaNegara);
void inputPemain(listNegara &LN, adrPemain Q, infotypePemain xP, int N);
void printListPemain(listNegara LN);

// Menu and Additional Function
void mainMenu();
void menuInsert();
void menuShow();
void menuDelete();
void youngestOldestPlayer(listNegara LN);
void avrAge(listNegara LN, string namaNegara);
#endif // MLL_H_INCLUDED
