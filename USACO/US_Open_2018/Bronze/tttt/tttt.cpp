#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(std::vector<char> one, std::vector<char> j, int size)
{
    sort(one.begin(), one.end());
    
    sort(j.begin(), j.end());
    for(int i = 0; i < size ; i++)
    {
        if(one[i] != j[i])
        {
            return false;
        }
    }
    return true;
}
bool isnt_there(std::vector<std::vector<char>> one, std::vector<char> j, int size, int size2)
{
    for(int i = 0; i < size; i++)
    {
        if(compare(one[i], j, size2))
        {
            return false;
        }
    }
    return true;
}
// I looked up usage of std::std::vector as I wasn't too familiar with it
int main(void)
{
    ifstream in("tttt.in");
    ofstream out("tttt.out");
    int num1 = 0;
    int num2 = 0;
    int dummy = 0;
    //read input
    char board[3][3];
    std::vector<std::vector<char>> tracker1 = {};
    std::vector<std::vector<char>> tracker2 = {};
    for(int i = 0; i < 3; i++)
    {
        for(int  j= 0; j <3 ; j++)
        {
            in >> board[i][j];
        }
    }
    in.close();
    // check vertical and horizontal
    for(int i = 0; i < 3; i++)
    {
        std::vector<char> playersv = {};
        std::vector<char> playersh = {};
        for(int j = 0; j < 3; j++)
        {
            if(find(playersh.begin(), playersh.end(), board[i][j]) == playersh.end()){ playersh.push_back( board[i][j]);}
            if(find(playersv.begin(), playersv.end(), board[j][i]) == playersv.end()){ playersv.push_back( board[j][i]);}
        }
        // check whether teams of one or teams of 2 won
        if(playersv.size() == 1)
        {
            if(isnt_there(tracker1, playersv, tracker1.size(), playersv.size()))
            {
                num1++;
                tracker1.push_back(playersv);
            }
        }
        else if(playersv.size() == 2)
        {
            if(isnt_there(tracker2, playersv, tracker2.size(), playersv.size()))
            {
                num2++;
                
                tracker2.push_back(playersv);
            }
        }
        if(playersh.size() == 1)
        {
            if(isnt_there(tracker1, playersh, tracker1.size(), playersh.size()))
            {
                num1++;
                tracker1.push_back(playersh);
            }
        }
        else if(playersh.size() == 2)
        {
            if(isnt_there(tracker2, playersh, tracker2.size(), playersh.size()))
            {
                num2++;
                
                tracker2.push_back(playersh);
            }
        }
    }
    std::vector<char> playersd1 = {};
    std::vector<char> playersd2 = {};
    for(int i = 0; i < 3; i++)
    {
        if(find(playersd1.begin(), playersd1.end(), board[i][i]) == playersd1.end()){ playersd1.push_back(board[i][i]) ;}
        if(find(playersd2.begin(), playersd2.end(), board[i][i]) == playersd2.end()){playersd2.push_back(board[i][2-i]);}
        
    }
    if(playersd1.size() == 1)
    {
        if(isnt_there(tracker1, playersd1, tracker1.size(), playersd1.size()))
        {
            num1++;
            tracker1.push_back(playersd1);
        }
    }
    else if(playersd1.size() == 2)
    {
        if(isnt_there(tracker2, playersd1, tracker2.size(), playersd1.size()))
        {
            num2++;
            tracker2.push_back(playersd1);
        }
    }
    if(playersd2.size() == 1)
    {
        if(isnt_there(tracker1, playersd2, tracker1.size(), playersd2.size()))
        {
            num1++;
            tracker1.push_back(playersd2);
        }
    }
    else if(playersd2.size() == 2)
    {
        if(isnt_there(tracker2, playersd2, tracker2.size(), playersd2.size()))
        {
            num2++;
            tracker2.push_back(playersd2);
        }
    }
    out << num1 << endl << num2 << endl;
    out.close();
}