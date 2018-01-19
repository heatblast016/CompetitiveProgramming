/*
ID: adiddee1
PROG: milk2
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("milk2.in");
    ofstream out("milk2.out");
    int n;
    int greatest, least;
    int count = 0;
    int count2 = 0;;
    in >> n;
    int start[n];
    int end[n];
    int greatersort[n];
    int lesssort[n];
    for(int i = 0; i < n; i++)
    {
        int temp;
        int temp2;
        in >> temp2 >> temp;
        start[i] = temp2;
        lesssort[i] = temp2;
        end[i] = temp;
        greatersort[i] = temp;
    }
    sort(greatersort, greatersort + n);
    sort(lesssort, lesssort + n);
    greatest = greatersort[n - 1];
    least = lesssort[0];
    int timemilking = 0;
    int timefree = 0;
    for(int i = least; i < greatest; i++)
    {
        bool milking = false;
        for(int j = 0; j < n; j++)
        {
            if(i >= start[j] && i < end[j])
            {
                milking = true;
                break;
            }
        }
        if(milking)
        {
            timefree = 0;
            timemilking++;
            if(timemilking > count)
            {
                count = timemilking;
            }
        }
        else if(!milking)
        {
            timemilking = 0;
            timefree++;
            if(timefree > count2)
            {
                count2 = timefree;
            }
        }
    }
    out << count << ' ' << count2 << endl;
    in.close();
    out.close();
    return 0;
}