#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales

  do
  {
    cout << "Combien de renards au départ (>= 2) ? ";
    cin >> renards_i;
  } while (renards_i < 2);

  do
  {
  cout << "Combien de lapins au départ  (>= 5) ? ";
    cin >> lapins_i;
  } while (lapins_i < 5);
  
  /*

  // ===== PARTIE 2 =====
  // Première simulation

  cout << endl
       << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;

  double renards(renards_i), lapins(lapins_i);
  for (int i = 0; i < 50; ++i)
  {
    double lapins_buffer(lapins), renards_buffer(renards);
    lapins = lapins * (1.0 + taux_croissance_lapins - taux_attaque * renards_buffer);
    renards = renards * (1.0 + taux_attaque * lapins_buffer * taux_croissance_renards - taux_mortalite);

    if (lapins < 0.05)
    {
      lapins = 0;
    }

    else if (renards < 0.05)
    {
      renards = 0;
    }
    cout << "Après " << i + 1 << " mois, il y a " << lapins << " lapins"
         << " et " << renards << " renards" << endl;
  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque

  double taux_attaque_f(0.0);
  do
  {
    cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
    cin >> taux_attaque;
  } while (not(taux_attaque < 6 && taux_attaque > 0.5));

  do
  {
    cout << "taux d'attaque à la fin en % (entre 0.5 et 6) ? ";
    cin >> taux_attaque_f;
  } while (not(taux_attaque_f <= 6 && taux_attaque_f > taux_attaque));

  double borne_attaque(taux_attaque), borne_attaque_f(taux_attaque_f);
  taux_attaque_f = taux_attaque_f / 100.0;
  taux_attaque = taux_attaque / 100.0;

  for (double k = borne_attaque; k <= borne_attaque_f; k++)
  {

    cout << endl
         << "***** Le taux d'attaque vaut " << k << "%" << endl;

    renards = renards_i;
    lapins = lapins_i;
    bool lapins_ext(false), lapins_ext_precedent(false), renards_ext(false), renards_ext_precedent(false), lapins_flag(false), renards_flag(false), lapins_flag2(false), renards_flag2(false);
    int j(0);

    for (int i = 0; i < 50; ++i)
    {
      j = i;
      double lapins_buffer(lapins), renards_buffer(renards);
      lapins = lapins * (1.0 + taux_croissance_lapins - (k / 100.0) * renards_buffer);
      renards = renards * (1.0 + (k / 100.0) * lapins_buffer * taux_croissance_renards - taux_mortalite);

      if (renards == 0 && lapins == 0)
      {
        break;
      }

      if (lapins < 2)
      {
        lapins = 0;
      }

      if (renards < 2)
      {
        renards = 0;
      }

      if (lapins < 5)
      {
        lapins_ext = true;
        if (lapins_ext_precedent != lapins_ext)
        {
          lapins_flag = true;
          lapins_ext_precedent = true;
        }
      }

      if (renards < 5)
      {
        renards_ext = true;
        if (renards_ext_precedent != renards_ext)
        {
          renards_flag = true;
          renards_ext_precedent = true;
        }
      }

      if (renards >= 5)
      {
        renards_ext = false;
        if (renards_ext_precedent != renards_ext)
        {
          renards_flag2 = true;
          renards_ext_precedent = false;
        }
      }
    }
    cout << "Après " << j + 1 << " mois, il y a " << lapins << " lapins"
         << " et " << renards << " renards" << endl;



    if (renards_flag == true)
    {
      cout << "Les renards ont été en voie d'extinction" << endl;
    }

   if (renards_flag2 == true)
    {
      cout << "mais la population est remontée ! Ouf !" << endl;
    }

    if (renards == 0)
    {
      cout << "et les renards ont disparu :-(" << endl;
    }

    if (lapins_flag == true)
    {
      cout << "Les lapins ont été en voie d'extinction" << endl;
    }

    if (lapins_flag2 == true)
    {
      cout << "mais la population est remontée ! Ouf !" << endl;
    }

    if (lapins == 0)
    {
      cout << "et les lapins ont disparu :-(" << endl;
    }

    if (lapins_flag == false && lapins_flag2 == false && renards_flag == false && renards_flag2 == false && renards > 0 && lapins > 0)
    {
      cout << "Les lapins et les renards ont des populations stables." << endl;
    }
  }
  */

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
