#include "../proto/supervisor.h"

// Reproduce 2 lucky MUs
// TEMPORARY -> Procreate will be refactored in the futur, when Turn will be implemented
void procreateRound(struct Univers **univers)
{/*
    // TEMPORARY -> No check for languor status
    // TEMPORARY -> No position check for reproduction (proximity)
    struct MU *inter = univers->population->startPopulation;
    while (inter != NULL)
    {

    }
    //struct MU *baby = breed(&(Mus[5]), &(Mus[3]), lastChild, population);
    //struct MU *newPopulation = malloc(sizeof(struct MU) * ((*population) + 1));
    //for (i = 0; i < (*population); i++)
    //{
    //    newPopulation[i] = Mus[i];
    //}
    //newPopulation[*(population)] = *baby;
    //(*population)++;

    //return newPopulation;*/
}

// breed 2 MU's by spliting DNA and return the baby of this epic reproduction
struct MU *breed(struct MU *dad, struct MU *mom, int *id, int *population)
{
    struct MU *baby = malloc(sizeof(struct MU));

    // Share DNA from Dad and Mom
    shareDNA(baby, dad, mom);
    baby->capacity = initiateCapacity(baby->DNA);

    // TEMPORARY -> Will need a function to determine child's position
    baby->position = malloc(sizeof(int) * 2);
    baby->position[0] = 1;
    baby->position[1] = 1;

    baby->idMu = (*id)++;
    baby->status = 1;
    baby->lifePoints = initiateLifePoints(baby->capacity[0]);
    baby->speed = baby->capacity[1];
    baby->children = calloc(50, sizeof(int));
    affectChildren(baby->idMu, dad);
    affectChildren(baby->idMu, mom);
    dad->languor = 0;
    mom->languor = 0;
    return baby;
}

void shareDNA(struct MU *baby, struct MU *dad, struct MU *mom)
{
    int i = 0;
    tiny expression = 'A';
    baby->DNA = malloc(sizeof(tiny *) * 13);
    while (expression <= 'L')
    {
        baby->DNA[i] = malloc(sizeof(tiny) * 3);
        // Will affect to DNA version 1 or 2 from each parents
        baby->DNA[i][0] = expression++;
        baby->DNA[i][1] = dad->DNA[i][(rand() % 2) + 1];
        baby->DNA[i][2] = mom->DNA[i][(rand() % 2) + 1];
        i++;
    }
}

void affectChildren(int idChildren, struct MU *parent)
{
    int i;
    for (i = 0; parent->children[i] != 0; i++)
    {
        printf("not okay");
    }
    parent->children[i] = idChildren;
}










// //#include <stdio.h>

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//     int val;
//     struct node * next;
// } node_t;

// void print_list(node_t * head) {
//     node_t * current = head;

//     while (current != NULL) {
//         printf("%d\n", current->val);
//         current = current->next;
//     }
// }

// int pop(node_t ** head) {
//     int retval = -1;
//     node_t * next_node = NULL;

//     if (*head == NULL) {
//         return -1;
//     }

//     next_node = (*head)->next;
//     retval = (*head)->val;
//     free(*head);
//     *head = next_node;

//     return retval;
// }

// int remove_by_index(node_t ** head, int n) {
//     int i = 0;
//     int retval = -1;
//     node_t * current = *head;
//     node_t * temp_node = NULL;

//     if (n == 0) {
//         return pop(head);
//     }

//     for (i = 0; i < n-1; i++) {
//         if (current->next == NULL) {
//             return -1;
//         }
//         current = current->next;
//     }

//     temp_node = current->next;
//     retval = temp_node->val;
//     current->next = temp_node->next;
//     free(temp_node);

//     return retval;

// }


// void delete_list(node_t *head) {
//     node_t  *current = head, 
//             *next = head;

//     while (current) {
//         next = current->next;
//         free(current);
//         current = next;
//     }
// }


// int main(void) {
//     node_t * test_list = malloc(sizeof(node_t));

//     test_list->val = 1;
//     test_list->next = malloc(sizeof(node_t));
//     test_list->next->val = 2;
//     test_list->next->next = malloc(sizeof(node_t));
//     test_list->next->next->val = 3;
//     test_list->next->next->next = malloc(sizeof(node_t));
//     test_list->next->next->next->val = 4;
//     test_list->next->next->next->next = NULL;

//     remove_by_value(&test_list, 3);

//     print_list(test_list);
//     delete_list(test_list);

//     return EXIT_SUCCESS;
// }

