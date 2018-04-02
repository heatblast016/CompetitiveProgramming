#include <fstream>
#include <algorithm>
#include <iostream>


using namespace std;
int main()
{
    ifstream in("milkorder.in");
    ofstream out("milkorder.out");
    int m, n, k;
    in >> n >> m >> k;
    int cows[n];
    int hierarchy[m];
    bool placed = false;
    int socialindexof1 = -1;
    bool isplaced[m];
    bool issocial[k];
    int positionsofpreplaced[k];
    int socialpreplaced[k];
    bool is1social = false;
    for(int i = 0; i < n; i++)
    {
        cows[i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        in >> hierarchy[i];
        isplaced[i] = false;
        if(hierarchy[i] == 1)
        {
            is1social = true;
            socialindexof1 = i;
        }
        
    }
    for(int i = 0; i < k; i++)
    {
        bool isssocial = false;
        int p, c;
        in >> c >> p;
        cows[p - 1] = c;
        for(int j = 0; j < m; j++)
        {
            if(hierarchy[j] = c)
            {
                isssocial = true;
                socialpreplaced[i] = j;
                break;
            }
            else
            {
                socialpreplaced[i] = -1;
            }
        }
        issocial[i] = isssocial;
        positionsofpreplaced[i] = p;
    }
    
    for(int i = 0; i < k; i++)
    {
        cout << i << endl;
        if(issocial[i])
        {   
            if(is1social)
            {
                int counter;
                int socialcounter;
                counter  = (socialindexof1 < socialpreplaced[i]) ? 0 : positionsofpreplaced[i];
                socialcounter  = (socialindexof1 < socialpreplaced[i]) ? 0 : socialpreplaced[i];
                while(socialcounter < m)
                {
                    if(cows[counter] == 0)
                    {
                        if(hierarchy[socialcounter == 1])
                        {
                            placed = true;
                        }
                        if(!isplaced[socialcounter])
                        {
                            cows[counter] = hierarchy[socialcounter];
                            counter++;
                            isplaced[socialcounter] = true;
                        }
                        socialcounter++;
                    }
                    else
                    {
                        counter++;
                        continue;
                    }
                }
            }
            else
            {
                int counter;
                int socialcounter;
                counter = positionsofpreplaced[i];
                socialcounter  = socialpreplaced[i];
                while(socialcounter >= 0 && counter >= 0)
                {
                    if(cows[counter] == 0)
                    {
                        if(!isplaced[socialcounter])
                        {
                            cows[counter] = hierarchy[socialcounter];
                            counter--;
                        }
                        socialcounter--;
                    }
                    else
                    {
                        counter--;
                        continue;
                    }
                }    
            }
        }
        else
        {
            continue;
        }
    }
    if(isplaced)
    {
        for(int i = 0; i < n; i++)
        {
            if(cows[i] == 1)
            {
                out << i+1 << endl;
            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(cows[i] == 0)
            {
                out << i+1 << endl;
            }
            else
            {
                
            }
        }
    }
    for(int j = 0; j < n; j++)
    {
        out << cows[j] << endl;
    }
    in.close();
    out.close();
    return 0;
}