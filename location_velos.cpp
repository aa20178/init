#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/


  if (debut < 0 or debut > 24 or fin <0 or fin > 24 )
  {
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
  }
  else if (debut == fin)
  {
      cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
  }

  else if (debut > fin)
  {
      cout << "Bizarre, le début de la location est après la fin ..." << endl;
  }

  else
  {
      int unf(0);
      int deuxf(0);
      




      if(debut<= 7 and fin>= 17)
      {
          unf = (7-debut) + (fin - 17);
          deuxf = 10;
      }

      else if(debut<= 7 and fin< 17 and fin > 7)
      {
          unf = (7-debut) ;
          deuxf =  (fin-7);
      }

      else if(debut<= 7 and fin< 17 and fin <= 7)
      {
          unf = (fin-debut) ;
          deuxf = 0;
      }


      else if(debut> 7 and debut <= 17 and fin>= 17)
      {
          unf = (fin - 17);
          deuxf = (17 - debut) ;
      }

      else if(debut> 7 and debut > 17 and fin>= 17)
      {
          unf = (fin - debut);
          deuxf = 0 ;
      }

      else if(debut> 7 and fin<17)
      {
          unf = 0;
          deuxf = (fin - debut) ;
      }


    cout << "Vous avez loué votre vélo pendant" << endl;

    cout <<unf << " heure(s) au tarif horaire de "
          <<1 << " franc(s)" << endl;

    cout <<deuxf<< " heure(s) au tarif horaire de "
      <<2 << " franc(s)" << endl;

    cout << "Le montant total à payer est de " << unf + (deuxf)* 2
         << " franc(s)." << endl;

  }
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
