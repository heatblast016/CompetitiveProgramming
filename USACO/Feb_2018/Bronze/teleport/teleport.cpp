#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isefficient(int a, int b, int x, int y)
{
    if(abs(min(x,y) - min(a, b)) + abs(max(x,y) - max(a,b)) < abs(a - b))
    {
        return true;
    }
    return false;
}
int main()
{
    ifstream in("teleport.in");
    ofstream out("teleport.out");
    int a, b, x, y;
    in >> a >> b >> x >> y;
    in.close();
    if(isefficient(a,b,x,y))
    {
        out << abs(min(x,y) - min(a, b)) + abs(max(x,y) - max(a,b)) << endl;
    }
    else
    {
        out << abs(a-b) << endl;
    }
    out.close();
    return 0;
}