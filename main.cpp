#include "mll.h"

int main(){
    //Deklarasi Variabel
    listNegara LN;
    infotypeNegara xN;
    infotypePemain xP;
    adrNegara pNegara;
    adrPemain pPemain;
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
    xN.namaNegara = "Argentina";
    xN.konfiderasi = "CONMEBOL";
    xN.finish = 1;
    xN.totJuara = 3;
    pNegara = newNegara(xN);
    insertFirstNegara(LN, pNegara);
    xN.namaNegara = "Perancis";
    xN.konfiderasi = "UEFA";
    xN.finish = 2;
    xN.totJuara = 2;
    pNegara = newNegara(xN);
    insertFirstNegara(LN, pNegara);
    xN.namaNegara = "Kroasia";
    xN.konfiderasi = "UEFA";
    xN.finish = 3;
    xN.totJuara = 0;
    pNegara = newNegara(xN);
    insertFirstNegara(LN, pNegara);
    xN.namaNegara = "Maroco";
    xN.konfiderasi = "CONCACAF";
    xN.finish = 4;
    xN.totJuara = 0;
    pNegara = newNegara(xN);
    insertFirstNegara(LN, pNegara);
    
    printNegara(LN);

    // Manual Input Pemain
    xP.no = 10;
    xP.posisi = "FWD";
    xP.namaPemain = "Lionel Messi";
    xP.umur = 35;
    xP.klub = "PSG";
    xP.totGoal = 7;
    pPemain = newPemain(xP);
    insertPemain(LN, pPemain, "Argentina");

    
    printListPemain(LN);

    return 0;
}