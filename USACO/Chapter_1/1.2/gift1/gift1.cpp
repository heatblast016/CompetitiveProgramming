/*
ID: adiddee1
LANG: C++11
TASK: gift1
*/
#include <iostream>
#include <fstream>
using namespace std;
int np;
int main()
{
    ifstream in("gift1.in");
    ofstream out("gift1.out");
    in >> np;
    string list[np];
    int balance[np];
    for(int i = 0; i < np; i++)
    {
        balance[i] = 0;
    }
    for(int j = 0; j < np; j++)
    {
        in >> list[j];
    }
    for(int i = 0; i < np; i++)
    {
        string giver;
        int numppl;
        int givemoney;
        int indexofgiver;
        in >> giver >> givemoney >> numppl;
        for(int j = 0; j < np; j++)
        {
            if(list[j] == giver)
            {
                balance[j] -= givemoney;
                balance[j] += (numppl != 0) ? (givemoney % numppl) : 0;
                indexofgiver = j;
                break;
            }
        }
        int moneytogive = (numppl != 0) ? (givemoney - (givemoney % numppl)) / numppl : 0;
        for(int k = 0; k < numppl; k++)
        {
            string tmp;
            in >> tmp;
            for(int j = 0; j < np; j++)
            {
                if(list[j] == tmp)
                {
                    balance[j] += moneytogive;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < np; i++)
    {
        out << list[i] << ' ' << balance[i] << endl;
    }
    in.close();
    out.close();
    return 0; 
}

