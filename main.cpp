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
    cout<<"Choice: ";
    cin>>choice;
    while (choice != 0){
        switch(choice){
        case 1:
            inputNegara(LN, pNegara, xN);
            break;
        case 2:
            inputPemain(LN, pPemain, xP, 11);
            break;
        case 3:
            menuShow();
            cout<<"Choice: ";
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
                cout<<"Choice: ";
                cin>>choice;
            }
            break;
        case 4:
            cout<<"Input country: ";
            cin>>namaNegara;
            while (namaNegara != "0"){
                avrAge(LN, namaNegara);
                cout<<"\nInput country: ";
                cin>>namaNegara;
            }
            break;
        case 5:
            deleteFirstNegara(LN, pNegara);
            cout<<info(pNegara).namaNegara<<" has been removed from the list"<<endl;
            break;
        case 6:
            cout<<"Input country: ";
            cin>>namaNegara;
            deletePemain(LN, namaNegara);
            cout<<"The player data from "<<namaNegara<<" has been deleted"<<endl;
            break;
        default:
            cout<<"Make sure you're inputing the correct menu option\n";
            break;
        }
        mainMenu();
        cout << "Choice: ";
        cin >> choice;
    }
    cout<<"You have exited the main menu."<<endl;

    return 0;
}
