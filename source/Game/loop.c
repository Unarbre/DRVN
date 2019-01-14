#include "../../proto/supervisor.h"
#include <stdio.h>


int startGame(struct Univers *univers, struct Population **population, struct Land *land)
{
    char command[2];


    printf("s pour commencer\n");
    fgets(command, 2, stdin);
    while(command[0] == 's' && univers->age < 5)
    {
        univers->age += 1;
        printf("%d\n", univers->age);
    }
    printf("test\n");
    return 0;
}