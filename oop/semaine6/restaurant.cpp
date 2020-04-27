#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/
class Produit
{
public:
  Produit(string nom, string unite = "") : nom_produit_(nom), unite_(unite) {}

  string getNom() const
  {
    return nom_produit_;
  }
  string getUnite() const
  {
    return unite_;
  }
  virtual string toString() const
  {
    return nom_produit_;
  }
  double quantiteTotale(const string &nomProduit) const
  {
    if (nom_produit_ == nomProduit)
    {
      return 1;
    }
    else
      return 0;
  }

  virtual const Produit *adapter()
  {
    return this;
  }

protected:
  string nom_produit_;
  string unite_;
};

class Ingredient
{
public:
  Ingredient(Produit const &inproduit, double quantite) : p_(inproduit), quantite_(quantite) {}

  const Produit &getProduit() const
  {
    return p_;
  }

  void setQuantite(double q)
  {
    quantite_ = q;
  }

  double getQuantite() const
  {
    return quantite_;
  }
  string descriptionAdaptee() const
  {
    return std::to_string(quantite_) + " " + p_.getUnite() + " de " + p_.toString();
  }

  double quantiteTotale(const string &nomProduit)
  {

    return getQuantite() * p_.quantiteTotale(nomProduit);
  }

private:
  const Produit &p_;
  double quantite_;
};

class Recette
{
public:
  Recette(string nom, double nombre = 1) : nom_recette_(nom), nbFois_(nombre) {}

  void ajouter(const Produit &p, double quantite)
  {
    Ingredient a(p, nbFois_ * quantite);

    ingredients_.push_back(a);
  }

  virtual Recette adapter(double n)
  {
    Recette r(nom_recette_, n / nbFois_);
    /*  
   for (auto &ing : ingredients_)
    {
      ing.setQuantite(ing.getQuantite() * (n / nbFois_));
    }
     */
    return r;
  }

  virtual string toString()
  {
    string s;
    s = s + "Recette \"" + this->nom_recette_ + "\" x " + std::to_string(nbFois_) + ":" + "\n";
    for (size_t i(0); i < ingredients_.size(); i++)
    {
      s = s + std::to_string(i + 1) + ". " + ingredients_[i].descriptionAdaptee();
      if (i != (ingredients_.size() - 1))
      {
        s = s + "\n";
      }
    }
    return s;
  }

  virtual double quantiteTotale(const string &nomProduit) const
  {
    double somme(0);
    for (size_t i(0); i < ingredients_.size(); i++)
    {
      if (ingredients_[i].getProduit().getNom() == nomProduit)
      {
        somme = somme + ingredients_[i].getQuantite();
      }
    }
    return somme;
  }

private:
  vector<Ingredient> ingredients_;
  string nom_recette_;
  double nbFois_;
};

class ProduitCuisine : public Produit
{
public:
  ProduitCuisine(string nom) : Produit(nom, "portions"), r(nom) {}

  void ajouterARecette(const Produit &produit, double quantite)
  {
    //cout << "toto";
    r.ajouter(produit, quantite);
  }

  const ProduitCuisine *adapter(double n)
  {
    ProduitCuisine *pp = new ProduitCuisine(nom_produit_);
    pp->r.adapter(n);
    return pp;
  }

  string toString()
  {
    string s;
    s = s + Produit::toString() + "\n"; // cause segfault

    s = s + r.toString() + ":";
    return s;
  }

  double quantiteTotale(const string &nomProduit)
  {
    if (nom_produit_ == nomProduit)
    {
      return 1;
    }
    else
    {
      return r.quantiteTotale(nomProduit);
    }
  }

private:
  Recette r;
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
