#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re + Skl1.im * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  Wynik.im = (Skl2.re * Skl1.im - Skl1.re * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  return Wynik;
}
istream & operator >> (istream & StrmWe, LZespolona& LiczZ)
{
StrmWe.ignore(1);
StrmWe >> LiczZ.re >> LiczZ.im;
StrmWe.ignore();
return StrmWe;
}
ostream & operator << (ostream & StrmWy, LZespolona LiczZesp)
{
   return StrmWy<<"("<<LiczZesp.re<<showpos<<LiczZesp.im<<noshowpos<<"i) "<<endl;
}
