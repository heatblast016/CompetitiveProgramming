#include <fstream>
#include <algorithm>
#define x1 0
#define y1 1
#define x2 2
#define y2 3 
#define lawnmower coordinates[0]
#define food coordinates[1]

int main(void)
{
    std::ifstream in("billboard.in");
    std::ofstream out("billboard.out");
    int coordinates[x2][4];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++)
            in >> coordinates[i][j];
    in.close();
    // check for complete obscuring
    if((lawnmower[y1] >= food[y1] && lawnmower[y2] <= food[y2]) && (lawnmower[x1] >= food[x1] && lawnmower[x2] <= food[x2]))
    {
        out << 0 << std::endl;
    }
    else if(lawnmower[y1] >= food[y1] && lawnmower[y2] <= food[y2])
    {
        if(food[x2] >= lawnmower[x1] && food[x2] < lawnmower[x2] && food[x2] <= lawnmower[x2])
        {
            out << (coordinates[0][3] - coordinates[0][1]) * (lawnmower[x2] - food[x2]) << std::endl;
        }
        else if(food[x2] > lawnmower[x2] && food[x1] <= lawnmower[x2] && food[x1] >= lawnmower[x1])
        {
            out << (coordinates[0][3] - coordinates[0][1]) * (food[x1] - lawnmower[x1]) << std::endl;
        }
        else
        {
            out << ((coordinates[0][2] - coordinates[0][0])) * ((lawnmower[y2] - lawnmower[y1])) << std::endl;
        }
    }
    else if (lawnmower[x1] >= food[x1] && lawnmower[x2] <= food[x2])
    {
        if(food[y2] >= lawnmower[y1] && food[y1] < lawnmower[y1] && food[y2] <= lawnmower[y2])
        {
            out << (coordinates[0][2] - coordinates[0][0]) * (lawnmower[y2] - food[y2]) << std::endl;
        }
        else if(food[y2] > lawnmower[y2] && food[y1] <= lawnmower[y2] && food[y1] >= lawnmower[y1])
        {
            out << (coordinates[0][2] - coordinates[0][0]) * (food[y1] - lawnmower[y1]) << std::endl;
        }
        else
        {
            out << ((coordinates[0][2] - coordinates[0][0])) * ((lawnmower[y2] - lawnmower[y1])) << std::endl;
        }
    }
    else
    {
        out << ((coordinates[0][2] - coordinates[0][0])) * ((lawnmower[y2] - lawnmower[y1])) << std::endl;
    }
    out.close();
    return 0;
}