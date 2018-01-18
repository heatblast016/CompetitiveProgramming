#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("square.in");
	ofstream out("square.out");
	int xyvalue[2][4];
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 4; j++)
			in >> xyvalue[i][j];
	int side = max((max(xyvalue[1][2],xyvalue[0][2]) - min(xyvalue[1][0],xyvalue[0][0])),(max(xyvalue[1][3],xyvalue[0][3]) - min(xyvalue[1][1],xyvalue[0][1])));
	out << side*side << endl;
	out.close();
	in.close();
}
