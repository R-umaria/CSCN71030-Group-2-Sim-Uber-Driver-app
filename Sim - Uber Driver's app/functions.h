#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Order.h"

int main(int argc, char* argv[]);
float randomFloat(float min, float max);
float calculateDistance(float x1, float y1, float x2, float y2);
CoordinateNode* generateRandomCoordinate(float userX, float userY, float radius, int id);
int calculateHeight(CoordinateNode* head);
float findShortestPath(CoordinateNode* start, CoordinateNode* end);
float findTotalShortestPath(OrderNode* order);

#endif 
