#ifndef READ_POINTS_H
#define READ_POINTS_H

#include <vector>
#include "Point.h"

// 读取CSV文件并返回点的向量
std::vector<Point> read_points_from_csv(const std::string& filename);

#endif // READ_POINTS_H