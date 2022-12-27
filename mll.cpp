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
    } else {
        next(P) = first(LN);
        first(LN) = P;
    }

}

//
void insertLastNegara(listNegara &LN, adrNegara P){


}

//
void insertAfterNegara(listNegara &LN, adrNegara Prec, adrNegara P){


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

adrPemain newPemain(infotypePemain X){
    adrPemain Q = new elmPemain;
    info(Q).no = X.no;
    info(Q).posisi = X.posisi;
    info(Q).namaPemain = X.namaPemain;
    info(Q).umur = X.umur;
    info(Q).klub = X.klub;
    info(Q).totGoal = X.totGoal;
    return Q;

}

void insertPemain(listNegara &LN, adrPemain P, string namaNegara){
    adrNegara Q = findNegara(LN, namaNegara);
    if (Q == NULL){
        cout << "Negara yang dicari tidak ada!";
    } else {
        if (nextChild(Q) == NULL){
            nextChild(Q) = P;
        } else {
            adrPemain R = nextChild(Q);
            next(P) = R;
            P = R;
        }
    }
}


//
float avrAge(listNegara LN, string namaNegara){
    int totAge = 0;
    int N;

    adrNegara P = findNegara(LN, namaNegara);
    if (P == NULL){
        cout << "Negara yang dicari tidak ada dalam list";
    } else {
        if (nextChild(P) != NULL){
            adrPemain Q = nextChild(P);
            while (Q != NULL){
                totAge = totAge + info(Q).umur;
                N++;
                Q = next(Q);
            }
        }
    
    }

    return (float(totAge) / float(N));
}

// 
void printNegara(listNegara LN){
    cout<<"========================== List Negara ==========================\nPosisi \t Negara \t Konfiderasi \t Total Menang Piala Dunia"<<endl;
    adrNegara P = first(LN);
    while (P != NULL){
        cout<<setw(9)<<left<<info(P).finish<<setw(16)<<info(P).namaNegara<<setw(27)<<info(P).konfiderasi<<info(P).totJuara<<endl;
        P = next(P);
    }
    cout<<endl;
    
}

void printListPemain(listNegara LN){
    adrNegara P = first(LN);
    if (P == NULL){
        cout<<"List Kosong!"<<endl;
    } else {
        cout<<"========================== List Pemain =========================="<<endl;
        while (P != NULL){
            cout<<info(P).namaNegara<<endl;
            if (nextChild(P) == NULL){
                cout << "Tidak ada pemain."<<endl;
            } else {
                cout<<"No\tPosisi\tNama Pemain\tKlub\tUmur\tGoal"<<endl;
                adrPemain Q = nextChild(P);
                while (Q != NULL){
                    cout<<info(Q).no<<"\t"<<info(Q).posisi<<"\t"<<info(Q).namaPemain<<"\t"<<info(Q).klub<<"\t"<<info(Q).umur<<"\t"<<info(Q).totGoal<<endl;
                    Q = next(Q);
                }
            }
            P = next(P);
            cout<<endl;
        }
    }
}