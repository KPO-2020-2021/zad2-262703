#include <iostream>
#include "BazaTestu.hh"
#include "stat.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona LiczbaZespolonaWe;
  int good=0,bad=0;
  try{
    while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {

      cout << ":? Podaj wynik operacji: " << WyrZ_PytanieTestowe;
      cout << "   Twoja odpowiedz:  ";
      cin >> LiczbaZespolonaWe; //wprowadzenie odpowiedzi
      while (cin.fail()){
        cin.clear();
        cerr << "Blad formatu liczby zespolonej"<<endl;
        cout << "   Twoja odpowiedz:  ";
        cin >> LiczbaZespolonaWe; 
      } 
      LiczbaZespolonaWe.arg(); //argument liczby zespolonej
      LZespolona Wynik;
      Wynik = Oblicz(WyrZ_PytanieTestowe);//obliczenie poprawnego wyniku
      if (Wynik == LiczbaZespolonaWe){//modul dla statystyki
        cout << ":) Odpowiedz poprawna" << endl;
        ++good;
      }
      else {
        cout << ":( Blad. Prawidlowym wynikiem jest: " << Wynik;
        ++bad;
      }
     
    }
  }
  catch (runtime_error& e) {
    // prints that exception has occurred 
    // calls the what function 
    // using runtime_error object 
    cout << "Exception occurred" << endl 
    << e.what(); 
  }


  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  
  Statystyka(good,bad);
}
