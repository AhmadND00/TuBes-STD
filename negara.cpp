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
    }
}

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

void deleteFirstNegara(listNegara &LN, adrNegara &P){
    P = first(LN);
    if(first(LN) != last(LN)) {
        first(LN) = next(P);
        prev(first(LN)) = NULL;
    }else{
        first(LN) = NULL;
        last(LN) = NULL;
        }
    }

void deleteLastNegara(listNegara &LN, adrNegara &P){
    P = last(LN);
    last(LN) = prev(last(LN));
    prev(P) = NULL;
    next(last(LN)) = NULL;
}

void deleteAterNegara(listNegara &LN, adrNegara Prec, adrNegara &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}


void insertAscNegara(listNegara &LN, adrNegara P){
    adrNegara Q = first(LN);
    adrNegara R = last(LN);
    adrNegara Prec;
    if (first(LN) == NULL && last(LN) == NULL){
        first(LN) = P;
        last(LN) = P;
    } else if (info(P).finish < info(Q).finish) {
        insertFirstNegara(LN, P);
    } else if (info(P).finish > info(R).finish){
        insertLastNegara(LN, P);
    } else {
        while ((info(P).finish > info(Q).finish) && (next(Q) != NULL)){
            Prec = Q;
            Q = next(Q);
        }
        insertAfterNegara(LN, Prec, P);
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
    X.namaNegara = "France";
    X.konfiderasi = "UEFA";
    X.finish = 2;
    X.totJuara = 2;
    P = newNegara(X);
    insertAscNegara(LN, P);
    X.namaNegara = "Morocco";
    X.konfiderasi = "CONCACAF";
    X.finish = 4;
    X.totJuara = 0;
    P = newNegara(X);
    insertAscNegara(LN, P);
    X.namaNegara = "Croatia";
    X.konfiderasi = "UEFA";
    X.finish = 3;
    X.totJuara = 0;
    P = newNegara(X);
    insertAscNegara(LN, P);
    X.namaNegara = "Argentina";
    X.konfiderasi = "CONMEBOL";
    X.finish = 1;
    X.totJuara = 3;
    P = newNegara(X);
    insertAscNegara(LN, P);

    cout<<"Country is successfully added to the list!"<<endl<<endl;
}

//
void printNegara(listNegara LN){
    if (first(LN) == NULL && last(LN) == NULL){
        cout<<"Country list is empty!"<<endl<<endl;
    } else {
        cout<<"========================== List Country ==========================\nFinish \t Country \t Confideration \t Total World Cup Win"<<endl;
        adrNegara P = first(LN);
        while (P != NULL){
            cout<<setw(9)<<left<<info(P).finish<<setw(16)<<info(P).namaNegara<<setw(27)<<info(P).konfiderasi<<info(P).totJuara<<endl;
            P = next(P);
        }
    cout<<endl;
    }
}
