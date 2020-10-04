#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

struct Pos
{
  int x;
  int y;
};
typedef vector<vector<int>> Carte;
typedef struct
{
  int x;
  int y;
} Position;

void ajoute_unique(vector<int> &ensemble, int valeur) {}
bool convexite_lignes(Carte &carte, vector<int> const &labels_bords) { return true; }
bool convexite_lignes(Carte &carte) { return true; }
void affiche(Carte const &carte)
{

  for (int i = 0; i < carte.size(); i++)
  {
    for (int j(0); j < carte[i].size(); j++)
    {
      cout << carte[i][j];
    }
    cout << endl;
  }
}
void reverse_array(vector<int>& arr, int end)
{
    int start = 0 ;
    while (start < end)
    {
        int temp = arr[start]; 
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    } 
}     
 
int debut_ligne(vector<int> v)
{
  for (int j(0); j < v.size(); j++)
  {

    if (((v[j] == 1) && (v[j + 1] == 1)))
    {
      return j;
    }
    else if (((v[j] == 0) && (v[j + 1] == 1)))
    {
      return j + 1;
    }
  }
}

Carte baliser_etangs(Carte const &carte)
{
  Carte carte_debut_fin = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
  for (int i = 0; i < carte.size(); i++) // première boucle de balisage début-fin
  {
    int index_de_debut_de_ligne = debut_ligne(carte[i]); // correspond a l'index du premier "un"

    vector<int> reverse_ligne = carte[i];
    reverse_array(reverse_ligne, reverse_ligne.size() -1);
    int index_de_fin_de_ligne = reverse_ligne.size() - debut_ligne(reverse_ligne) - 1; // correspond a l'index du dernier "un"

    carte_debut_fin[i].push_back(index_de_debut_de_ligne);
    carte_debut_fin[i].push_back(index_de_fin_de_ligne);
    cout << "ligne " << i << " : debut : " << index_de_debut_de_ligne << " fin : " << index_de_fin_de_ligne << endl;
  }
  //affiche(carte_debut_fin);
  return carte_debut_fin;
}

void effacer_etangs(Carte &carte)
{
  Carte carte_debut_fin = baliser_etangs(carte);
  affiche(carte);
  cout << endl
       << endl
       << endl;
  for (int i = 0; i < carte.size(); i++)
  {
    for (int j(0); j < carte[i].size(); j++)
    {
      if ((j >= carte_debut_fin[i][0]) && (j <= carte_debut_fin[i][1]))
      {
        carte[i][j] = 1;
      }
    }
  }
  //affiche(carte);
}


int longueur_cloture(Carte &carte)
{
    Carte cartebalisee = baliser_etangs(carte);
  
  int c=0;
  for (int i = 0; i < carte.size(); i++)
  {
    for (int j= cartebalisee[i][0]; j < cartebalisee[i][1]+1; j++)
    {
        
      if( i ==carte.size() -1 && carte[i][j] == 1)
      {
          c++;
      }
      else if(i==0 && carte[i][j] == 1)
      {
        c++;
      }
      
      if(i>0)
      {
         if(carte[i][j] == 1 && carte[i-1][j] == 0)
        {
           c++; 
        }
     
     if(i<carte.size()-1)
      {
         if(carte[i][j] == 1 && carte[i+1][j] == 0)
        {
           c++; 
        }
      }
      
    if(j<cartebalisee[i][1])
      {
         if(carte[i][j] == 1 && carte[i][j+1] == 0)
        {
           c++; 
        }
      }
      
          if(j>cartebalisee[i][0])
      {
         if(carte[i][j] == 1 && carte[i][j-1] == 0)
        {
           c++; 
        }
      }

    }
  }
    cout << " cloture ligne " << i << ":"<<c <<"\n" ; 

  }
  return c*2.5;
}

bool binaire(Carte const &carte)
{

  for (int i = 0; i < carte.size(); i++)
  {
    for (int j(0); j < carte[i].size(); j++)
    {
      if ((carte[i][j] != 1) && (carte[i][j] != 0))
      {
        return false;
      }
      
      
    }
  }
  return true;
}

bool verifie_et_modifie(Carte &carte)
{
  if (binaire(carte) == false)
  {
    cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
    return false;
  }
  else
  {
    effacer_etangs(carte);
  }
}

/* qui vérifie si la carteest bien composée de0et de1uniquement.
 Si tel n’est pas le cas elle af-fichera le messageVotre carte du terrain ne contient pas que des 0 et des 1
 .suivi d’un saut de ligne (en respectant strictement ce format) et retournerafalse. 
 Sinon, cette fonction devra effacer les étangs et retournertrue. * /






/*
cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
cout << "bord extérieur entrant trouvé en position [";
cout << "][";
cout << "]" << endl;
*/

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
