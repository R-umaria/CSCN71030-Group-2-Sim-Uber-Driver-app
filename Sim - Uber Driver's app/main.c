// Uber Driver's app Simulation
// project 2 - Group 2 - Rishi U. - Krishi - Adam - Mehak
//
// This software will run a simulation of how a Uber Driver's app works in finding the shortest
// path to different locations and our main aim of the software is to demonstrate 
// the principle of  "Dijkstra's Algorithm"

#include "Header.h"

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    float userX = 0.0f; // User's X coordinate
    float userY = 0.0f; // User's Y coordinate
    float radius = 10.0f; // Radius around the user's location for generating pickup and delivery locations

    // Generate a random order
    OrderNode* order = generateRandomOrder(userX, userY, radius);

    // Allocate memory for distances
    float* distances = (float*)malloc(order->numDeliveries * sizeof(float));

    // Compute distances from pickup location to delivery locations
    computeDistances(order, &distances);

    // Determine the optimal order to visit delivery locations
    int* orderOfVisits = (int*)malloc(order->numDeliveries * sizeof(int));
    determineOptimalOrder(distances, order->numDeliveries, orderOfVisits);

    // Print the order details
    printOrder(order, orderOfVisits);

    // Free memory
    free(distances);
    free(orderOfVisits);

    CoordinateNode* current = order->deliveryLocations;
    while (current != NULL) {
        CoordinateNode* next = current->next;
        free(current);
        current = next;
    }
    free(order);

    return 0;
}
