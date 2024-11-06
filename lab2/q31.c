#include <stdio.h>
#include <string.h>
struct Row
{
    char state[256];
    int confirmed, active, recovered,
        deceased, tested, vaccinated, population;
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

int main(int argc, char *argv[])
{
    Csv storage;
    int lines = load("covid-state-data.txt", storage);  
    FILE *csvFile = fopen("covid-state-data.csv", "w");
    fprintf(csvFile, "State, Population, Confirmed, Active, Recovered, Deceased, Tested, Vaccinated\n");
    for (size_t i = 0; i < lines; i++)
        fprintf(csvFile, "%s, %d, %d, %d, %d, %d, %d, %d\n", storage[i].state, storage[i].population, storage[i].active, storage[i].active, storage[i].recovered, storage[i].deceased, storage[i].tested, storage[i].vaccinated);
    fclose(csvFile);
    printf("File saved in csv format");
    return 0;
}