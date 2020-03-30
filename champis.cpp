#include <iostream>
using namespace std;

int main()
{
     int lamelles(0);
     int anneau(0);
     int chapeau(0);
     int foret(0);

     cout << "Pensez à  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
     << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

     cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
     cin >> chapeau ;
     
     if(chapeau == 0)
     {
          cout << "Est-ce que votre champignon vit en forÃªt (1 : oui, 0 : non) ? ";
          cin >> foret ;

          if(foret == 0)
          {
               cout << "==> Le champignon auquel vous pensez est ";
               cout << "le coprin chevelu";
          }
          else if (foret == 1)
          {
               cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
               cin >> lamelles ;
               
               if (lamelles == 0)
               {
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "le cèpe de Bordeaux";
               }
               else
               {
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "la girolle";
               }
          }
     }

     if(chapeau == 1)
     {
          cout << "Est-ce que votre champignon vit en forÃªt (1 : oui, 0 : non) ? ";
          cin >> foret ;

          if(foret == 0)
          {
               cout << "==> Le champignon auquel vous pensez est ";
               cout << "l'agaric jaunissant";
          }
          else if ( foret == 1)
          {
               cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
               cin >> anneau ;

               if(anneau == 1)
               {
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "l'amanite tue-mouches";
               }
               else
               { 
                    cout << "==> Le champignon auquel vous pensez est ";  
                    cout << "le pied bleu";
               }
          }
     }

}