#ifndef POLYGON_INTERSECT_H
#define POLYGON_INTERSECT_H

#include "Point.h"

// 向量叉积
double cross_product_z(const Point& a, const Point& b, const Point& c);

// 判断点是否在线段内
bool point_in_segment(const Point& p, const Point& s1, const Point& s2);

// 判断点是否在多边形内
bool point_in_polygon(const Point& p, const std::vector<Point>& polygon);

// 判断两个多边形是否相交
bool polygons_intersect(const std::vector<Point>& polygon1, const std::vector<Point>& polygon2);

#endif // POLYGON_INTERSECT_H