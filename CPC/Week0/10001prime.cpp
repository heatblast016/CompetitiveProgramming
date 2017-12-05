#include <iostream>
#include <math.h>  
using namespace std;

int main()
{
    long long numprime = 1;
    long long counter = 2;
    long long arrofprimes[10001];
    for(int i = 0; i < 10001; i++)
    {
        arrofprimes[i] = 2;
    }
    while(numprime < 10001)
    {
        counter++;
        bool isprime = true;
        for(int i = 0; i < numprime; i++)
        {
            if((counter % arrofprimes[i]) == 0)
            {
                isprime = false;
                break;
            }
        }
        if(isprime)
        {
            arrofprimes[numprime] = counter;
            numprime++;
        }
    }
    cout << counter << endl;
}