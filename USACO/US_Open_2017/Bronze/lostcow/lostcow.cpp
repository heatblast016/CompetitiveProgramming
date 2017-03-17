#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    ifstream in("lostcow.in");
    ofstream out("lostcow.out");
    int x;
    int y;
    in >> x >> y;
    int stepstaken = 0;
    bool found = false;
    int startingvalue = 1;
    int pos = x;
    while(found == false)
    {
        for(int i = pos; i < x + startingvalue; i++)
        {

            pos++;
            stepstaken++;
            if(pos == y)
            {
                found = true;
                break;
            }
        }
        if(found == true)
        {
            break;
        }
        startingvalue *= -2;
        for(int i = pos; i > x + startingvalue; i--)
        {
            pos--;
            stepstaken++;
            if(pos == y)
            {
                found = true;
                break;
            }
        }
        startingvalue *= -2;
    }
    out << stepstaken << endl;
    in.close();
    out.close();
}