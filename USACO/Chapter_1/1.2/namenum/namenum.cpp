/*
ID: adiddee1
PROG: namenum
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <list>
#include<algorithm>
void dfs(int size, int depth, std::string outname, std::list<std::string> dict, std::string num, std::string output, char tt [8] [3]);

int main(void)
{
    std::ifstream in("namenum.in");
    std::ifstream dict("dict.txt");
    std::string outname = "namenum.out";
    std::list<std::string> dictionary;
    for(int i = 0; i < 5000; i++)
    {
        if(dict.eof())
        {
            break;
        }
        std::string element;
        std::getline(dict, element);
        dictionary.push_back(element);
    }
    dict.close();
    char touch_tone[8][3] = {
    {'A','B','C'},
    {'D','E','F'},
    {'G','H','I'},
    {'J','K','L'},
    {'M','N','O'},
    {'P','R','S'},
    {'T','U','V'},
    {'W','X','Y'}
    };
    std::string num;
    in >> num;
    in.close();
    std::string outp = num;
    dfs(num.length(), num.length(), outname, dictionary, num, outp, touch_tone);
    
}
void dfs(int size, int depth, std::string outname, std::list<std::string> dict, std::string num, std::string output, char tt [8] [3])
{
    for(int i = 0; i < 2; i++)
    {
        output[size - depth] = (tt[(num[size - depth] - 50)] [i]);
        if(depth == 1)
        {
            std::ofstream out(outname);
            if((std::find(dict.begin(), dict.end(), output)) != dict.end())
            {
                out << output << std::endl;
            }
            out.close();
        }
        dfs(size, depth, outname, dict, num, output, tt);
    }
}
