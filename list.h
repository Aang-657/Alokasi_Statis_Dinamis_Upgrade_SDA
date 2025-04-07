// list.h (Header File)
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char data[20];
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void initList(Node *list);
Node* createNode(char *data);
void insertAfter(Node *prevNode, Node *newNode);
void insertAwal(LinkedList *list, Node *newNode);
void insertLast(Node **list, Node *newNode);
void insertBetween(LinkedList *list, Node *newNode);
void insertAfterBetween(LinkedList *list, Node *newNode);
void insertBeforeBetween(LinkedList *list, Node *newNode);
void insertAfterValue(LinkedList *list, char target, Node *newNode);
void insertBeforeValue(LinkedList *list, char target, Node *newNode);
void deleteAwal(LinkedList *list);
void deleteLast(LinkedList *list);
void deleteBetween(LinkedList *list);
void deleteAfterBetween(LinkedList *list);
void deleteBeforeBetween(LinkedList *list);
void deleteAfterValue(Node *list, char *target);
void deleteBeforeValue(LinkedList *list, char target);
void deleteAll(Node *list);
void modifyBetween(LinkedList *list, char newData);
void modifyAfterBetween(LinkedList *list, char newData);
void modifyBeforeBetween(LinkedList *list, char newData);
void modifyFirst(LinkedList *list, char newData);
void modifyLast(LinkedList *list, char newData);
void modifyAfterValue(LinkedList *list, char target, char newData);
void modifyBeforeValue(LinkedList *list, char target, char newData);
void printList(Node *list);

#endif