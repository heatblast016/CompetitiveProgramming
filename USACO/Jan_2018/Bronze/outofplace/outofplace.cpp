#include <fstream>
using namespace std;

int dfs(int depth, int array[], int arr2[], int size, int minimum);
int main(void)
{
    ifstream in("outofplace.in");
    ofstream out("outofplace.out");
    int minswaps = 0;
    int n = 0;
    in >> n;
    int array[n];
    for(int i = 0; i < n; i++)
        in >> array[n];
    int minimum ;
    dfs(0, array, array, n, minimum);
    out << minimum<< endl;
    out.close();
    in.close();
    
}
int dfs(int depth, int array[],int arr2[], int size, int minimum)
{
    if(depth > size*size)
    {
        return size*size;
    }
    int fn = 1;
    for(int k = 0; k < size - 1; k++)
    {
        if(array[k] > array[k+1])
        {
            fn = 0;
            break;
        }
    }
    if(fn == 1)
    {
        return depth;
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size - 1; k++)
            {
                arr2[k] = array[k];
            }
            arr2[i] = array[j];
            arr2[j] = array[i];
            int me = dfs(depth + 1, arr2, arr2, size, minimum);
            minimum = (me<minimum) ? me : minimum;
        }
    }
    return minimum;
}