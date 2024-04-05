#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define M_PI 3.14
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

// Function to generate a random float within a specific range
float randomFloat(float min, float max) {
    return min + (float)rand() / RAND_MAX * (max - min);
}

// Function to generate random coordinates within a specific radius around the user's location
CoordinateNode* generateRandomCoordinate(float userX, float userY, float radius, int id) {
    float angle = randomFloat(0, 2 * M_PI);
    float randomRadius = randomFloat(0, radius);
    float offsetX = randomRadius * cos(angle);
    float offsetY = randomRadius * sin(angle);

    CoordinateNode* coord = (CoordinateNode*)malloc(sizeof(CoordinateNode));
    coord->id = id;
    coord->x = userX + offsetX;
    coord->y = userY + offsetY;
    coord->next = NULL;

    return coord;
}

// Function to generate a random order
OrderNode* generateRandomOrder(float userX, float userY, float radius) {
    OrderNode* order = (OrderNode*)malloc(sizeof(OrderNode));

    // Generate random user location
    order->userLocation.id = -1;
    order->userLocation.x = userX;
    order->userLocation.y = userY;
    order->userLocation.next = NULL;

    // Generate random pickup location within a specific radius around the user's location
    order->pickupLocation.id = 0;
    order->pickupLocation.next = generateRandomCoordinate(userX, userY, radius, 0);

    // Generate random delivery locations within the same radius around the user's location
    order->numDeliveries = rand() % 10 + 1; // Generate between 1 and 10 delivery locations
    CoordinateNode* currentDelivery = NULL;
    for (int i = 0; i < order->numDeliveries; i++) {
        if (i == 0) {
            order->deliveryLocations = generateRandomCoordinate(userX, userY, radius, i + 1);
            currentDelivery = order->deliveryLocations;
        }
        else {
            currentDelivery->next = generateRandomCoordinate(userX, userY, radius, i + 1);
            currentDelivery = currentDelivery->next;
        }
    }
    currentDelivery->next = NULL;

    order->next = NULL;

    return order;
}

// Function to calculate the height of the linked list
int calculateHeight(CoordinateNode* head) {
    int height = 0;
    CoordinateNode* current = head;
    while (current != NULL) {
        height++;
        current = current->next;
    }
    return height;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random order
    OrderNode* randomOrder = generateRandomOrder(0, 0, 50);

    // Output the linked list of delivery locations and the height of the linked list
    printf("Random Order:\n");
    printf("Pickup Location: (%.2f, %.2f)\n", randomOrder->pickupLocation.x, randomOrder->pickupLocation.y);
    CoordinateNode* current = randomOrder->deliveryLocations;
    while (current != NULL) {
        printf("Delivery Location: (%.2f, %.2f)\n", current->x, current->y);
        current = current->next;
    }
    printf("Height of the delivery locations linked list: %d\n", calculateHeight(randomOrder->deliveryLocations));

    // Free allocated memory
    // Note: You need to implement a function to free the memory properly
    // For simplicity, I'm skipping memory deallocation in this example

    return 0;
}
