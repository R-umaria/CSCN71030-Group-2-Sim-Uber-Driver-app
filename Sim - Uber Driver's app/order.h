#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>



// Define the Order structure
typedef struct OrderNode {
    CoordinateNode userLocation;
    CoordinateNode pickupLocation;
    CoordinateNode* deliveryLocations; // Pointer to the head of the linked list of delivery locations
    int numDeliveries;
    struct OrderNode* next;
} OrderNode;