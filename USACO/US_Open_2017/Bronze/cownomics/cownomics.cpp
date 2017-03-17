#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    FILE* in = fopen("cownomics.in", "r");
    ofstream out("cownomics.out");
    int numcows;
    int sg;
    int numspec = 0;
    fscanf(in, "%d %d\n", &numcows, &sg);
    bool isspecial[sg];
    for(int i = 0; i < sg; i++)
    {
        isspecial[i] = true;
    }
    char* spotty[numcows];
    char* plain[numcows];
    for(int i = 0; i < numcows; i++)
    {
        spotty[i] = (char*) malloc(sg);
        fscanf(in, "%s\n", spotty[i]);
    }     
    for(int i = 0; i < numcows; i++)
    {
        plain[i] = (char*) malloc(sg);
        fscanf(in, "%s\n", plain[i]);
    }
    for(int i = 0; i < sg; i++)
    {
        for(int j = 0; j < numcows; j++)
        {
            for(int k = 0; k < numcows; k++)
            {
                if(spotty[j][i] == plain[k][i])
                {
                    isspecial[i] = false;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < sg; i++)
    {
        if(isspecial[i])
        {
            numspec++;
        }
    }
    out << numspec << endl;
    fclose(in);
    out.close();
}