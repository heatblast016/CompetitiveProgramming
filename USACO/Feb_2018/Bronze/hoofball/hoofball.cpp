#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ifstream in("hoofball.in");
    ofstream out("hoofball.out");
    int n;
    in >> n;
    int numballz = 0;
    int positions[n];
    for(int i = 0; i < n; i++)
    {
        in >> positions[i];
    }
    int distance[n];
    for(int i = 0; i < n; i++)
    {
        distance[i] = 0;
        int j = i;
        int past = i;
        while(true)
        {
            int closest = (i == n-1) ? i - 1: i + 1;
            int dist = 1000;
            for(int k = 0; k < n; k++)
            {
                if(abs(positions[j] - positions[k])< dist)
                {
                    closest = k;
                    dist =abs(positions[j] - positions[k]);
                }
                else if(abs(positions[j] - positions[k]) == dist)
                {
                    if(positions[closest] > positions[k])
                    {
                        closest = k;
                    }
                    
                }
            }
            if(closest == past)
            {break;}
            past = j;
            j = closest;
            
            distance[i]++;
                        
        }
    }
    for(numballz = 0; numballz < n; numballz++)
    {
        int init[numballz];
        for(int i = 0; i < numballz; i++)
        {
            init[i] = n - 1;
            for(int j = 0; j < n; j++)
            {
                if(distance[j] < distance[init[i]])
                {
                    init[i] = j;
                }
            }
            distance[init[i]] = n;
        }
        bool istouched[n];
        for(int o = 0; o < n; o++)
        {
            istouched[o] = false;
        }
        for(int ko = 0; ko< n; ko++)
        {
            for(int i = 0; i < numballz; i++)
            {
                
                int dist = 1000;
                int closest = (init[i] == n-1) ? init[i] - 1: init[i] + 1;
                istouched[init[i]] = true;
                int  j = init[i];
                for(int k = 0; k < n; k++){
                if(abs(positions[j] - positions[k])< dist)
                {
                    closest = k;
                    dist =abs(positions[j] - positions[k]);
                }
                else if(abs(positions[j] - positions[k]) == dist)
                {
                    if(positions[closest] > positions[k])
                    {
                        closest = k;
                    }
                }
              }
                init[i] = closest;
                istouched[init[i]] = true;
                
                
            }
            
            
        }
        bool flag = true;
        for(int i = 0; i < n; i++)
                {
                    flag = istouched[i];
                }
                if(flag)
                {
                    break;
                }
    }

    out << numballz << endl;
    return 0;
}