#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Data structures
typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate pickup;
    Coordinate delivery;
    // Will have to add more fields as needed
} Order;


// Function prototypes
Coordinate generateRandomCoordinate(int, int);
void generateRandomOrder(Order* order);
void dijkstraAlgorithm(/* Will have to Pass necessary parameters */);
void userInteraction();
void manageOrder(Order order);
void writeFile(/* Will have to Pass necessary parameters */);