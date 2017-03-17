#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool bsearch(int key, int arr[], int size);
int main()
{
    ifstream in("haybales.in");
    ofstream out("haybales.out");
    int n, q;
    in >> n >> q;
    int a[q];
    int b[q];
    int intervals[n];
    in.get();
    for(int i = 0; i < n; i++)
    {
        in >> intervals[i];
    }
    sort(intervals, intervals + n);
    for(int i = 0; i < q; i++)
    {
        in >> a[i] >> b[i];
    }
    for(int i = 0; i < q; i++)
    {
        int counter = 0;
        for(int j = a[i]; j <= b[i]; j++)
        {
            if(bsearch(j, intervals, n))
            {
                counter++;
            }
        }
        out << counter << endl;
    }
    out.close();
    return 0;
}
bool bsearch(int key, int arr[], int size)
{
    int min = 0;
    int max = size - 1;
    while(min <= max)
    {
        int mid = min + ((max-min)/2);
        if(arr[mid] == key)
        {
            return true;
        }
        else if(arr[mid] <  key)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return false;
}