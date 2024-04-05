#include"functions.h"

// Function to compute Euclidean distances between pickup location and delivery locations
void computeDistances(OrderNode* order, float** distances) {
    CoordinateNode* currentDelivery = order->deliveryLocations;
    int i = 0;
    while (currentDelivery != NULL) {
        (*distances)[i] = calculateDistance(order->pickupLocation.x, order->pickupLocation.y,
            currentDelivery->x, currentDelivery->y);
        currentDelivery = currentDelivery->next;
        i++;
    }
}

// Function to determine the optimal order to visit delivery locations based on shortest path
void determineOptimalOrder(float* distances, int numDeliveries, int* order) {
    // Initialize order array with values from 0 to numDeliveries - 1
    for (int i = 0; i < numDeliveries; i++) {
        order[i] = i;
    }

    // Bubble sort to sort the order array based on distances
    for (int i = 0; i < numDeliveries - 1; i++) {
        for (int j = 0; j < numDeliveries - i - 1; j++) {
            if (distances[j] > distances[j + 1]) {
                // Swap distances
                float temp = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp;
                // Swap order
                int tempOrder = order[j];
                order[j] = order[j + 1];
                order[j + 1] = tempOrder;
            }
        }
    }
}

// Function to print order details including coordinates
void printOrder(OrderNode* order, int* optimalOrder) {
    printf("User Location: (%.2f, %.2f)\n", order->userLocation.x, order->userLocation.y);
    printf("Pickup Location: (%.2f, %.2f)\n", order->pickupLocation.x, order->pickupLocation.y);
    printf("Delivery Locations:\n");
    CoordinateNode* currentDelivery = order->deliveryLocations;
    while (currentDelivery != NULL) {
        printf("\tDelivery Location %d: (%.2f, %.2f)\n", currentDelivery->id, currentDelivery->x, currentDelivery->y);
        currentDelivery = currentDelivery->next;
    }
    printf("Optimal order of visiting delivery locations:\n");
    for (int i = 0; i < order->numDeliveries; i++) {
        printf("\tDelivery Location %d\n", optimalOrder[i] + 1); // Adding 1 to match 1-indexing
    }
    printf("Number of Deliveries: %d\n", order->numDeliveries);
}
