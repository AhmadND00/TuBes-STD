#include "mll.h"

int main(){
    //Deklarasi Variabel
    listNegara LN;
    infotypeNegara X;
    adrNegara pNegara;
    int N;

    //Create Empty List Negara
    createListNegara(LN);


    /* -------------- Input (Draft Version) -------------- */

    // Input through looping
    /*cout << "Input banyak negara: ";
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin>>X.namaNegara;
        cin>>X.konfiderasi;
        cin>>X.finish;
        cin>>X.totJuara;
        pNegara = newNegara(X);
        insertFirstNegara(LN, pNegara);
    }
    */
    // Manual Input
    X.namaNegara = "Argentina";
    X.konfiderasi = "CONMEBOL";
    X.finish = 1;
    X.totJuara = 3;
    pNegara = newNegara(X);
    insertFirstNegara(LN, pNegara);
    X.namaNegara = "Perancis";
    X.konfiderasi = "UEFA   ";
    X.finish = 2;
    X.totJuara = 2;
    pNegara = newNegara(X);
    insertFirstNegara(LN, pNegara);
    X.namaNegara = "Kroasia";
    X.konfiderasi = "UEFA   ";
    X.finish = 3;
    X.totJuara = 0;
    pNegara = newNegara(X);
    insertFirstNegara(LN, pNegara);
    X.namaNegara = "Maroco ";
    X.konfiderasi = "CONCACAF";
    X.finish = 4;
    X.totJuara = 0;
    pNegara = newNegara(X);
    insertFirstNegara(LN, pNegara);

    
    printNegara(LN);


    return 0;
}