#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/
class Produit
{

protected:
  string nom_;
  string unite_;

public:
  Produit(string a, string b = "") : nom_(a), unite_(b) {}

  string getNom() const
  {
    return nom_;
  }
  string getUnite() const
  {
    return unite_;
  }
  virtual string toString() const
  {
    return nom_;
  }

  const Produit *adapter(double d) const
  {
    return this;
  }

  virtual double quantiteTotale(const string &nomProduit) const //produit
  {
    if (getNom() == nomProduit)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
};

class Ingredient
{
private:
  const Produit &produit_;
  double quantite;

public:
  Ingredient(const Produit &p, double q) : produit_(p), quantite(q) {}

  const Produit &getProduit() const //was virtual
  {
    return produit_;
  }

  double getQuantite() const
  {
    return quantite;
  }

  string descriptionAdaptee() const
  {
    ostringstream ss;
    ss << quantite; //Utiliser ss comme cout

    string s = std::to_string(quantite) + " " + produit_.getUnite() + " de ";

    const Produit *produitadap = produit_.adapter(quantite);

    s = s + produitadap->toString();
    return s;
  }

  double quantiteTotale(const string &nomProduit) const
  {
    return (getQuantite() * getProduit().quantiteTotale(nomProduit));
  }
};

class Recette
{
private:
  vector<Ingredient> liste;
  string nom_recette_;
  double nbFois_;

public:
  Recette(string nom, double q = 1) : nom_recette_(nom), nbFois_(q) {}

  double getnbFois_() const
  {
    return nbFois_;
  }
  string getnom_recette_() const
  {
    return nom_recette_;
  }
  void ajouter(const Produit &p, double quantite)
  {
    Ingredient i(p, quantite * nbFois_);
    liste.push_back(i);
  }

  Recette adapter(double n)
  {
    Recette r(nom_recette_, n * nbFois_);
    for (size_t i(0); i < liste.size(); i++)
    {
      r.ajouter(liste[i].getProduit(), liste[i].getQuantite() * n / nbFois_); //enlever le n ? 
    }

    return r;
  }

  string toString() const // was virtual
  {
    string s;

    ostringstream ss;
    ss << nbFois_; //Utiliser ss comme cout
    string nbFois_str = ss.str();

    s = s + "  Recette \"" + nom_recette_ + "\" x " + nbFois_str + ":" + "\n";

    for (size_t i(0); i < liste.size(); i++)
    {
      s = s + "  " + std::to_string(i + 1) + ". " + liste[i].descriptionAdaptee(); // DOUTE ICI
      if (i != (liste.size() - 1))
      {
        s = s + "\n";
      }
    }

    return s;
  }

  double quantiteTotale(const string &nomProduit) const  //recette
  {
    double somme(0);

    for (size_t i(0); i < liste.size(); i++)
    {
      if (liste[i].getProduit().getNom() == nomProduit)
      {
        somme = somme + liste[i].getQuantite();
      }
    }
    return somme;
  }
};

class ProduitCuisine : public Produit
{
public:
  ProduitCuisine(string no) : Produit(no, "portion(s)"), recetteCuisine(no) {}

  void ajouterARecette(const Produit &prod, double quan)
  {
    recetteCuisine.ajouter(prod, quan);
  }

  //const ProduitCuisine *adapter(double n)  override
  const Produit *adapter(double n) const
  {

    ProduitCuisine *pp = new ProduitCuisine(getNom());
    pp->recetteCuisine.adapter(n); //adapter(n);
    return pp;
  }

  string toString() const override
  {
    string s;
    s += Produit::toString();
    s += "\n";
    s += recetteCuisine.toString();
    //s += ":";
    return s;
  }

  double quantiteTotale(const string &nomProduit) //produit Cuisine
  {
    if (getNom() == nomProduit)
    {
      return 1;
    }
    else
    {
      return recetteCuisine.quantiteTotale(nomProduit);
    }
  }

private:
  Recette recetteCuisine;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette &recette, const Produit &produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n"
       << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
