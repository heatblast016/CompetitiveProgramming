/*
ID: adiddee1
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
class bead
{
    public:
    bead* front;
    bead* back;
    char color;
    bool takenoff;
};
int main(void)
{
    FILE *in = fopen("beads.in", "r");
    ofstream out("beads.out");
    int n;
    int count = 0;
    fscanf(in, "%d\n", &n);
    bead* head;
    bead* current;
    head = new bead();
    head -> front = new bead();
    current = head -> front;
    head -> color = fgetc(in);
    head -> takenoff = false;
    bead* previous = head;
    for(int i = 2; i < n; i++)
    {
        current -> back = previous;
        current -> front = new bead();
        current -> color = fgetc(in);
        current -> takenoff = false;
        previous = current;
        current = current -> front;
    }
    current -> front = head;
    current -> back = previous;
    current -> takenoff = false;
    current -> color = fgetc(in);
    head -> back = current;
    bead* lower = head;
    bead* upper = head -> front;
    for(int i = 0; i < n; i++)
    {
        bead* temp = head;
        for(int j = 0; j < n; j++)
        {
            temp -> takenoff = false;
            temp = temp -> front;
        }
        char uppercolor = upper -> color;
        char lowercolor = lower -> color;
        int counter = 0;
        bead* cur1 = upper;
        bead* cur = lower;
        for(int j = 0; j < n; j++)
        {
            if(uppercolor == 'w' && cur1 -> color != 'w')
            {
                uppercolor = cur1 -> color;
            }
            if((cur1 -> color == uppercolor) || (cur1 -> color == 'w'))
            {
                counter++;
                cur1 -> takenoff = true;
                cur1 = cur1 -> front;
            }
            else
            {
                break;
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(lowercolor == 'w' && cur -> color != 'w')
            {
                lowercolor = cur -> color;
            }
            if((cur -> color == lowercolor || cur -> color == 'w') && cur -> takenoff != true)
            {
                cur -> takenoff = true;
                counter++;
                cur = cur -> back;
            }
            else
            {
                break;
            }
        }
        count = (count < counter) ? counter : count;
        lower = upper;
        upper = upper -> front;
    }
    out << count << endl;
    fclose(in);
    out.close();
    return 0;
  
}
