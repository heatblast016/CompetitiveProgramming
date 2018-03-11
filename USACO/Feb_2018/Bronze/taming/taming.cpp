#include <iostream>
#include <fstream>

using namespace std;
// did not pass case 3
int main(void)
{
    ifstream in("taming.in");
    ofstream out("taming.out");
    int n;
    in >> n;
    int log[n];
    for(int i = 0; i<n; i++)
    {
        in >> log[i];
    }
    log[0] = 0;
    int logger = -1;
    for(int i = n-2; i >= 0; i--)
    {
        logger = log[i+1];
        if(logger >= 1)
        {
            if(log[i] >=1 && logger - log[i] != 1)
            {
                log[0] == 5;
                break;
            }
            else if(log[i] < 1)
            {
                log[i] = logger -1;
                logger--;
            }  
        }
        else
        {
            logger = log[i];
        }
    }
    if(log[0] != 0)
    {
        out << -1 << endl;
    }
    else
    {
        int numz = 0;
        int numneg = 0;
        for(int i = 0; i < n; i++)
        {
            if(log[i] == 0)
            {
                numz++;
            }
            else if(log[i] < 0)
            {
                numneg++;
            }
        }
        out << numz << " " << numz+numneg << endl;
    }
    out.close();
    in.close();
}