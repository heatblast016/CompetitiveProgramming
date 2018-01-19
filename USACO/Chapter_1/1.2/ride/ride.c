/*
ID: adiddee1
PROG: ride
LANG: C
*/
//I looked up standard library function usage
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char* num1;
char* num2;
int prod1 = 1;
int prod2 = 1;
int mod1;
int mod2;

int main(void)
{
    num1 = malloc(7 * sizeof(char));
    num2 = malloc(7 * sizeof(char));
    FILE* input = fopen("ride.in", "r");
    FILE* output = fopen("ride.out", "w");
    fscanf(input, "%s\n", num1);
    fscanf(input, "%s\n", num2);
    for(int i = 0; isupper(num1[i]); i++)
    {
        prod1 *= (num1[i] - 64);
    } 
    for(int i = 0; isupper(num2[i]); i++)
    {
        prod2 *= (num2[i] - 64);
    }
    if(prod1 % 47 == prod2 % 47)
    {
        fprintf(output, "GO\n");
    }
    else
    {
        fprintf(output, "STAY\n");
    }
    free(num1);
    free(num2);
    fclose(input);
    fclose(output);
    return 0;
}
