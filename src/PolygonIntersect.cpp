#include "PolygonIntersect.h"
#include <vector>

// 向量叉积
double cross_product_z(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 判断点是否在线段内
bool point_in_segment(const Point& p, const Point& s1, const Point& s2) {
    return (s1.x <= p.x && p.x <= s2.x) || (s2.x <= p.x && p.x <= s1.x) ||
           (s1.y <= p.y && p.y <= s2.y) || (s2.y <= p.y && p.y <= s1.y);
}

// 判断点是否在多边形内
bool point_in_polygon(const Point& p, const std::vector<Point>& polygon) {
    int count = 0;
    for (size_t i = 0; i < polygon.size(); ++i) {
        const Point& prev = polygon[i == 0 ? polygon.size() - 1 : i - 1];
        const Point& cur = polygon[i];
        if ((cur.y > p.y) != (prev.y > p.y)) {
            if (cross_product_z(prev, cur, p) > 0) {
                ++count;
            }
        }
    }
    return count % 2 == 1;
}

// 判断两个多边形是否相交
bool polygons_intersect(const std::vector<Point>& polygon1, const std::vector<Point>& polygon2) {
    // 检查边是否相交
    for (size_t i = 0; i < polygon1.size(); ++i) {
        const Point& p1 = polygon1[i];
        const Point& q1 = polygon1[(i + 1) % polygon1.size()];
        for (size_t j = 0; j < polygon2.size(); ++j) {
            const Point& p2 = polygon2[j];
            const Point& q2 = polygon2[(j + 1) % polygon2.size()];
            if (cross_product_z(p1, q1, p2) * cross_product_z(p1, q1, q2) <= 0 &&
                cross_product_z(p2, q2, p1) * cross_product_z(p2, q2, q1) <= 0) {
                return true;
            }
        }
    }

    // 检查顶点是否在对方多边形内
    for (const Point& p : polygon1) {
        if (point_in_polygon(p, polygon2)) {
            return true;
        }
    }
    for (const Point& p : polygon2) {
        if (point_in_polygon(p, polygon1)) {
            return true;
        }
    }

    return false;
}