#include "mll.h"

adrPemain newPemain(infotypePemain X){
    adrPemain Q = new elmPemain;
    info(Q).no = X.no;
    info(Q).posisi = X.posisi;
    info(Q).namaPemain = X.namaPemain;
    info(Q).umur = X.umur;
    info(Q).klub = X.klub;
    info(Q).totGoal = X.totGoal;
    next(Q) = NULL;
    return Q;

}
void insertPemainFirst(listNegara &LN, adrPemain P, adrNegara Q, adrPemain R){
    nextChild(Q) = P;
    next(P) = R;
}

void insertPemainLast(listNegara &LN, adrPemain P, adrNegara Q, adrPemain R){
    while (next(R) != NULL){
    R = next(R);
    }
    next(R) = P;
}

void insertPemain(listNegara &LN, adrPemain P, string namaNegara){
    adrNegara Q = findNegara(LN, namaNegara);
    adrPemain prev;
    if (Q == NULL){
        cout << "Negara yang dicari tidak ada!"<<endl<<endl;
    } else {
        adrPemain R = nextChild(Q);
        if (nextChild(Q) == NULL){
            nextChild(Q) = P;
        } else if (info(P).posisi == "GK") { //Insert first if Goal Keeper
            insertPemainFirst(LN, P, Q, R);
        } else if (info(P).posisi == "FWD") { //Insert last if forward
            insertPemainLast(LN, P, Q, R);
        } else if  (info(P).posisi == "DEF"){ //Insert after defense
            if (info(R).posisi != "GK"){
                insertPemainFirst(LN, P, Q, R);
            } else if (next(R) == NULL) {
                insertPemainLast(LN, P, Q, R);
            } else {
                while ((info(R).posisi == "GK") && next(R) != NULL){
                    prev = R;
                    R = next(R);
                }
                next(P) = next(prev);
                next(prev) = P;
            }

        } else if (info(P).posisi == "MID") { //Insert after mid
            if (info(R).posisi != "GK" && info(next(R)).posisi != "DEF"){
                insertPemainFirst(LN, P, Q, R);
            } else if (next(R) == NULL) {
                insertPemainLast(LN, P, Q, R);
            } else {
                while ((info(R).posisi == "GK" || info(R).posisi == "DEF") && next(R) != NULL){
                    prev = R;
                    R = next(R);
                }
                next(P) = next(prev);
                next(prev) = P;
            }
        }

    }
}

void deletePemain(listNegara &LN, string namaNegara){
    adrNegara P = findNegara(LN, namaNegara);
    if (P != NULL){
        nextChild(P) = NULL;
    } else {
        cout<<"Country is not found in the list.";
    }
}


void inputPemain(listNegara &LN, adrPemain Q, infotypePemain xP, int N){
    string negara;
    cout<<"Where is the player from? ";
    cin>>negara;
    while (negara != "0"){
        if (findNegara(LN, negara) == NULL){
            cout<<"No country in the list."<<endl<<endl;
        } else {
            for (int i = 1; i <= N; i++){
                cout<<"Input No Pemain: ";
                cin>>xP.no;
                cout<<"Input Posisi Pemain: ";
                cin>>xP.posisi;
                cin.ignore();
                cout<<"Input Nama Pemain: ";
                getline(cin, xP.namaPemain);
                cout<<"Input Klub Pemain: ";
                getline(cin, xP.klub);
                cout<<"Input Umur Pemain: ";
                cin>>xP.umur;
                cout<<"Input Gol Pemain: ";
                cin>>xP.totGoal;
                Q = newPemain(xP);
                insertPemain(LN, Q, negara);
            }
            cout<<"Input player is successful!"<<endl<<endl;
        }

        cout<<"Where is the player from? ";
        cin>>negara;
    }
}

void printListPemain(listNegara LN){
    if (first(LN) == NULL){
        cout<<"Player list is empty!"<<endl<<endl;
    } else {
        adrNegara P = first(LN);
        cout<<"========================== Player List =========================="<<endl;
        while (P != NULL){
            cout<<info(P).namaNegara<<endl;
            if (nextChild(P) == NULL){
                cout << "There is no player in this country."<<endl;
            } else {
                cout<<"No\tNo\tPlayer Name\t\tClub\t\t    Age   Goal"<<endl;
                adrPemain Q = nextChild(P);
                while (Q != NULL){
                    cout<<setw(8)<<left<<info(Q).no<<setw(8)<<info(Q).posisi<<setw(24)<<info(Q).namaPemain<<setw(20)<<info(Q).klub<<setw(7)<<info(Q).umur<<setw(8)<<info(Q).totGoal<<endl;
                    Q = next(Q);
                }
            }
            P = next(P);
            cout<<endl;
        }
    }
}
