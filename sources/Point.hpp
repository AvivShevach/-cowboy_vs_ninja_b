#ifndef POINT_HPP
#define POINT_HPP
namespace ariel{};
#include <iostream>
#include <cmath>
using namespace std;
class Point {
  public:
    double x, y;
    Point(){};
    Point(double n1, double n2){x=n1; y=n2;};
    double distance(Point);
    static double distance(Point p, Point q);
    void print();
    Point moveTowards(Point, double);
    static Point moveTowards(Point, Point, double);

};
#endif