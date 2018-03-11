/*
ID: adiddee1
LANG: C++11
TASK: milk
*/
#include <iostream>
#include <fstream>
//implementing merge sort myself just to test my knowledge of it
using namespace std;
void merge(int arr[][2], int l, int r, int m)
{
    int n1 = m - l + 1;
    int n2 =  r - m;
    int arr1[n1][2];
    int arr2[n2][2];
    for(int i = 0; i < n1; i++)
    {
        arr1[i][0] = arr[l+i][0];
        arr1[i][1] = arr[l+i][1];
    }
    for(int i = 0; i < n1; i++)
    {
        arr2[i][0] = arr[m+i+1][0];
        arr2[i][1] = arr[m+i+1][1];
    }
    int i = 0, j =0 , lol = l;
    while(i < n1 && j < n2 )
    {
        if(arr1[i][0] < arr2[j][0])
        {
            arr[lol][0] = arr1[i][0];
            arr[lol][1] = arr1[i][1];
            i++;
        }
        else
        {
            arr[lol][0] = arr2[j][0];

            arr[lol][1] = arr2[j][1];
            j++;
        }
        lol++;
    }
    while(i < n1)
    {
        arr[lol][0] = arr1[i][0];
        arr[lol][1] = arr1[i][1];
        i++;
        lol++;
    }
    while(j < n2)
    {
        arr[lol][0] = arr2[j][0];
        arr[lol][1] = arr2[j][1];
        j++;
        lol++;
    }
}
void sort(int l, int r, int arr[][2])
{
    int m = l+(r-l)/2;
    if(l <r)
    {
        sort(l, m, arr);
        sort(m+1, r, arr);
        merge(arr, l, r, m);
    }
}
int main()
{
    ifstream in("milk.in");
    ofstream out("milk.out");
    int n, m;
    in >> n >> m;
    int arr[m][2];
    for(int i = 0; i < m; i++)
    {
        in >> arr[i][0] >> arr[i][1];
    }
    in.close();
    sort(0, m-1, arr);
    int price = 0;
    for(int i = 0; i < m; i++)
    {
        
        if(arr[i][1] <= n)
        {
            price += (arr[i][0] * arr[i][1]);
            n -= arr[i][1];
            arr[i][1] = 0;
        }
        else
        {
            for(int j = 0; j < n; j++)
            {
                price += arr[i][0];
            }
            n = 0;
        }
        if(n == 0)
        {
            break;
        }
    }
    out << price << endl;
    out.close();
}