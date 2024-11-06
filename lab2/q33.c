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
void showVaccinatedPopulation(Csv data, int lineCount)
{
    float heighest = 0, lowest = 9999999;
    char *heighestState, *lowestState;
    for (int lineNo = 0; lineNo < lineCount; lineNo++)
    {
        int ratio = data[lineNo].vaccinated / data[lineNo].population;
        if (ratio > heighest){
            heighest = ratio;
            heighestState = data[lineNo].state;
        }
        if (ratio < lowest){
            lowest = ratio;
            lowestState = data[lineNo].state;
        }
    }
    printf("VaccinatedPopulation lowest: %s, heighest: %s\n", lowestState, heighestState);
}
void showRecoveredConfirm(Csv data, int lineCount)
{
    float heighest = 0, lowest = 9999999;
    char *heighestState, *lowestState;
    for (int lineNo = 0; lineNo < lineCount; lineNo++)
    {
        int ratio = data[lineNo].recovered / data[lineNo].confirmed;
        if (ratio > heighest){
            heighest = ratio;
            heighestState = data[lineNo].state;
        }
        if (ratio < lowest){
            lowest = ratio;
            lowestState = data[lineNo].state;
        }
    }
    printf("RecoveredConfirm lowest: %s, heighest: %s\n", lowestState, heighestState);
}
void showTestedPopulation(Csv data, int lineCount)
{
    float heighest = 0, lowest = 9999999;
    char *heighestState, *lowestState;
    for (int lineNo = 0; lineNo < lineCount; lineNo++)
    {
        int ratio = data[lineNo].tested / data[lineNo].population;
        if (ratio > heighest){
            heighest = ratio;
            heighestState = data[lineNo].state;
        }
        if (ratio < lowest){
            lowest = ratio;
            lowestState = data[lineNo].state;
        }
    }
    printf("TestedPopulation lowest: %s, heighest: %s", lowestState, heighestState);
}

int main()
{
    Csv storage;
    int lines = load("covid-state-data.txt", storage);
    showVaccinatedPopulation(storage, lines);
    showRecoveredConfirm(storage, lines);
    showTestedPopulation(storage, lines);
    return 0;
}