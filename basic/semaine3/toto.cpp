#include <iostream>
using namespace std;

class Base 
{
    public :
    void print()
    {
        std::cout<< "hello" ;
    }

};
class Child : public Base
{
        public :
    void print()
    {
        std::cout<< "hello child" ;
    }

};

int main()
{

Base b ; 
Child c ; 
b = c;
b.print();

  return 0;
}
