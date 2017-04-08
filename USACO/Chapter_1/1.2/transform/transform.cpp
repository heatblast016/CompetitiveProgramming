/*
ID: adiddee1
PROG: transform
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

bool compare(char mat1[10][10], char mat2[10][10], int size);
bool rotate90test(char mat1[10][10], char mat2[10][10], int size);
bool rotate180test(char mat1[10][10], char mat2[10][10], int size);
bool rotate270test(char mat1[10][10], char mat2[10][10], int size);
bool mirrortest(char mat1[10][10], char mat2[10][10], int size);
bool combotest(char mat1[10][10], char mat2[10][10], int size);

int main()
{
    ifstream in("transform.in");
    ofstream out("transform.out");
    int size;
    in >> size;
    in.get();
    char mat1[10] [10];
    char mat2[10] [10];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat1[i][j] = in.get();
        }
        in.get();
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat2[i][j] = in.get();
        }
        in.get();
    }
    if(rotate90test(mat1, mat2, size))
    {
        out << 1 << endl;
    }
    else if(rotate180test(mat1, mat2, size))
    {
        out << 2 << endl;
    }
    else if(rotate270test(mat1, mat2, size))
    {
        out << 3 << endl;
    }
    else if(mirrortest(mat1, mat2, size))
    {
        out << 4 << endl;
    }
    else if(combotest(mat1, mat2, size))
    {
        out << 5 << endl;
    }
    else if(compare(mat1, mat2, size))
    {
        out << 6 << endl;
    }
    else
    {
        out << 7 << endl;
    }
    in.close();
    out.close();
}

bool compare(char mat1[10][10], char mat2[10][10], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(mat1[i][j] != mat2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool rotate90test(char mat1[10][10], char mat2[10][10], int size)
{
    char mat3[10][10];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat3[j][size - i - 1] = mat1[i][j];
        }
    }   
    return compare(mat2, mat3, size);
}
bool rotate180test(char mat1[10][10], char mat2[10][10], int size)
{
    char mat3[10][10];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat3[j][size - i - 1] = mat1[i][j];
        }
    }   
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat1[j][size - i - 1] = mat3[i][j];
        }
    }
    return compare(mat2, mat1, size);
}
bool rotate270test(char mat1[10][10], char mat2[10][10], int size)
{
    char mat3[10][10];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat3[j][size - i - 1] = mat1[i][j];
        }
    }   
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat1[j][size - i - 1] = mat3[i][j];
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat3[j][size - i - 1] = mat1[i][j];
        }
    }
    return compare(mat2, mat3, size);
}
bool mirrortest(char mat1[10][10], char mat2[10][10], int size)
{
    char mat3[10][10];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat3[i][size - j - 1] = mat1[i][j];
        }
    }
    return compare(mat2, mat3, size);
}
bool combotest(char mat1[10][10], char mat2[10][10], int size)
{
    char mat3[10][10];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat3[i][size - j - 1] = mat1[i][j];
        }
    }
    if(rotate90test(mat3, mat2, size))
    {
        return true;
    }
    else if(rotate180test(mat3, mat2, size))
    {
        return true;
    }
    else if(rotate270test(mat3, mat2, size))
    {
        return true;
    }
    return false;
}
