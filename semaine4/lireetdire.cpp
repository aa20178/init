#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int &nombre, int chiffre)
{
  nombre = (nombre * 10) + chiffre;
}

void dire_chiffre(int &nombre, int repetitions_chiffre, int chiffre)
{

  ajouter_chiffre_droit(nombre, repetitions_chiffre);
  ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre)
{
  int chiffre_gauche(0), chiffre_gauche_while(0), repetitions(1), resultat(0);
  chiffre_gauche = separer_chiffre_gauche(nombre); 

  while (nombre != 0)
  {
    chiffre_gauche_while = separer_chiffre_gauche(nombre);

    if (chiffre_gauche == chiffre_gauche_while)
    {
      ++repetitions;
      
    }
    else
    {
      dire_chiffre(resultat, repetitions, chiffre_gauche);
      repetitions=1;
      chiffre_gauche = chiffre_gauche_while;
    }
  }
  if (nombre == 0)
  {
    dire_chiffre(resultat, repetitions, chiffre_gauche);
  }

  nombre = resultat ;
  resultat = 0 ;
  chiffre_gauche = 0 ; 
  chiffre_gauche_while = 0;
  repetitions = 1 ; 
  
  return nombre ; 
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
