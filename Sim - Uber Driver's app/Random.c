#include"functions.h"


// Function to generate a random float within a specific range
float randomFloat(float min, float max) {
    return min + (float)rand() / RAND_MAX * (max - min);
}

// Function to calculate the Euclidean distance between two points
float calculateDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to generate random coordinates within a specific radius around the user's location
CoordinateNode* generateRandomCoordinate(float userX, float userY, float radius, int id) {
    float angle = randomFloat(0, 2 * 3.14);
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
    order->pickupLocation.x = userX + randomFloat(-radius, radius);
    order->pickupLocation.y = userY + randomFloat(-radius, radius);
    order->pickupLocation.next = NULL;

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
