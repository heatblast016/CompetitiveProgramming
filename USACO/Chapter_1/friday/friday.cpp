/*
ID: adiddee1
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int days[12] = {31 , 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int thirteens[7] = {0, 0, 0, 0, 0, 0, 0} ;
    ifstream in("friday.in");
    ofstream out("friday.out");
    int years;
    in >> years;
    int dayselapsed = 0;
    for(int i = 1900; i < 1900 + years; i++)
    {
        for(int j = 0; j < 12;  j++)
        {
            int month = ((j == 1) && ((i % 4 == 0 && i % 100 != 0 ) || i % 400 == 0)) ? 29 : days[j];
            for(int k = 0; k < month; k++)
            {
                dayselapsed++;
                if(k == 12)
                {
                    thirteens[(dayselapsed % 7)]++;
                }
            }
        }
    }
    out << thirteens[6] << " " ;
    for(int i = 0; i < 6; i++)
    {
        out << thirteens[i] << " ";
    }
    out << endl;
    return 0;
}