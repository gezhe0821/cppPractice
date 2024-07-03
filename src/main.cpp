#include <iostream>
#include "PolygonIntersect.h"
#include "ReadPoints.h"

int main() {
    std::vector<Point> polygon1 = read_points_from_csv("../polygon1.csv");
    std::vector<Point> polygon2 = read_points_from_csv("../polygon2.csv");

    bool intersect = polygons_intersect(polygon1, polygon2);
    std::cout << "Polygons intersect: " << (intersect ? "Yes" : "No") << std::endl;

    return 0;
}