// Define the Coordinate structure
typedef struct CoordinateNode {
    int id;
    float x;
    float y;
    struct CoordinateNode* next;
} CoordinateNode;