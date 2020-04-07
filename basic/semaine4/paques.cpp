#include <iostream>
using namespace std;

int demander_annee()
{
  int annee(0);
  do
  {
    cout << "Entrez une annee (1583-4000) : ";
    cin >> annee;
  } while (not(annee<4000 && annee > 1583));
  return annee ; 
}


void affiche_date(int annee, int nombre_de_jours)
{
  int affiche(0) ; 
  if (nombre_de_jours< 32)
  {
    affiche = nombre_de_jours ;
    cout << "Date de Paques en " << annee << " : " << affiche << " mars" << endl;
  }
  else
  {
    affiche = (nombre_de_jours -31 );
    cout << "Date de Paques en " << annee << " : " << affiche << " avril"<<endl;

  }
  


}

int date_Paques(int annee)
{
  int siecle(annee/100);
  int p(((8*siecle) + 13)/25);
  int q(siecle/4);
  int M((15-p-q + siecle)%30);
  int N((4+siecle - q)%7 );
  int d((M + (19*(annee%19)))%30);
  int e((2*(annee % 4) + 4*(annee % 7) + 6*d + N) % 7);
  int jour(e+d +22);

  bool d_eq_28((d==28));
  bool d_eq_29((d==29));
  bool finalPartOfOr(((11*(M+1))%30 <19));
  bool bigOr(d_eq_28 && finalPartOfOr);

  if (e == 6 && (d_eq_29 or ( bigOr)))
  {
    jour = jour -7 ; 
  }
  return jour ; 



  return 0 ; 
}

int main()
{
  int anneeU(demander_annee());
  int jour_paques_selon_an(date_Paques(anneeU));
  //cout << "jour calculé " <<jour_paques_selon_an <<endl;
  affiche_date(anneeU,jour_paques_selon_an);

  return 0;
}
