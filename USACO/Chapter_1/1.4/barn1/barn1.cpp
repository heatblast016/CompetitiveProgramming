/*
ID: adiddee1
LANG: C++11
TASK: barn1
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main(void)
{
    ifstream in("barn1.in");
    ofstream out("barn1.out");
    int m, s, c;
    in >> m >> s >> c;
    int boardsused = c;
    int unoccupiedcovered = c;
    int positions[c];
    for(int j = 0; j < c; j++)
    {
        in >> positions[j];
    }
    std::sort(positions, positions + c);
    int sol[c - 1];
    for(int i = 0; i < c - 1; i++)
    {
        sol[i] = positions[i + 1] - positions[i] - 1;;
    }
    std::sort(sol, sol + c - 1);
    for(int i = 0; i < c - 1; i++)
    {
        if(boardsused <= m)
        {
            break;
        }
        boardsused -= 1;
        unoccupiedcovered += sol[i];
    }
    out << unoccupiedcovered << endl;
    out.close();
    in.close();
}