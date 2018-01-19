/*
ID: adiddee1
LANG: C++11
TASK: namenum
*/
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

string toBase(int base, int number)
{
    string final = "";
    int total = pow(number, 2);
    int powa = 0;
    for(powa = 0; pow(base, powa) < total; powa++)
    {
    }
    powa--;
    for(int i = powa; i >= 0; i--)
    {
        if(pow(base, i) <= total)
        {
            final.append("1");
            total -= pow(base, i);
        }
        else
        {
            final.append("0");
        }
    }
    return final;
}
int main()
{
    ifstream in("palsquare.in");
    ofstream out("palsquare.out");
    int b;
    in >> b;
    in.close();
    for (int i = 1; i < 301; i++)
    {
        string pal = toBase(b ,pow(i, 2));
        bool ispal = true;
        for(int i = 0; i < pal.size(); i++)
        {
            if(pal.at(i) != pal.at(pal.size() - 1 - i))
            {
                ispal = false;
            }
        }
        if(ispal == true)
        {
            out << i <<" "<< pal << endl;
        }
    }
    out.close();
}