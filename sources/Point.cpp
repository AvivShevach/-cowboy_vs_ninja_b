#include "Point.hpp"

double Point::distance(Point q)
{
    double dx = q.x - x;
    double dy = q.y - y;
    return sqrt(dx * dx + dy * dy);
}
double Point::distance(Point p, Point q)
{
    double dx = q.x - p.x;
    double dy = q.y - p.y;
    return sqrt(dx * dx + dy * dy);
}


void Point::print()
{
    cout << "(" << x << ", " << y << ")" <<endl;
}


Point Point::moveTowards(Point p, Point q, double d) 
{
    if(d < 0)
        throw invalid_argument("Invalid argument: value must be not negative");
    double currentDistance = distance(p,q);
    double dx;
    double dy;
    double ratio;
    double newX;
    double newY;
    if(currentDistance <= d)
        return q;
    else 
    {
        dx = q.x - p.x;
        dy = q.y - p.y;
        ratio = d / currentDistance;
        newX = p.x + dx * ratio;
        newY = p.y + dy * ratio;
        return {newX, newY};
    }
   
}

Point Point::moveTowards(Point q, double d) 
{
    if(d < 0)
        throw invalid_argument("Invalid argument: value must be not negative");
    double currentDistance = distance(q);
    double dx;
    double dy;
    double ratio;
    double newX;
    double newY;
    if(currentDistance <= d)
        return q;
    else 
    {
        dx = q.x - x;
        dy = q.y - y;
        ratio = d / currentDistance;
        newX = x + dx * ratio;
        newY = y + dy * ratio;
        return {newX, newY};
    }
   
}