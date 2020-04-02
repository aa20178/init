#include <iostream>
using namespace std;

int demander_annee()
{
  int annee(0);
  do
  {
    cout << " Entrez une annee(1583-4000) : ";
    cin >> annee;
  } while (not(annee<4000 && annee > 1583));
  return annee ; 
}


void affiche_date(int annee, int nombre_de_jours)
{
}

int date_Paques(int annee)
{
}

int main()
{
  int nombre(1);
  cin >> nombre;
  cout << nombre << endl;
  return 0;
}
