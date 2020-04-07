#include <iostream>
using namespace std;

int decale(char c, char debut, int decalage)
{
    while (decalage < 0)
    {
        decalage = decalage + 26;
    }
    return debut + (((c - debut) + decalage) % 26); 
}

char code(char c, int d)
{
    if ((c >= 'a') and (c <= 'z'))
    {
        return decale(c, 'a', d);
    }

    else if ((c >= 'A') and (c <= 'Z'))
    {
        return decale(c, 'A', d);
    }

    else
    {
        return c;
    }
}

string code(string c, int d)
{
    string result("");
    for (int i = 0; i < c.length(); ++i)
    {
        char charcode = code(c[i], d);
        result += charcode;
    }
    return result;
}

string decode(string c, int d)
{ 
    return code(c, -d);
}

int main()
{
    string s("Fuyez manants");
    //cout << s <<endl ;
    string nouv(code(s, 4));
    string decoded(decode(nouv, 4));

    cout <<s << " se code en :" << nouv << endl;
    cout <<nouv << " se decode en :" << decoded << endl;

    return 0;
}