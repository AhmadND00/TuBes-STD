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
        cout << "Negara yang dicari tidak ada!"<<endl<<endl;
    } else {
        if (nextChild(Q) == NULL){
            nextChild(Q) = P;
        } else if ((info(P).posisi == "GK") && (nextChild(Q) != NULL)) { //Insert First if Goal Keeper
            adrPemain R = nextChild(Q);
            nextChild(Q) = P;
            next(P) = R;
        } else {
            adrPemain R = nextChild(Q);
            while (next(R) != NULL){
                R = next(R);
            }
            next(R) = P;
        }
    }
}


//
float avrAge(listNegara LN, string namaNegara){
    int totAge = 0;
    int N;

    adrNegara P = findNegara(LN, namaNegara);
    if (P == NULL){
        cout << "Negara yang dicari tidak ada dalam list"<<endl<<endl;
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
    if (first(LN) == NULL){
        cout<<"List Negara Kosong!"<<endl<<endl;
    } else {
        cout<<"========================== List Negara ==========================\nPosisi \t Negara \t Konfiderasi \t Total Menang Piala Dunia"<<endl;
        adrNegara P = first(LN);
        while (P != NULL){
            cout<<setw(9)<<left<<info(P).finish<<setw(16)<<info(P).namaNegara<<setw(27)<<info(P).konfiderasi<<info(P).totJuara<<endl;
            P = next(P);
        }
    cout<<endl<<endl;
    }
}

void printListPemain(listNegara LN){
    if (first(LN) == NULL){
        cout<<"List Pemain Kosong!"<<endl<<endl;
    } else {
        adrNegara P = first(LN);
        cout<<"========================== List Pemain =========================="<<endl;
        while (P != NULL){
            cout<<info(P).namaNegara<<endl;
            if (nextChild(P) == NULL){
                cout << "Tidak ada pemain."<<endl;
            } else {
                cout<<"No\tPosisi\tNama Pemain\t\tKlub\t\t Umur\tGoal"<<endl;
                adrPemain Q = nextChild(P);
                while (Q != NULL){
                    cout<<setw(8)<<left<<info(Q).no<<setw(8)<<info(Q).posisi<<setw(24)<<info(Q).namaPemain<<setw(17)<<info(Q).klub<<setw(8)<<info(Q).umur<<setw(8)<<info(Q).totGoal<<endl;
                    Q = next(Q);
                }
            }
            P = next(P);
            cout<<endl;
        }
    }
}


void inputPemain(listNegara &LN, adrPemain Q, infotypePemain xP, int N){
    string negara;
    cout<<"Negara dari Pemain adalah? ";
    cin>>negara;
    while (negara != "0"){
        if (findNegara(LN, negara) == NULL){
            cout<<"Negara tidak terdapat dalam list."<<endl<<endl;
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
            cout<<"Input pemain berhasil!"<<endl<<endl;
        }

        cout<<"Negara dari Pemain adalah? ";
        cin>>negara;

    }



}


void mainMenu(){
    cout<<"\n=================== MAIN MENU ==================="<<endl;
    cout<<"1. Insert Data"<<endl;
    cout<<"2. Show List"<<endl;
    cout<<"3. Find..."<<endl;
    cout<<"4. Delete..."<<endl;
    cout<<"0. Exit Menu"<<endl;
    cout<<"================================================="<<endl;
}

void menuInsert(){
    cout<<"\n================== INSERT MENU =================="<<endl;
    cout<<"1. Insert Negara"<<endl;
    cout<<"2. Insert Pemain"<<endl;
    cout<<"0. Return to Main Menu"<<endl;
    cout<<"================================================="<<endl;
}

void menuShow(){
    cout<<"\n=================== SHOW MENU ==================="<<endl;
    cout<<"1. Show Negara"<<endl;
    cout<<"2. Show Info Pemain"<<endl;
    cout<<"0. Return to Main Menu"<<endl;
    cout<<"================================================="<<endl;
}
