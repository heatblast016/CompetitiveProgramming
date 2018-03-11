/*
ID: adiddee1
LANG: C++11
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
int matches = 0;
int charactertoint(char ch)
{
    if(ch == 'A' || ch == 'B' || ch == 'C'){
        return 2;
    }
    if(ch == 'D' || ch == 'E' || ch == 'F'){
        return 3;
    }
    if(ch == 'G' || ch == 'H' || ch == 'I'){
        return 4;
    }
    if(ch == 'J' || ch == 'K' || ch == 'L'){
        return 5;
    }
    if(ch == 'M' || ch == 'N' || ch == 'O'){
        return 6;
    }
    if(ch == 'P' || ch == 'R' || ch == 'S'){
        return 7;
    }
    if(ch == 'T' || ch == 'U' || ch == 'V'){
        return 8;
    }
    if(ch == 'W' || ch == 'X' || ch == 'Y'){
        return 9;
    }
}


long long convert(string s)
{
    long long num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        char x = s.at(i);
        num += charactertoint(x) * pow(10, s.size() - i -1);
    }
    return num;
}
int main()
{
    ifstream in("namenum.in");
    ofstream out("namenum.out");
    ifstream dict("dict.txt");
    long long num = 0;
    in >> num;
    in.close();
    string numbar = std::to_string(num);
    int size = numbar.size();
    string st;
    while(dict >> st)
    {
        if(st.size() == size && convert(st) == num)
        {
            out << st << endl;
            matches++;
        }
    }
    if(matches == 0)
    {
        out << "NONE" << endl;
    }
    out.close();
    dict.close();
}