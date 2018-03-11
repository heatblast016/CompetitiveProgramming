#include <fstream>
#include <cmath>

int main(void)
{
    std::ifstream in("leadgame.in");
    std::ofstream out("leadgame.out");
    int n;
    in >> n;
    int score1, score2;
    int maxlead = 0;
    int winningplayer = 1;
    for(int i = 0; i < n; i++)
    {
        in >> score1 >> score2;
        if(score1 > score2)
        {
            if(score1 - score2 > maxlead)
            {
                winningplayer = 1;
                maxlead = score1-score2;
            }
        }
        else
        {
            if(score2 - score1 > maxlead)
            {
                winningplayer = 2;
                maxlead = score2-score1;
            }

        }
    }
    in.close();
    out << winningplayer << " " << maxlead << std::endl;




    return 0;
}