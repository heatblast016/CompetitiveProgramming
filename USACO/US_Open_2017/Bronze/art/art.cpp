#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    ifstream in ("art.in");
    FILE* out = fopen("art.out", "w");
    int size;
    in >> size;
    in.get();
    bool exists[size + 1];
    bool orig[size + 1];
    int originals = 0;
    for(int i = 0; i < size + 1; i++)
    {
        exists[i] = false;
        orig[i] = true;
    }
    int painting [size + 2] [size + 2];
    for(int i = 0; i < size + 2; i++)
    {
        for(int j = 0; j < size + 2; j++)
        {
            painting[i][j] = 0;
        }
    }
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            painting[i][j] = in.get() - 80;
        }
        in.get();
    }
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            exists[painting[i][j]] = true;
        }
    }
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            for(int k = 1; k <= 9; k++)
            {
                if(k == painting[i][j])
                {
                    continue;
                }
                int diffcount = 0;
                if(painting[i - 1][j] == k)
                {
                    diffcount++;
                }
                if(painting[i + 1][j] == k)
                {
                    diffcount++;
                }
                if(painting[i][j - 1] == k)
                {
                    diffcount++;
                }
                if(painting[i][j + 1] == k)
                {
                    diffcount++;
                }
                if(diffcount > 1)
                {
                    orig[painting[i][j]] = false;
                }
            }
        }
    }
    for(int i = 1; i <= 9; i++)
    {
        originals += (exists[i] == true && orig[i] == true) ? 1 : 0;
    }    
    fprintf(out, "%d\n", originals);
    fclose(out);
    in.close();
}