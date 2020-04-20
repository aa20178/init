#include <iostream>
#include <string>
using namespace std;

class Game
{
public:
  void add_animal(Animal *);
private:
  vector<unique_ptr<Animal>> animals; // version 2
  vector<Animal *> animals1;   // version 1
};