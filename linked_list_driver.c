/*
    Joe Lux
    Applied Topics in Cyber Security 
    Kyle Cook
    Project 01
    1-21-19

    gcc -0 linkedList linked_list.c linked_list_driver.c
*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    List *myList = list_new();

    List_init(myList);

    List_push(myList, 3.4);
    List_push(myList, 7.1);
    List_push(myList, 10.9);
    List_push(myList, 5);
    List_push(myList, 22.8);
    List_push(myList, 10);

    List_print(myList);

    double *holder = malloc(sizeof(double));

    List_delete(myList, holder, 4);
    List_delete(myList, holder, 1);

    List_print(myList);
    
    List_add(myList, 5.5, 2);
    List_add(myList, 9880.3, 4);

    List_print(myList);

    List_push(myList, 100);
    List_push(myList, 400);

    List_print(myList);

    double *variable = malloc(sizeof(double));
    List_get(myList, variable, 4);

    List_print(myList);

    List_delete(myList, holder, 4);
    List_add(myList, 74.4, 4);

    List_print(myList);

    List_push(myList, *variable);

    List_print(myList);

    List_free(myList);
    myList = NULL;

    List_print(myList);

    free(variable);
    free(holder);

    return 0;
}