#include <stdio.h>
#include <string.h>
struct Row
{
    char state[256];
    int confirmed, active, recovered,
        deceased, tested, vaccinated, population;
    float ratio;
};
typedef struct Row Csv[256];

int load(char *sourcePath, Csv target)
{
    FILE *csvFile = fopen(sourcePath, "r");
    char lineBuffer[256];
    int lineNo = 0;
    fgets(lineBuffer, sizeof(lineBuffer), csvFile);
    while (fgets(lineBuffer, sizeof(lineBuffer), csvFile))
    {
        sscanf(lineBuffer, "%s %d %d %d %d %d %d %d", &target[lineNo].state, &target[lineNo].population, &target[lineNo].confirmed, &target[lineNo].active, &target[lineNo].recovered, &target[lineNo].deceased, &target[lineNo].tested, &target[lineNo].vaccinated);
        lineNo++;
    }
    fclose(csvFile);
    return lineNo;
}
int partition(Csv arr, int n, float *(*getValue)(Csv, int))
{
    float pivot = *getValue(arr, n - 1);
    int i = 0, j = -1;
    while (i < n)
    {
        if (*getValue(arr, i) < pivot)
        {
            j++;
            struct Row c = arr[j];
            arr[j] = arr[i];
            arr[i] = c;
        }
        i++;
    }
    j++;
    struct Row c = arr[j];
    arr[j] = arr[i];
    arr[i] = c;
    return j;
}
void sort(Csv arr, int n, float *(*getValue)(Csv, int))
{
    if (n <= 1)
        return;
    int pivotIdx = partition(arr, n, getValue);
    sort(arr, pivotIdx, getValue);
    sort(arr + pivotIdx + 1, n - pivotIdx - 1, getValue);
}
float *getRatio(Csv arr, int i)
{
    return &(arr[i].ratio);
}
float *dum(float arr[], int i)
{
    return &(arr[i]);
}
void show(Csv storage, int lines)
{
    printf("State, Population, Confirmed, Active, Recovered, Deceased, Tested, Vaccinated, Ratio\n");
    for (size_t i = 0; i < lines; i++)
        printf("%s, %d, %d, %d, %d, %d, %d, %d, %f\n", storage[i].state, storage[i].population, storage[i].active, storage[i].active, storage[i].recovered, storage[i].deceased, storage[i].tested, storage[i].vaccinated, storage[i].ratio);
}
void showReverse(Csv storage, int lines)
{
    printf("State, Population, Confirmed, Active, Recovered, Deceased, Tested, Vaccinated, Ratio\n");
    for (int i = lines - 1; i >= 0; i--)
        printf("%s, %d, %d, %d, %d, %d, %d, %d, %f\n", storage[i].state, storage[i].population, storage[i].active, storage[i].active, storage[i].recovered, storage[i].deceased, storage[i].tested, storage[i].vaccinated, storage[i].ratio);
}
int main(int argc, char *argv[])
{
    Csv storage;
    int lines = load("covid-state-data.txt", storage);
    for (int i = 0; i < lines; i++)
        storage[i].ratio = (float)(storage[i].vaccinated) / storage[i].population;
    sort(storage, lines - 1, getRatio);
    printf("Sorted in descending order of ratio of vaccinated to population\n");
    showReverse(storage, lines);
    for (int i = 0; i < lines; i++)
        storage[i].ratio = (float)(storage[i].recovered) / storage[i].confirmed;
    sort(storage, lines - 1, getRatio);
    printf("\nSorted in ascending order of ratio of recovered to confirmed\n");
    show(storage, lines);
    for (int i = 0; i < lines; i++)
        storage[i].ratio = (float)(storage[i].tested) / storage[i].population;
    sort(storage, lines - 1, getRatio);
    printf("\nSorted in ascending order of ratio of tested to population\n");
    show(storage, lines);
    return 0;
}