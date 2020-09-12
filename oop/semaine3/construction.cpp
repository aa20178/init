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
vector<vector<vector<Brique>>> contenu ;
Construction(Brique b) : contenu(1, vector<vector<Brique>>(1, vector<Brique>(1,b))){}
  Construction & operator ^= (Construction const &b);
    Construction&  operator-=(Construction const& b)  ;
    Construction&  operator+=(Construction const& b)  ;

ostream& afficher(ostream& sortie) const 
{
	if (contenu.empty())
	{
		return sortie ; 
	}
	else 
	{
        for (size_t i = contenu.size(); i--; ) 
        {
			sortie << "couche " << i << " :\n"  ; 				
			for (size_t k = 0 ; k< contenu[i].size() ; k++)
			{
				for (size_t j = 0 ; j< contenu[i][k].size() ; j++)
				{
					sortie << contenu[i][k][j] ;		
				}
				sortie << "\n" ; 
			}
			
    	}
	    return sortie ;
	}
}

  
  
};


  Construction & Construction::operator^= (Construction const &b)
 {
     for(size_t i(0); i< b.contenu.size();i++)
	  {
	      contenu.push_back(b.contenu[i]);
	  }
	return (*this);
	  
 }
  Construction&  Construction::operator-=(Construction const& b)  
 {
          if(b.contenu.size() >= contenu.size())
          {
              for(size_t i(0); i< contenu.size();i++)
              {
                for(size_t j(0); j< b.contenu[i].size();j++)
                {
                    contenu[i].push_back(b.contenu[i][j]);
                    
                }
              }
          }
          	return (*this);

 }
 
 
Construction&  Construction::operator+= (Construction const& b)
  {
    int flag = 1;
      
    if (b.contenu.size () < contenu.size ())
	{
	    flag = 0;
    }
    else
    {
        
	    for (size_t i (0); i < contenu.size (); i++)
    	{
        	if (b.contenu[i].size () < contenu[i].size ())
        	{
        	    flag = 0; 
        	    break ; 
        	}
        	
    	}
    	if(flag == 1)
    	{
    	    
    	    for (size_t i (0); i < contenu.size (); i++)
        	{
                	for (size_t j (0);j <contenu[i].size (); j++)
                	{
    
                    	for (size_t k (0); k < b.contenu[i][j].size (); k++)
                    	{
        	                contenu[i][j].push_back (b.contenu[i][j][k]);
                    	}
        	
    	            
                	}
        	}
        }
    }
    
    return (*this);

}


 
 

 ostream& operator<<(ostream& sortie, Construction const& b)  
 {
	 return b.afficher(sortie) ;	 
 }

 
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "blanc");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  // on construit les murs
  Construction maisonblanche(toitG );
  Construction maisonrouge(toitD );

  maisonblanche += maisonrouge ; 
    maisonblanche -= maisonrouge ; 

  //maisonblanche ^= maisonrouge ; 

  
  cout << maisonblanche << endl;

  return 0;
}
