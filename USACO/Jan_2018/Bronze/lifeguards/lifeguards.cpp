#include <fstream>
#include <iostream>

using namespace std;

int main(void)
{
    ifstream in("lifeguards.in");
    ofstream out("lifeguards.out");
    int n = 0;
    in >> n;
    bool isonshift[n][1000];
    int amountofpeople[1000];
    int timealone[n];
    for(int i = 0; i < 1000; i++)
    {
        amountofpeople[i] = 0;
        for(int j = 0; j < n; j++)
        {
            isonshift[j][i] = false;
        }
    }
    for(int j = 0; j < n; j++)
    {
        int start = 0;
        int end = 0;
        in >> start >> end;
        for(int k = start; k < end; k++)
        {
            isonshift[j][k] = true;
            amountofpeople[k] += 1;
        }
    }
    for(int j = 0; j < n; j++)
    {
        timealone[j] = 0;      
    }
    for(int i = 0; i < 1000; i++)
    {
        if(amountofpeople[i] == 1)
        {
            for(int j = 0; j < n; j++)
            {
                if(isonshift[j][i])
                {
                    timealone[j]++;
                }
            }
        }
    }
    int minalonetime = 0;
    for(int i = 0; i < n; i++)
    {
        if(timealone[i] < timealone[minalonetime])
        {
            minalonetime = i;
        }
    }
    for(int j = 0; j < 1000; j++)
    {
        if(isonshift[minalonetime][j])
        {
            amountofpeople[j]--;
        }
    }
    int dayz = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(amountofpeople[i] > 0)
        {
            dayz++;
        }       
    }
    in.close();
    out << dayz << endl;
    out.close();
    return 0;
}