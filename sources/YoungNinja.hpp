#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
//#include "Ninja.hpp"
//#include "Point.hpp"
class YoungNinja:public Ninja{
    public:
    // int hitPoints = 100;
    // int speed = 14;
    YoungNinja(string n, Point loc):Ninja(n,loc,100,14){};
};
#endif