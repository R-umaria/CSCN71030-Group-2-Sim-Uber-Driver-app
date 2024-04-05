// Uber Driver's app Simulation
// project 2 - Group 2 - Rishi U. - Krishi - Adam - Mehak
//
// This software will run a simulation of how a Uber Driver's app works in finding the shortest
// path to different locations and our main aim of the software is to demonstrate 
// the principle of  "Dijkstra's Algorithm"

#include "Header.h"

int main() {

    srand(time(NULL));

    int maxX = 100; // Maximum x coordinate (will change afterwards)
    int maxY = 100; // Maximum y coordinate (will change afterwards)
    Coordinate userLocation = generateRandomCoordinate(maxX, maxY);
    printf("User location: (%d, %d)\n", userLocation.x, userLocation.y);

    Coordinate pickup, delivery;
    generateFoodOrder(&pickup, &delivery, maxX, maxY);
    printf("Food order - Pickup: (%d, %d), Delivery: (%d, %d)\n", pickup.x, pickup.y, delivery.x, delivery.y);

    // Implement Dijkstra's algorithm to find shortest path between userLocation, pickup, and delivery

    // Simulate user accepting or declining order
    // Provide more orders near the pickup location if accepted

    // Sort orders based on shortest distance first and longest distance after

    // Simulate driver's trip according to the sorted order of tasks

    // and any other required stuffs

    return 0;
}
