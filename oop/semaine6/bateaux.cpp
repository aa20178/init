#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
public:


Pavillon pavillon_;
Etat etat_;
Coordonnees position_;
static int rayon_rencontre;

Navire(int x, int y, Pavillon pavillonIn) : position_(x,y), pavillon_(pavillonIn), etat_(Intact) {}


Coordonnees position() const
{
	return position_;
	
}

void avancer(int de_x, int de_y) 
{
	if (etat_!=Coule)
	{
		Coordonnees c(de_x,de_y); 
		position_ += c;
	}
}
void renflouer() 
{
		etat_= Intact;
}

ostream& afficher(ostream& os) const ;



};


 ostream& operator<<(ostream& os, Coordonnees const& autre)
{
	os << "(" << autre.x() <<", " << autre.y() << ")";
	
}
 ostream& operator<<(ostream& os, Pavillon const& autre)
{
	if(autre==JollyRogers) 
		os << "pirate";
	else if (autre==CompagnieDuSenegal)
		os << "français";
	else if (autre== CompagnieDOstende)
		os << "autrichien";
	else os << "pavillon inconnu";
		
	
}
 ostream& operator<<(ostream& os, Etat const& autre)
{
	if(autre==Intact) 
		os << "intact";
	else if (autre==Endommage)
		os << "ayant subi des dommages";
	else if (autre==Coule)
		os << "coule";
	else os << "état inconnu";
		
	
}


double distance(const Coordonnees& ship1,const Coordonnees& ship2) 
{
	double terme1 = (ship1.x() - ship2.x()) *(ship1.x() - ship2.x());
		double terme2 = (ship1.y() - ship2.y()) *(ship1.y() - ship2.y());

	return sqrt( terme1+terme2) ; 
	
}


ostream& Navire::afficher(ostream& os) const 
{
	os << "navire en " << position_ << " battant pavillon " << pavillon_<< ", " << etat_ ; 
	return os; 
}

double distance(const Navire& n1, const Navire& n2) 
{
	return distance(n1.position_,n2.position_) ;
}
 ostream& operator<<(ostream& os, Navire const& autre)
{
	return autre.afficher(os) ;
}

int Navire::rayon_rencontre(10);

void Coordonnees::operator+=(Coordonnees const& autre)
{
	 x_ = x_ + autre.x() ;
	 y_ = y_ + autre.y() ;

}

class Pirate : public Navire
{
  public:
  Pirate(int x, int y, Pavillon pavillonIn) :Navire( x,  y, pavillonIn){}

};
class Marchand : public Navire
{
  public:
  Marchand(int x, int y, Pavillon pavillonIn) :Navire( x,  y, pavillonIn){}

};

class Felon : public Marchand, public Pirate
{
  public:
  using Navire::pavillon_;
    using Navire::etat_;
using Navire::position_;

  Felon(int x, int y, Pavillon pavillonIn) :Marchand( x,  y, pavillonIn),Pirate( x,  y, pavillonIn) {}

};
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);

  return 0;
}
