#include "stat.hh"

void Statystyka(int good, int bad){
    double Proc;
    Proc = ((double)good/((double)good+(double)bad))*100;
    cout << "Ilosc dobrych  odpowiedzi: " << good << endl;
    cout << "Ilosc blednych odpowiedzi: " << bad << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi:    " << Proc << "%" << endl;
}