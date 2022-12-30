#include "mll.h"

int main(){
    //Deklarasi Variabel
    listNegara LN;
    infotypeNegara xN;
    infotypePemain xP;
    adrNegara pNegara;
    adrPemain pPemain;
    int choice;
    string namaNegara;

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
                    inputNegara(LN, pNegara, xN);
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
                } else if (choice == 3){
                    youngestOldestPlayer(LN);
                }
                menuShow();
                cout<<"Pilih no: ";
                cin>>choice;
            }
            break;
        case 3:
            cout<<"Input negara yang dicari: ";
            cin>>namaNegara;
            while (namaNegara != "0"){
                avrAge(LN, namaNegara);
                cout<<"\nInput negara yang dicari: ";
                cin>>namaNegara;
            }
            break;
        case 4:
            cout<<"Fungsi belum dibuat\n";
            break;
        default:
            cout<<"Pastikan pilihan menu sudah sesuai dengan list\n";
            break;
        }
        mainMenu();
        cout << "Pilih no: ";
        cin >> choice;
    }
    cout<<"Anda keluar dari menu."<<endl;



    return 0;
}
