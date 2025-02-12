#include "../include/point.hpp"
#include <cmath>
#include <iostream>

// Keep only one constructor using member initializer list
Point::Point(double x, double y) : x{x}, y{y} {}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

double Point::distance(const Point &other) const {
    double x2 = other.get_x();
    double y2 = other.get_y();
    double x2_x1 = x2 - x;
    double y2_y1 = y2 - y;
    return std::sqrt(x2_x1 * x2_x1 + y2_y1 * y2_y1);
}

double Point::get_x() const { return x; }

double Point::get_y() const { return y; }

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

bool Point::is_equal(const Point &other) const {
    return (x == other.get_x() && y == other.get_y());
}
