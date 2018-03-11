/*
ID: adiddee1
LANG: C++11
TASK: palsquare
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

inline char to_char(int c){
 if(c >= 10) return c - 10 + 'A';
 return c + '0';
}

string tobase(int num, int base){
 string ret;
 int div = base;

while(div < num){
  div *= base;
}
div /= base;
 while(true){
  ret += to_char(num / div);
  // get remainder
  num = num % div;
  // next
  if(div < 2) break;
  div /= base;
 }
 return ret;
}
int main()
{
    ifstream in("palsquare.in");
    ofstream out("palsquare.out");
    int b;
    in >> b;
    in.close();
    for (int i = 1; i <= 300; i++)
    {
        string pal = tobase(i*i, b);
        string pal2 = pal;
        reverse(pal2.begin(), pal2.end());
        if (pal == pal2)
        {
            out << tobase(i,b) << " " << pal << endl;
        }
    }
    out.close();
}