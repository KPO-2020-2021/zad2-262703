#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona  operator + (LZespolona  Skl2) const;
  LZespolona  operator - (LZespolona  Skl2) const;
  LZespolona  operator * (LZespolona  Skl2) const;
  LZespolona  operator / (LZespolona  Skl2) const;
  LZespolona  operator / (double liczba) const;
  void arg();
  void Sprzezenie();
  double modul ();
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

bool operator == (LZespolona Wynik, LZespolona PoprWynik);
LZespolona operator /= (LZespolona &Skl1,LZespolona const &Skl2);
LZespolona operator += (LZespolona &Skl1,LZespolona const &Skl2);
istream & operator >> (istream & StrmWe, LZespolona& LiczZ);
ostream & operator << (ostream & StrmWy, LZespolona LiczZesp);
#endif
