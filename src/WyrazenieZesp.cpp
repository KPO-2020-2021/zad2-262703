#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

LZespolona Oblicz(WyrazenieZesp WyrZ){
LZespolona Wynik;
if (WyrZ.Op == Op_Dodaj){WyrZ.Arg1 += WyrZ.Arg2; return WyrZ.Arg1;}
if (WyrZ.Op == Op_Odejmij){Wynik = WyrZ.Arg1 - WyrZ.Arg2;}
if (WyrZ.Op == Op_Mnoz){Wynik = WyrZ.Arg1 * WyrZ.Arg2;}
if (WyrZ.Op == Op_Dziel){WyrZ.Arg1 /= WyrZ.Arg2; return WyrZ.Arg1;}
return Wynik;
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

istream & operator >> (istream & StrmWe, WyrazenieZesp & WyrZ)//wczytywnai liczby zespolonej
{
    char znak;
    StrmWe >> WyrZ.Arg1 >> znak >> WyrZ.Arg2;
    if (StrmWe.fail()) return StrmWe;
    WyrZ.Op = WczytajZnak(znak);
    return StrmWe;
}

Operator WczytajZnak (char znak)
{
    Operator Oper;
    if (znak == '+'){Oper = Op_Dodaj;}
    if (znak == '-'){Oper = Op_Odejmij;}
    if (znak == '*'){Oper = Op_Mnoz;}
    if (znak == '/'){Oper = Op_Dziel;}
    return Oper;
}