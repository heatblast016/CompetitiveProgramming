/*
ID: adiddee1
LANG: C++11
TASK: dualpal
*/
#include <fstream>
#include <algorithm>
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
int main(void)
{
    ifstream in("dualpal.in");
    ofstream out("dualpal.out");
    int n, s;
    in >> n >> s;
    in.close();
    s += 1;
    int num = 0;
    while(num < n)
    {
        int counter = 0;
        for(int i = 2; i <= 10; i++)
        {
            string pal = tobase((s), i);
            string pal2 = pal;
            reverse(pal2.begin(), pal2.end());
            if(pal2 == pal)
            {
                counter++;
            }
        }
        if(counter > 1)
        {
            num++;
            out << s << endl;
        }
        s++;
    }
    out.close();
}