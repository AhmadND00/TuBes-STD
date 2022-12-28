#include "mll.h"

int main(){
    //Deklarasi Variabel
    listNegara LN;
    infotypeNegara xN;
    infotypePemain xP;
    adrNegara pNegara;
    adrPemain pPemain;
    int choice;

    //Create Empty List Negara
    createListNegara(LN);
    mainMenu();
    cout<<"Pilih no: ";
    cin>>choice;
    while (choice != 0){
        switch(choice){
        case 1:
            menuInsert();
            cout<<"Pilih no: ";
            cin>>choice;
            while (choice != 0){
                if (choice == 1){
                    xN.namaNegara = "Argentina";
                    xN.konfiderasi = "CONMEBOL";
                    xN.finish = 1;
                    xN.totJuara = 3;
                    pNegara = newNegara(xN);
                    insertFirstNegara(LN, pNegara);
                    xN.namaNegara = "France";
                    xN.konfiderasi = "UEFA";
                    xN.finish = 2;
                    xN.totJuara = 2;
                    pNegara = newNegara(xN);
                    insertFirstNegara(LN, pNegara);
                    xN.namaNegara = "Croatia";
                    xN.konfiderasi = "UEFA";
                    xN.finish = 3;
                    xN.totJuara = 0;
                    pNegara = newNegara(xN);
                    insertFirstNegara(LN, pNegara);
                    xN.namaNegara = "Morocco";
                    xN.konfiderasi = "CONCACAF";
                    xN.finish = 4;
                    xN.totJuara = 0;
                    pNegara = newNegara(xN);
                    insertFirstNegara(LN, pNegara);
                    cout<<"Negara berhasil diinputkan ke dalam list!"<<endl<<endl;
                } else if (choice == 2){
                        inputPemain(LN, pPemain, xP, 11);
                }
                menuInsert();
                cout<<"Pilih no: ";
                cin>>choice;
            }
            break;
        case 2:
            menuShow();
            cout<<"Pilih no: ";
            cin>>choice;
            while (choice != 0){
                if (choice == 1){
                    printNegara(LN);
                } else if (choice == 2){
                    printListPemain(LN);
                }
                menuShow();
                cout<<"Pilih no: ";
                cin>>choice;
            }
            break;
        case 3:
            cout<<"Fungsi belum dibuat";
            break;
        case 4:
            cout<<"Fungsi belum dibuat";
            break;
        default:
            cout<<"\nPastikan pilihan menu sudah sesuai dengan list"<<endl;
            cout<<endl;
            break;
        }
        mainMenu();
        cout << "Pilih no: ";
        cin >> choice;
    }



    return 0;
}
