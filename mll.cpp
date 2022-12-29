#include "mll.h"
void youngestOldestPlayer(listNegara LN){
    adrPemain tempYoungest, tempOldest, youngest, oldest;
    if (first(LN) == NULL){
        cout<<"List kosong! Mohon untuk input data terlebih dahulu!"<<endl;
    } else {
        adrNegara P = first(LN);
        while (P != NULL){
            if (nextChild(P) == NULL){
                cout<<"Data pemain di negara "<<info(P).namaNegara<<" kosong!"<<endl;
            } else {
                adrPemain Q
                 = nextChild(P);
                tempOldest = nextChild(P);
                tempYoungest = nextChild(P);
                while (Q != NULL){
                    if (info(Q).umur > info(tempOldest).umur){
                        tempOldest = Q;
                    } else if (info(Q).umur < info(tempYoungest).umur) {
                        tempYoungest = Q;
                    }
                    Q = next(Q);

                }
                cout<<"Pemain paling muda di "<<info(P).namaNegara<<" adalah: "<<endl<<info(tempYoungest).namaPemain<<", Umur: "<<info(tempYoungest).umur<<endl;
                cout<<"Pemain paling tua di "<<info(P).namaNegara<<" adalah: "<<endl<<info(tempOldest).namaPemain<<", Umur: "<<info(tempOldest).umur<<endl;
            }
            cout<<endl;
            P = next(P);
        }

    }
}


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
