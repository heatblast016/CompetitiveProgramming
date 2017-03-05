/*
ID: adiddee1
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
    ifstream in("beads.in");
    ofstream out("beads.out");
    int n;
    int count = 0;
    in >> n;
    char arr[n];
    in >> arr;
    for(int i = 0; i < n - 1; i++)
    {
        int fulllooparound = 1;
        int counter = 0;
        int lower = i;
        int upper = i + 1;
        char lowertype = arr[lower];
        char uppertype = arr[upper];
        for(int j = 0; j < n; j++)
        {
            if(arr[(upper + j) % n] == uppertype || arr[(upper + j) % n] == 'w')
            {
                counter++;
            }
            else
            {
                fulllooparound = 0;
                break;
            }
        }
        if(fulllooparound == 0)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[(n + lower - j) % n] == uppertype || arr[(n + lower - j) % n] == 'w')
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
        }
        count == (counter > count) ? counter : count;
    }
    out << count << endl;
    in.close();
    out.close();
    return 0;
}