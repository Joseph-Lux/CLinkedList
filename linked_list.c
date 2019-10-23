/*
    Joe Lux
    Applied Topics in Cyber Security 
    Kyle Cook
    Project 01
    1-21-19

    gcc -o linkedList linked_list.c linked_list_driver.c
*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

List* list_new() {
    List *newList = malloc(sizeof(List));
    return newList;
}

int List_init(List* l){
    l->head = NULL;
    l->size = 0;
    return 0; 
}

int List_add(List* l, double val, int idx) {
    if (idx > l->size - 1) {
        return NULL;
    }

    Node *newNode = malloc(sizeof(Node));
    newNode->value = val; 

    Node *currentNode = l->head;
    for (int i = 1; i < idx; ++i){
        currentNode = currentNode->nextNode;
    }

    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;

    l->size = l->size + 1;

    return idx;
}

int List_push(List* l, double val) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->nextNode = NULL;
    if (!(l->head)) {
        l->head = newNode;
    } else {
        Node *currentNode = l->head;
        for(int i = 1; i < l->size; ++i){
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode = newNode;
    }
    l->size = l->size + 1;

    return l->size - 1;
}

int List_pop(List* l, double* val) {
    Node *currentNode = l->head;
    for(int i = 2; i < l->size; ++i){
        currentNode = currentNode->nextNode;
    }
    *val = currentNode->nextNode->value;

    free(currentNode->nextNode);

    currentNode->nextNode = NULL;
    l->size = l->size - 1;

    return l->size;
}

int List_get(List* l, double* val, int idx) {
    if (idx > l->size - 1){
        return NULL;
    }
    Node *currentNode = l->head;
    for(int i = 0; i < idx; ++i){
        currentNode = currentNode->nextNode;
    }

    *val = currentNode->value;

    return idx;
}

int List_delete(List* l, double* val, int idx) {
    if (idx > l->size - 1){
        return NULL;
    }

    Node *currentNode = l->head;
    for(int i = 1; i < idx; ++i){
        currentNode = currentNode->nextNode;
    }

    Node *tempNode = currentNode->nextNode;
    *val = tempNode->value;
    currentNode->nextNode = tempNode->nextNode;
    free(tempNode);

    l->size = l->size - 1;

    return idx;
}

int List_free(List* l) {
    Node *currentNode = l->head;
    while (l->head){
        currentNode = l->head;
        l->head = currentNode->nextNode;
        free(currentNode);
    }
    free(l);
    
    return 0;
}

int List_size(List* l) {
    return l->size;
}

void List_print(List* l) {
    if(!l){
        printf("Null list.\n");
        return;
    }
    if(!(l->head)){
        printf("List empty.\n");
    } else {
        Node *currentNode = l->head;
        for (int i = 0; i < l->size; ++i){
            printf("%.1f  ", currentNode->value);
            currentNode = currentNode->nextNode;
        }
        printf("\n%d items.\n", l->size);
    }
}