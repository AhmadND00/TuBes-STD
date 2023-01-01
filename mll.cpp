#include "mll.h"

void youngestOldestPlayer(listNegara LN){
    adrPemain tempYoungest, tempOldest, youngest, oldest;
    if (first(LN) == NULL){
        cout<<"List is empty! Please insert the data first!"<<endl;
    } else {
        adrNegara P = first(LN);
        oldest = nextChild(P);
        youngest = nextChild(P);
        while (P != NULL){
            if (nextChild(P) == NULL){
                cout<<"Player data in "<<info(P).namaNegara<<" is empty!"<<endl;
            } else {
                adrPemain Q = nextChild(P);
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
                cout<<"Youngest player in "<<info(P).namaNegara<<" is: "<<endl<<info(tempYoungest).namaPemain<<", Age: "<<info(tempYoungest).umur<<endl;
                cout<<"Oldest playerin "<<info(P).namaNegara<<" is: "<<endl<<info(tempOldest).namaPemain<<", Age: "<<info(tempOldest).umur<<endl;
            }
            P = next(P);
            if (info(youngest).umur > info(tempYoungest).umur){
                youngest = tempYoungest;
            }
            if (info(oldest).umur < info(tempOldest).umur){
                oldest = tempOldest;
            }

            cout<<endl;

        }
        cout<<"The youngest player in top 4 world cup is: "<<endl<<info(youngest).namaPemain<<", Age: "<<info(youngest).umur<<endl;
        cout<<"The oldest player in top 4 world cup is: "<<endl<<info(oldest).namaPemain<<", Age: "<<info(oldest).umur<<endl;

    }
}


void avrAge(listNegara LN, string namaNegara){
    int totAge, N = 0;
    float average;
    adrNegara P = findNegara(LN, namaNegara);
    if (P == NULL){
        cout << "The country isn't on the list!"<<endl;
    } else if (nextChild(P) == NULL){
        cout << "There's no player data in the country list!"<<endl;
    } else {
        if (nextChild(P) != NULL){
            adrPemain Q = nextChild(P);
            while (Q != NULL){
                totAge = totAge + info(Q).umur;
                N++;
                Q = next(Q);
            }
        }
        average = (float(totAge) / float(N));
        cout<<"The average age of player in "<<namaNegara<<" is "<<average<<" years old "<<endl;

    }
}



void mainMenu(){
    cout<<"\n============= WORLD CUP MAIN MENU =============="<<endl;
    cout<<"1. Insert Country"<<endl;
    cout<<"2. Insert Player"<<endl;
    cout<<"3. Show List"<<endl;
    cout<<"4. Find Average Age of the Player"<<endl;
    cout<<"5. Remove a Country"<<endl;
    cout<<"6. Remove Players"<<endl;
    cout<<"0. Exit Menu"<<endl;
    cout<<"================================================="<<endl;
}

void menuInsert(){
    cout<<"\n================== INSERT MENU =================="<<endl;
    cout<<"1. Insert Country"<<endl;
    cout<<"2. Insert Player"<<endl;
    cout<<"0. Return to Main Menu"<<endl;
    cout<<"================================================="<<endl;
}

void menuShow(){
    cout<<"\n=================== SHOW MENU ==================="<<endl;
    cout<<"1. Show List of Country"<<endl;
    cout<<"2. Show the Player Information"<<endl;
    cout<<"3. Show the Youngest and Oldest Player"<<endl;
    cout<<"0. Return to Main Menu"<<endl;
    cout<<"================================================="<<endl;
}

void menuDelete(){
    cout<<"\n================== DELETE MENU =================="<<endl;
    cout<<"1. Delete the first country from the list"<<endl;
    cout<<"0. Return to Main Menu"<<endl;
    cout<<"================================================="<<endl;
}


