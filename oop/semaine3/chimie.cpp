#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/

  double getVolume() const
  {
    return volume;
  }

  double getpH() const
  {
    return pH;
  }

  string getNom() const
  {
    return nom;
  }
  ostream &etiquette(ostream &sortie) const
  {
    sortie << getNom() << " : " << getVolume() << " ml, pH " << getpH();
    return sortie;
  }

  Flacon(string n, double v, double p) : nom(n), volume(v), pH(p){};
};

ostream &operator<<(ostream &sortie, const Flacon &f)
{
  return f.etiquette(sortie);
}
Flacon operator+(const Flacon &f1, const Flacon &f2)
{
  double pow1 = pow(10.0, -f1.getpH());
  double pow2 = pow(10.0, -f2.getpH());

  double num2 = (f2.getVolume() * pow2);
  double num1 = (f1.getVolume() * pow1);
  double num = num1 + num2 ; 
  double den = f1.getVolume() + f2.getVolume();
  double newph = -log10(num / den);
  return Flacon(f1.getNom() + " + " + f2.getNom(), f1.getVolume() + f2.getVolume(), newph);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const &f1, Flacon const &f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique", 800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;
}
