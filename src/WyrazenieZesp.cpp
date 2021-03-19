#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

LZespolona Oblicz(WyrazenieZesp WyrZ){
LZespolona Wynik;
if (WyrZ.Op == Op_Dodaj){Wynik = WyrZ.Arg1 + WyrZ.Arg2;}
if (WyrZ.Op == Op_Odejmij){Wynik = WyrZ.Arg1 - WyrZ.Arg2;}
if (WyrZ.Op == Op_Mnoz){Wynik = WyrZ.Arg1 * WyrZ.Arg2;}
if (WyrZ.Op == Op_Dziel){Wynik = WyrZ.Arg1 / WyrZ.Arg2;}
return Wynik;
}
void Wyswietl(LZespolona Wynik){
    cout << "Wynik:" << endl;
    if (Wynik.im > 0) {
       cout << "(" << Wynik.re << "+" << Wynik.im << "i)" << endl;
    }
    if (Wynik.im < 0) {
    cout << "(" << Wynik.re << Wynik.im << "i)" << endl;
    }
}

ostream & operator << (ostream & StrmWy, WyrazenieZesp WyrZ)
{
    char a;
    if (WyrZ.Op == Op_Dodaj){a='+';}
    if (WyrZ.Op == Op_Odejmij){a='-';}
    if (WyrZ.Op == Op_Dziel){a='/';}
    if (WyrZ.Op == Op_Mnoz){a='*';}
    return StrmWy<<"("<<WyrZ.Arg1.re<<showpos<<WyrZ.Arg1.im<<noshowpos<<"i) "<<a<<" ("<<WyrZ.Arg2.re<<showpos<<WyrZ.Arg2.im<<noshowpos<<"i) ="<<endl;
}