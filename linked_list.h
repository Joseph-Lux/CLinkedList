/*
    Joe Lux
    Applied Topics in Cyber Security 
    Kyle Cook
    Project 01
    1-21-19

    Not sure if you need this. I also changed it a little
    bit, because I was getting some errors about the 
    structs already being declared.
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    double value;
    struct Node *nextNode;
} Node;

typedef struct List {
    struct Node *head;
    int size;
} List;

List* list_new();
int List_init(List* l);
int List_add(List* l, double val, int idx);
int List_push(List* l, double val);
int List_pop(List* l, double* val);
int List_get(List* l, double* val, int idx);
int List_delete(List* l, double* val, int idx);
int List_free(List* l);
int List_size(List* l);
void List_print(List* l);

#endif // LINKED_LIST_H