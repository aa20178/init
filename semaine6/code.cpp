#include <iostream>
using namespace std;

char code(char c, int d)
{
    if ( (c > 'a') and  (c <= 'z'))
    {
        return decale(c,'a', d );
    }

    else if ((c > 'A') and  (c <= 'Z'))
    {
        return decale(c,'A', d );

    }

    else
    {
        return c ; 
    }
    
}

int decale(char c, char debut, int decalage)
{
    while (decalage < 0)
    {
        decalage += 26;
    }
    return debut + (((c - debut) + decalage) % 26) ; 
}

string code(string c, int d)
{ }


int main()
{
    return  0 ; 
}