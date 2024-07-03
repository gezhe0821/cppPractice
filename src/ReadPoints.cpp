#include "ReadPoints.h"
#include <fstream>
#include <sstream>
#include <string>

// 读取CSV文件并返回点的向量
std::vector<Point> read_points_from_csv(const std::string& filename) {
    std::vector<Point> points;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return points;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        double x, y;
        char comma; // 用来存储逗号
        if (ss >> x >> comma >> y) {
            if (comma == ',') {
                points.push_back(Point(x, y));
            } else {
                std::cerr << "Error reading coordinates from line: " << line << std::endl;
            }
        } else {
            std::cerr << "Error reading coordinates from line: " << line << std::endl;
        }
    }

    file.close();
    return points;
}