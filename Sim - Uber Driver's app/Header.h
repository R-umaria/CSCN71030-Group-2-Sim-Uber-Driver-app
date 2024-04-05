#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

// Define the Coordinate structure
typedef struct CoordinateNode {
    int id;
    float x;
    float y;
    struct CoordinateNode* next;
} CoordinateNode;

// Define the Order structure
typedef struct OrderNode {
    CoordinateNode userLocation;
    CoordinateNode pickupLocation;
    CoordinateNode* deliveryLocations; // Pointer to the head of the linked list of delivery locations
    int numDeliveries;
    struct OrderNode* next;
} OrderNode;



// Function prototypes
void printOrder(OrderNode* order, int* optimalOrder);
void determineOptimalOrder(float* distances, int numDeliveries, int* order);
void computeDistances(OrderNode* order, float** distances);
OrderNode* generateRandomOrder(float userX, float userY, float radius);
CoordinateNode* generateRandomCoordinate(float userX, float userY, float radius, int id);
float calculateDistance(float x1, float y1, float x2, float y2);
float randomFloat(float min, float max);
void writeFile(/* Will have to Pass necessary parameters */);