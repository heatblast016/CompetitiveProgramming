#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool overlap(int truck[4], int billboard[4]);
int area(int figure[4]);
int overarea(int truck[4], int billboard[4]);

int main()
{
	ifstream in("billboard.in");
	ofstream out("billboard.out");
	int truck[4];
	int bill1[4];
	int bill2[4];
	for(int i = 0; i < 4; i++)
	{
		in >> bill1[i];
	}
	for(int i = 0; i < 4; i++)
	{
		in >> bill2[i];
	}
	for(int i = 0; i < 4; i++)
	{
		in >> truck[i];
	}
	in.close();
	int viewable = ((area(bill1) + area(bill2)) - (overarea(truck, bill1) + overarea(truck, bill2)));
	out << viewable << endl;
	out.close();
}
int area(int figure[4])
{
	return ((figure[2] - figure[0]) * (figure[3] - figure[1]));
}
int overarea(int truck[4], int billboard[4])
{
	int area = 0;
	int minconstx = min(truck[0], billboard[0]);
	int minconsty = min(truck[1], billboard[1]);
	int xsize = (max(truck[2], billboard[2]) - min(truck[0], billboard[0]));
	int ysize = max(truck[3], billboard[3]) - min(truck[1], billboard[1]);
	int oversquare[xsize][ysize];
	for(int i = 0; i < xsize; i++)
		for(int j = 0; j < ysize; j++)
			oversquare[i][j] = 0;
	for (int i = 0; i < xsize; i++)
	{
		for (int j = 0; j < ysize; j++)
		{
			if((i+minconstx >= truck[0] && i + minconstx < truck[2])&&(j+minconsty >= truck[1] && j + minconsty < truck[3]))
			{
				oversquare[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < xsize; i++)
	{
		for (int j = 0; j < ysize; j++)
		{
			if((i+minconstx >= billboard[0] && i + minconstx < billboard[2])&&(j+minconsty >= billboard[1] && j + minconsty < billboard[3]))
			{
				if(oversquare[i][j] == 1) { area++;}
			}
		}
	}
	return area;
}
