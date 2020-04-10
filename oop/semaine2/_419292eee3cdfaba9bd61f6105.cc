#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
#include <memory>

class Auteur
{
public:
     Auteur(string n, bool p = false) : nom(n), prime(p) {}
     Auteur(const Auteur &a) = delete;

     string getNom() const
     {
          return nom;
     }
     bool getPrime() const
     {
          if (prime)
          {
               return true;
          }
     }

private:
     string nom;
     bool prime;
};

class Oeuvre
{
public:
     Oeuvre(const Oeuvre &o) = delete;

     Oeuvre(string tit, Auteur &a, string lan) : titre(tit), auteur(a), langue(lan) {}
     ~Oeuvre()
     {
          cout << "L’oeuvre " << getTitre() << ", " << getAuteur().getNom() << ", en " << getLangue() << " n’est plus disponible." << endl;
     }
     string getTitre() const
     {
          return titre;
     }
     const Auteur &getAuteur() const
     {
          return auteur;
     }
     void affiche() const
     {
          cout << getTitre() << ", " << getAuteur().getNom() << ", en " << getLangue(); //<< endl;
     }

     string affiche_string() const
     {
          return getTitre() + ", " + getAuteur().getNom() + ", en " + getLangue(); //<< endl;
     }

     string getLangue() const
     {
          return langue;
     }

private:
     string titre;
     const Auteur &auteur;
     string langue;
};

class Exemplaire
{
public:
     ~Exemplaire() { cout << "Un exemplaire de " << getOeuvre().affiche_string() << " a été jeté !" << endl; }
     Exemplaire(Oeuvre &o) : oeuvre(o)
     {
          cout << "Nouvel exemplaire de : " << getOeuvre().affiche_string() << endl;
     }

     Exemplaire(const Exemplaire &ee) : oeuvre(ee.oeuvre)
     {
          cout << "Copie d'un exemplaire de : " << getOeuvre().affiche_string() << endl;
     }

     void affiche() const
     {
          cout << "Exemplaire de : " << getOeuvre().affiche_string() << endl;
     }

     const Oeuvre &getOeuvre() const
     {
          return oeuvre;
     }

private:
     Oeuvre &oeuvre;
};

class Bibliotheque
{
public:
     ~Bibliotheque()
     {
          cout << "La bibliothèque " << getNom() << " ferme ses portes, et détruit ses livres." << endl;
     }

     Bibliotheque(string s) : nom(s) { cout << "La bibliothèque " << getNom() << " est ouverte !" << endl; }

     string getNom()
     {
          return nom;
     }

     void stocker(Oeuvre &o, int nombre = 1)
     {
          for (int i(0); i < nombre; i++)
          {
               v.push_back(std::make_unique<Exemplaire>(o));
          }

          return;
     }
     void lister_exemplaires(string langue1 = "")
     {

          if (langue1 == "")
          {
               for (int i(0); i < v.size(); i++)
               {
                    v[i]->affiche();
               }
          }
          else
          {
               {
                    for (int i(0); i < v.size(); i++)
                    {
                         if (v[i]->getOeuvre().getLangue() == langue1)
                         {
                              v[i]->affiche();
                         }
                    }
               }
          }
     }

     int compter_exemplaires(Oeuvre &o)
     {
          int count(0);
          for (int i(0); i < v.size(); i++)
          {
               if (v[i]->getOeuvre().getTitre() == o.getTitre())
               {
                    ++count;
               }
          }
          return count;
     }

     void afficher_auteurs(bool b = false)
     {
          if (b == true)
          {
               for (int i(0); i < v.size(); i++)
               {
                    if (v[i]->getOeuvre().getAuteur().getPrime() == true)
                    {
                         cout << v[i]->getOeuvre().getAuteur().getNom() << endl;
                    }
               }
          }
          else
          {
               for (int i(0); i < v.size(); i++)
               {
                    cout << v[i]->getOeuvre().getAuteur().getNom() << endl;
               }
          }
     }

private:
     string nom;
     vector<unique_ptr<Exemplaire>> v;
};
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
