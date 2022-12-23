#include "mll.h"

int main(){
    //Deklarasi Variabel
    listNegara LN;
    infotypeNegara X;
    adrNegara pNegara;

    //Create Empty List Negara
    createListNegara(LN);


    // Only for checking (for now) if input worked
    cin>>X.namaNegara;
    cin>>X.konfiderasi;
    cin>>X.finish;
    cin>>X.totJuara;
    pNegara = newNegara(X);
    insertFirstNegara(LN, pNegara);
    printNegara(LN);


    return 0;
}