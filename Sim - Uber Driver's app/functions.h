#include"order.h"
#include"cordinates.h"
float randomFloat(float min, float max);
float calculateDistance(float x1, float y1, float x2, float y2);
CoordinateNode* generateRandomCoordinate(float userX, float userY, float radius, int id);
OrderNode* generateRandomOrder(float userX, float userY, float radius);
void computeDistances(OrderNode* order, float** distances);
void determineOptimalOrder(float* distances, int numDeliveries, int* order);
void printOrder(OrderNode* order, int* optimalOrder);