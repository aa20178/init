#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/

Brique(Forme f, Couleur c) : forme(f),couleur(c) {} 
Brique()=delete ;

ostream& afficher(ostream& sortie) const 
{
	if(couleur!="")
	{
		sortie << "(" << forme << "," << couleur << ")" ;
	}
	if(couleur=="")
	{
		sortie <<  forme ;
	}
	return sortie;
}

 

};

 ostream& operator<<(ostream& sortie, Brique const& b)  
 {
	 return b.afficher(sortie) ;
	 
 }
 
 
 class Construction
{
friend class Grader;

public:
vector<vector<vector<int>>> contenu ;
Construction(Brique b) : contenu(1, vector<vector<int>>(1, vector<int>(1,5))){}
ostream& afficher(ostream& sortie) const 
{
	int i(0) ;
	for (int i =  contenu.size() ; i>0 ; i--)
	{
		sortie << "couche " << i << " :"  ; 				
	    
		for (int k = 0 ; k< contenu[i].size() ; k++)
		{
			for (int j = 0 ; j< contenu[i][k].size() ; j++)
			{
				sortie << contenu[i][k][j] ;		
			}
			sortie << "\n" ; 
		
		}
		
	}
	return sortie ;
}



};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");
  
    cout << mur << endl << toitD;

  

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit
  
  Construction con(mur); 
  cout << con.afficher(cout);

  // on construit les murs
 
/*
 Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;
*/
  return 0;
}
