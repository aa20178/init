#include <iostream>
using namespace std;

int shift(char c, char start, int offset)
{
    while (offset < 0)
    {
        offset += 26;
    }
    return start + (((c - start) + offset) % 26);
}

char code(char c, int d)
{
    if ((c > 'a') and (c <= 'z'))
    {
        return shift(c, 'a', d);
    }

    else if ((c > 'A') and (c <= 'Z'))
    {
        return shift(c, 'A', d);
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

int main()
{
    string s("Fuyez manants");
    //cout << s <<endl ;
    string nouv("");
    nouv = code(s, 4);
    cout << nouv << endl;

    return 0;
}