#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/



class Auteur
{
public:
     Auteur(string n, bool p = false) : nom(n), prime(p) {}
     Auteur(Auteur &a) = delete;

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
     ~Oeuvre()
     {
          cout << "L’oeuvre " << getTitre() << ", " << getAuteur().getNom() << ", en " << getLangue() << " n’est plus disponible." << endl;
     }

     Oeuvre(Oeuvre &o) = delete;

     Oeuvre(string tit, Auteur &a, string lan) : titre(tit), auteur(a), langue(lan) {}

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
     ~Exemplaire() { cout << "Un exemplaire de " << getOeuvre().getTitre() << ", " << getOeuvre().getAuteur().getNom() << ", en " << getOeuvre().getLangue() << "a été jeté"; }
     Exemplaire(Oeuvre &o) : oeuvre(o)
     {
          cout << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue();
     }

     Exemplaire(const Exemplaire &ee) : oeuvre(ee.oeuvre) {}

     void affiche() const
     {
          cout << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue();
     }

     Oeuvre &getOeuvre() const
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
          cout << "La bibliothèque " << getNom() << " ferme ses portes et détruit ses livres." << endl;
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
               v.push_back(Exemplaire(o));
          }

          return;
     }
     void lister_exemplaires(string langue1 = "")
     {

          if (langue1 == "")
          {
               for (int i(0); i < v.size(); i++)
               {
                    v[i].affiche();
                    cout << endl;
               }
          }
          for (int i(0); i < v.size(); i++)
          {
               if (v[i].getOeuvre().getLangue() == langue1)
               {
                    v[i].affiche();
                    cout << endl;
               }
          }
     }

     int compter_exemplaires(Oeuvre &o)
     {
          int count(0);
          for (int i(0); i < v.size(); i++)
          {
               if (v[i].getOeuvre().getTitre() == o.getTitre())
               {
                    ++count;
               }
          }
          return count;
     }
     void afficher_auteurs(bool b = false)
     {

          for (int i(0); i < v.size(); i++)
          {
               if (v[i].getOeuvre().getAuteur().getPrime() == b)
               {
                    cout << v[i].getOeuvre().getAuteur().getNom() << endl;
               }
          }
     }

private:
     string nom;
     vector<Exemplaire> v;
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
