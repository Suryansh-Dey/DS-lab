#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    ofstream f("output.txt");
    int n, low, high;
    scanf("%d", &n);
    scanf("%d", &low);
    scanf("%d", &high);
    int count = 0;
    f << n << ' ';
    while (count++ != n)
    {
        int c = rand() + rand();
        int result = low + c % (high - low);
        f << result << " ";
    }
    return 0;
}