#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
string nom;
  unsigned int annee;
  string pays;
  double valeur_faciale;

public:
  Timbre(string n, unsigned int a, string p = "Suisse", double v = 1.0) : nom(n), annee(a), pays(p), valeur_faciale(v){};
  string getNom() const
  {
    return nom;
  }

  string getPays() const
  {
    return pays;
  }

  unsigned int getAnnee() const
  {
    return annee;
  }

  double getValeurFaciale() const
  {
    return valeur_faciale;
  }
  unsigned int age() const
  {
    return ANNEE_COURANTE - getAnnee();
  } 

  string afficher() const
  {
    string s = "de nom " + getNom() + " datant de " + std::to_string(getAnnee()) + " (provenance " + getPays() + ") ayant pour valeur faciale " ;

    std::string num_text = std::to_string(getValeurFaciale());
    std::string rounded = num_text.substr(0, num_text.find(".")+2);

    s += rounded ;
    s+=" francs";
    return s;
  }
  double vente() //est sa valeur faciale, si le timbre a moins que cinq ans ; sinon,il  vaut  la  valeur  faciale  multipliée  par  2.5  fois  l’âge  du  timbre
  {
    if (age() < 5)
    {
      return getValeurFaciale();
    }
    else
    {
      return (age() * 2.5) * getValeurFaciale();
    }
  }
};
std::ostream &operator<<(std::ostream &os, const Timbre &obj)
{
  os << "Timbre " + obj.afficher();
  return os;
}


class Rare : public Timbre
{
public:
  Rare(string n, unsigned int a, string p = "Suisse", double v = 1.0, unsigned int nb = 100) : Timbre(n, a, p, v), nombre(nb){};

  unsigned int getNombre() const
  {
    return nombre;
  }
  unsigned int nb_exemplaires() const
  {
    return nombre;
  }

  double base()
  {
    if (getNombre() < 100)
    {
      return PRIX_BASE_TRES_RARE;
    }
    else if (getNombre() < 1000)
    {
      return PRIX_BASE_RARE;
    }
    else
      return PRIX_BASE_PEU_RARE;
  }

  double vente()
  {
    return base() * (age() / 10.0);
  }


private:
  static constexpr unsigned int PRIX_BASE_TRES_RARE = 600;

  static constexpr unsigned int PRIX_BASE_RARE = 400;

  static constexpr unsigned int PRIX_BASE_PEU_RARE = 50;

  unsigned int nombre;
};

class Commemoratif : public Timbre
{
public:
  Commemoratif(string n, unsigned int a, string p = "Suisse", double v = 1.0) : Timbre(n, a, p, v){};

  double vente()
  {
    return (Timbre::vente() * 2.0);
  }

private:
};

std::ostream &operator<<(std::ostream &os, const Rare &obj)
{
  os << "Timbre rare (" <<obj.nb_exemplaires() <<" ex.) " <<obj.afficher();
  return os;
}
std::ostream &operator<<(std::ostream &os, const Commemoratif &obj)
{
  os << "Timbre commémoratif " <<obj.afficher();
  return os;
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
