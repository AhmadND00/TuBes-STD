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

void insertPemain(listNegara &LN, adrPemain P, string namaNegara){
    adrNegara Q = findNegara(LN, namaNegara);
    if (Q == NULL){
        cout << "Negara yang dicari tidak ada!"<<endl<<endl;
    } else {
        if (nextChild(Q) == NULL){
            nextChild(Q) = P;
        } else { //Insert First if Goal Keeper
            adrPemain R = nextChild(Q);
            nextChild(Q) = P;
            next(P) = R;
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
                cout<<"No\tPosisi\tNama Pemain\t\tKlub\t\t    Umur    Goal"<<endl;
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
