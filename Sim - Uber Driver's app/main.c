// Uber Driver's app Simulation
// project 2 - Group 2 - Rishi U. - Krishi - Adam - Mehak
//
// This software will run a simulation of how a Uber Driver's app works in finding the shortest
// path to different locations and our main aim of the software is to demonstrate 
// the principle of  "Dijkstra's Algorithm"

#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"

int main(int argc, char* argv[]) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random order
    OrderNode* randomOrder = generateRandomOrder(0, 0, 50);

    // Output the linked list of delivery locations and the height of the linked list
    printf("Random Order:\n");
    printf("Pickup Location: (%.2f, %.2f)\n", randomOrder->pickupLocation.x,
        randomOrder->pickupLocation.y);
    CoordinateNode* current = randomOrder->deliveryLocations;
    while (current != NULL) {
        printf("Delivery Location: (%.2f, %.2f)\n", current->x, current->y);
        current = current->next;
    }
    printf("Height of the delivery locations linked list: %d\n",
        calculateHeight(randomOrder->deliveryLocations));

    // Find shortest paths from pickup location to each delivery location
    current = randomOrder->deliveryLocations;
    while (current != NULL) {
        float distance = findShortestPath(&randomOrder->pickupLocation, current);
        printf("Distance from Pickup Location to Delivery Location %d: %.2f\n",
            current->id, distance);
        current = current->next;
    }

    return 0;
}
