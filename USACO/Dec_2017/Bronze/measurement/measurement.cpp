#include <iostream>
#include <fstream> 
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("measurement.in");
	ofstream out("measurement.out");
	int production[3][101];
	for(int f = 0; f < 101; f++)
	{
		for(int j = 0; j < 3; j++)
			production[j][f] = 7;
	}
	int entries = 0;
	in >> entries;
	int max = 0;
	int changes = 1;
	for(int j = 0; j < entries; j++)
	{
		int day = 0;
		in >> day;
		string name;
		in >> name;
		int gain = 0;
		in >> gain;
		if(name == "Mildred")
		{
			for(int i = day; i < 101; i++)
			{		
				production [0] [i] += gain;
			}
		} 
		if(name == "Elsie")
		{
			for(int i = day; i < 101; i++)
			{		
				production [1] [i] += gain;
			}
		} 
		if(name == "Bessie")
		{
	
			for(int i = day; i < 101; i++)
			{		
				production [2] [i] += gain;
			}
		} 
	}
	for(int f = 0; f < 100; f++)
	{	
		int maximum = std::max(production [0] [f], std::max(production [1] [f],production [2] [f]));
		int maximum2 = std::max(production [0] [f+1], std::max(production [1] [f+1],production [2] [f+1]));
		for (int j = 0; j < 3; j++)
		{
			if(production[j][f+1] == maximum2 && production[j][f] < maximum)
			{
				changes++;
			}
		}
	}
	out << changes << endl;
	return 0;
}
