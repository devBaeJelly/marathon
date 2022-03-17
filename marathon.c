#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int checkPoint;
    int passPoint;
    int distance = 0;

    scanf("%d\n", &checkPoint);

    if (checkPoint > 1000)
        return -1;

    int *x = malloc(sizeof(int) * checkPoint);
    int *y = malloc(sizeof(int) * checkPoint);

    for (int i = 0; i < checkPoint; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }

    printf("Which point should we pass? (Except for 1 and the last point) : ");
    scanf("%d", &passPoint);
    if (passPoint <= 1 || passPoint >= checkPoint)
    {
        printf(" *** incorrect input (Except for 1 and the last point) **\n");
        return -1;
    }


    x[(checkPoint - 1) - (checkPoint - passPoint)] = 0;
    y[(checkPoint - 1) - (checkPoint - passPoint)] = 0;

    for (int i = 0; i < checkPoint; i++)
    {
        if (x[i + 1] == 0 && y[i + 1] == 0)
            distance += abs(x[i] - x[i + 1 + 1]) + abs(y[i] - y[i + 1 + 1]);
        else if (x[i] == x[checkPoint-1] && y[i] == y[checkPoint-1])
            break;
        else if ((x[i] == x[(checkPoint - 1) - (checkPoint - passPoint)] && y[i] == y[(checkPoint - 1) - (checkPoint - passPoint)]) && i!=0)
            continue;
        else
            distance += abs(x[i] - x[i + 1]) + abs(y[i] - y[i+1]);
    }


    printf("%d\n", distance);

    free(x);
    free(y);

    return 0;
}

