#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
    int sum = 0, high = 0, c;
    ifstream f("output.txt");
    while (f >> c)
    {
        if (c > high)
        {
            high = c;
        }
        sum += c;
    }
    printf("Highest = %d \n Sum = %d", high, sum);
}