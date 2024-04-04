#ifndef CORDINATES_H
#define CORDINATES_H

typedef struct CoordinateNode {
    int id;
    float x;
    float y;
    struct CoordinateNode* next;
} CoordinateNode;

float randomFloat(float min, float max);
float calculateDistance(float x1, float y1, float x2, float y2);
CoordinateNode* generateRandomCoordinate(float userX, float userY, float radius, int id);
int calculateHeight(CoordinateNode* head);
float findShortestPath(CoordinateNode* start, CoordinateNode* end);

#endif 

