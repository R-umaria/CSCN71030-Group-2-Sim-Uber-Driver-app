#ifndef ORDER_H
#define ORDER_H
#include "Cordinates.h"

typedef struct OrderNode {
    CoordinateNode userLocation;
    CoordinateNode pickupLocation;
    CoordinateNode* deliveryLocations;
    int numDeliveries;
    struct OrderNode* next;
} OrderNode;

OrderNode* generateRandomOrder(float userX, float userY, float radius);
float findTotalShortestPath(OrderNode* order);

#endif

