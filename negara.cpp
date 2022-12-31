#include "mll.h"

// Procedure to create empty list
void createListNegara(listNegara &LN){
    first(LN) = NULL;
    last(LN) = NULL;
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
    prev(P) = NULL;
    return P;
}


//
void insertFirstNegara(listNegara &LN, adrNegara P){
    if (first(LN) != NULL && last(LN) != NULL){
        next(P) = first(LN);
        prev(first(LN)) = P;
        first(LN) = P;
    } else {
        first(LN) = P;
        last(LN) = P;
    }

}

//
void insertLastNegara(listNegara &LN, adrNegara P){
    prev(P) = last(LN);
    next(last(LN)) = P;
    last(LN) = P;
}

//
void insertAfterNegara(listNegara &LN, adrNegara Prec, adrNegara P){
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;

}

void deletefirst(listNegara &LN, adrNegara P){
    P = first(LN);
    if(first(LN) != last(LN)) {
        first(LN) = next(P);
        prev(first(LN)) = NULL;
    }else{
        first(LN) = NULL;
        last(LN) = NULL;
        }
    }
void deletelast(listNegara &LN, adrNegara P){
    P = last(LN);
    last(LN) = prev(last(LN));
    prev(P) = NULL;
    next(last(LN)) = NULL;
}
void deleteafter(listNegara &LN, adrNegara Prec, adrNegara P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}




// FIXME Input negara pada list negara sesusai dengan urutan mereka di piala dunia
void insertAscNegara(listNegara &LN, adrNegara P){
    adrNegara Q = first(LN);
    if (first(LN) == NULL){
        first(LN) = P;
        next(P) = NULL;
    } else if (info(P).finish < info(Q).finish) {
        insertFirstNegara(LN, P);
    } else {
        while (info(P).finish > info(Q).finish){
            Q = next(Q);
        }
        insertAfterNegara(LN, Q, P);

    }

}

adrNegara findNegara(listNegara LN, string namaNegara){
    adrNegara P = first(LN);
    adrNegara found = NULL;
    while (P != NULL && found == NULL){
        if (info(P).namaNegara == namaNegara){
            found = P;
        }
        P = next(P);
    }
    return found;


}

void inputNegara(listNegara &LN, adrNegara P, infotypeNegara X){
    X.namaNegara = "Argentina";
    X.konfiderasi = "CONMEBOL";
    X.finish = 1;
    X.totJuara = 3;
    P = newNegara(X);
    insertFirstNegara(LN, P);
    X.namaNegara = "France";
    X.konfiderasi = "UEFA";
    X.finish = 2;
    X.totJuara = 2;
    P = newNegara(X);
    insertFirstNegara(LN, P);
    X.namaNegara = "Croatia";
    X.konfiderasi = "UEFA";
    X.finish = 3;
    X.totJuara = 0;
    P = newNegara(X);
    insertFirstNegara(LN, P);
    X.namaNegara = "Morocco";
    X.konfiderasi = "CONCACAF";
    X.finish = 4;
    X.totJuara = 0;
    P = newNegara(X);
    insertFirstNegara(LN, P);
    cout<<"Negara berhasil diinputkan ke dalam list!"<<endl<<endl;
}

//
void printNegara(listNegara LN){
    if (first(LN) == NULL){
        cout<<"List Negara Kosong!"<<endl<<endl;
    } else {
        cout<<"========================== List Negara ==========================\nPosisi \t Negara \t Konfiderasi \t Total Menang Piala Dunia"<<endl;
        adrNegara P = first(LN);
        while (P != NULL){
            cout<<setw(9)<<left<<info(P).finish<<setw(16)<<info(P).namaNegara<<setw(27)<<info(P).konfiderasi<<info(P).totJuara<<endl;
            P = next(P);
        }
    cout<<endl;
    }
}
