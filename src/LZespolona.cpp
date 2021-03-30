#include "LZespolona.hh"
#define MIN_DIFF 0.01



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (LZespolona  Skl2) const//opcja dodawania(old version)
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}
LZespolona LZespolona::operator - (LZespolona  Skl2) const//opcja odejmowania
{
  LZespolona  Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}
LZespolona LZespolona::operator * (LZespolona  Skl2) const//opcja mnozenia
{
  LZespolona  Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->re * Skl2.im + this->im * Skl2.re;
  return Wynik;
}
LZespolona  LZespolona::operator / (LZespolona  Skl2) const//opcja dzielenia(znalazlem inne formule)
{
  LZespolona  Wynik;

  Wynik.re = (this->re * Skl2.re + this->im * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  Wynik.im = (Skl2.re * this->im - this->re * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  return Wynik;
}
istream & operator >> (istream & StrmWe, LZespolona& LiczZ)//wczytywnai liczby zespolonej
{
char Nawotw, ZnakI, NawZam;
StrmWe >> Nawotw >> LiczZ.re >> LiczZ.im >> ZnakI >> NawZam;
if (StrmWe.fail()) return StrmWe;
if (Nawotw != '(' || ZnakI != 'i' || NawZam != ')') {
  StrmWe.setstate(ios::failbit);
}
return StrmWe;
}
ostream & operator << (ostream & StrmWy, LZespolona LiczZesp)
{
   return StrmWy<<"("<<LiczZesp.re<<showpos<<LiczZesp.im<<noshowpos<<"i) "<<endl;
}
void LZespolona::arg(){
  double fi;
  if (this->re != 0) 
  {
    if (this->re > 0) {fi = atan(this->im/this->re);}
    else {fi = atan(this->im/this->re) + M_PI;}
  }
  else 
  {
    if (this->im > 0){fi = 0.5 * M_PI;}
    if (this->im < 0){fi = -0.5 * M_PI;}
    if (this->im == 0){cout << "Argument jest nieokreslony."<< endl;}
  }
  cout << "   Argument wprowadzonej liczby jest rowny: " << fi << " radian." << endl;
}
LZespolona operator +=(LZespolona &Skl1, LZespolona const &Skl2)
{
Skl1.re += Skl2.re;
Skl1.im += Skl2.im;
return Skl1;  
}
LZespolona operator /= (LZespolona &Skl1, LZespolona const &Skl2)
{
double x;
x = (Skl1.re * Skl2.re + Skl1.im * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
Skl1.im = (Skl2.re * Skl1.im - Skl1.re * Skl2.im) / (Skl2.re * Skl2.re + Skl2.im * Skl2.im);
Skl1.re = x;
return Skl1;  
}
bool operator == (LZespolona Wynik, LZespolona PoprWynik)
{
  if ((abs(Wynik.re - PoprWynik.re) <= MIN_DIFF) && (abs(Wynik.im - PoprWynik.im) <= MIN_DIFF))
  {
    return true;
  }
  else 
  {
    return false;
  }
}
void LZespolona::Sprzezenie()
{
this->im = - this->im;
}
double LZespolona::modul()
{
  double z;
  z = sqrt(this->im * this->im + this->re * this->re);
  return z;
}
LZespolona LZespolona::operator / (double liczba) const
{
  if (liczba == 0){
    throw std::runtime_error("Math error: Attemted to divide by zero\n");
  }
  LZespolona Wynik;
  Wynik.re = this->re / liczba;
  Wynik.im = this->im / liczba;
  return Wynik;
}
