#include "Header.h"


Coordinate generateRandomCoordinate(int maxX, int maxY) {
    Coordinate randomCoordinate;
    randomCoordinate.x = rand() % maxX;
    randomCoordinate.y = rand() % maxY;
    return randomCoordinate;
}
    
void generateRandomOrder(Order* order) {
    // func to generate random pickup and delivery coordinates
    order->pickup = generateRandomCoordinate();
    order->delivery = generateRandomCoordinate();
}

void generateFoodOrder(Coordinate* pickup, Coordinate* delivery, int maxX, int maxY) {
    *pickup = generateRandomCoordinate(maxX, maxY);
    *delivery = generateRandomCoordinate(maxX, maxY);
}

void dijkstraAlgorithm(/* Pass parameters */) {
    // Implement Dijkstra's algorithm
}

void userInteraction() {
    // user interaction
}

void manageOrder(Order order) {
    // order management
}
