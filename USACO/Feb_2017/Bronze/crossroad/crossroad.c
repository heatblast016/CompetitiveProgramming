#include <stdio.h>
#include <stdlib.h>
FILE* in;
FILE* out;
int crossings;
typedef struct
{
    int id;
    int side;
} cow;
int main(void)
{
    crossings = 0;
    in = fopen("crossroad.in", "r");
    out = fopen("crossroad.out", "w");
    cow herd[10];
    int total;
    fscanf(in, "%d", &total);
    for(int i = 0; i < 10; i++)
    {
        herd[i].side = 2;
        herd[i].id = i+1;
    }
    for(int i = 0; i < total; i++)
    {
        int id;
        fscanf(in, "%d", &id);
        int side;
        fscanf(in, "%d", &side);
        if(herd[id - 1].side != side && herd[id - 1].side != 2)
        {
            herd[id - 1].side = side;
            crossings++;
        }
        else if(herd[id - 1].side == 2)
        {
            herd[id - 1].side = side;
        }
    }
    fprintf(out, "%d", crossings);
    fclose(in);
    fclose(out);
}