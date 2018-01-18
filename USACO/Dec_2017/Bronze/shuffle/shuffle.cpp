#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("shuffle.in");
	ofstream out("shuffle.out");
	int size = 0;
	in >> size;
	int shufflepos[size];
	int sf[size];
	for(int i = 0; i < size; i++)
	{
		int value;
		in >> value;
		shufflepos[value - 1] = i;
	}
	for( int i = 0; i < size; i++)
	{
		int value = 0;
		in >> value;
		sf[i] = value;
	}
	int buffer[size];
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < size; j++)
		{
			buffer[j] = sf[j];
		}
		for(int j = 0; j < size; j++)
		{
			sf[shufflepos[j]] = buffer[j];
		}
	}
	for(int i = 0; i < size; i++)	
	{
		out << sf[i] << endl;
	}
	in.close();
	out.close();
}
