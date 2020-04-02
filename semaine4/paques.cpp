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
  string affiche("") ; 
  if (nombre_de_jours< 32)
  {
    affiche = nombre_de_jours + "mars" ;
  }
  else
  {
     affiche = (nombre_de_jours -31 ) + "avril";
  }
  
  cout << "Date de Paques en " << annee << " : " << affiche ;


}

int date_Paques(int annee)
{
  int siecle(annee/100);
  int p(((8*siecle) + 13)/25);
  int q(siecle/4);
  int M((15-p-q + siecle)%30);
  int N(4+siecle - (q%7) );
  int d((19*(annee%19)+M)%30) ;
  int e((2*(annee % 4) + 4*(annee % 7) + 6*d + N) % 7);
  int jour(e+d +15);
  if (e == 6 && ((d==29) or ((d==28) && ((11*(M+1))%30 <19)   )))
  {
    jour = jour -7 ; 
  }
  return jour ; 



  return 0 ; 
}

int main()
{


  return 0;
}
