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

    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    cout << "Bizarre, le début de la location est après la fin ..." << endl;

    cout << "Vous avez loué votre vélo pendant" << endl;

      cout << " heure(s) au tarif horaire de "
           << " franc(s)" << endl;

    cout << "Le montant total à payer est de "
         << " franc(s)." << endl;

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
