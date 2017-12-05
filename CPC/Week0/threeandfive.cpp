#include <iostream>

int main(void)
{
    int count = 0;
    for(int i = 3; i < 1000; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            count += i;
        }
    }
    std::cout << count << std::endl;
}