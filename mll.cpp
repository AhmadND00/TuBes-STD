#include "mll.h"

// Procedure to create empty list
void createListNegara(listNegara &LN){
    first(LN) = NULL;
}

// Create New Element Negara
adrNegara newNegara(infotypeNegara X){
    adrNegara P = new elmNegara;
    info(P).namaNegara = X.namaNegara;
    info(P).konfiderasi = X.konfiderasi;
    info(P).finish = X.finish;
    info(P).totJuara = X.totJuara;
    nextChild(P) = NULL;
    next(P) = NULL;
    return P;
}


//
void insertFirstNegara(listNegara &LN, adrNegara P){
    if (first(LN) == NULL){
        first(LN) = P;
        next(P) = NULL;
    } else {
        next(P) = first(LN);
        first(LN) = P;
    }

}

//
void insertLastNegara(listNegara &LN, adrNegara P){


}

//
void insertAfterNegara(listNegara &LN, adrNegara P){


}


// Input negara pada list negara sesusai dengan urutan mereka di piala dunia
void insertAscNegara(listNegara &LN, adrNegara P){


}

void printNegara(listNegara LN){
    cout<<"List Negara"<<endl;
    adrNegara P = first(LN);
    while (P != NULL){
        cout<<"Negara: "<<info(P).namaNegara<<endl;
        cout<<"Konfiderasi: "<<info(P).konfiderasi<<endl;
        cout<<"Posisi: "<<info(P).finish<<endl;
        cout<<"Total Menang Piala Dunia: "<<info(P).totJuara<<endl;
        P = next(P);
    }
    
}