#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Data structures
typedef struct Coordinate {
    int x;
    int y;
} COORDINATE;

typedef struct Order
{
    COORDINATE pickup;
    COORDINATE delivery;
    int orderID;
    // Will have to add more fields as needed
} ORDER;

typedef struct Node
{
    ORDER data;
    struct Node* next;
}NODE;


// Function prototypes
Coordinate generateRandomCoordinate(int, int);
void generateRandomOrder(Order* order);
void dijkstraAlgorithm(/* Will have to Pass necessary parameters */);
void userInteraction();
void manageOrder(Order order);
int writeFile(NODE* ptr);