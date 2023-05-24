#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
//#include "Ninja.hpp"
//#include "Point.hpp"
class TrainedNinja:public Ninja{
    public:
    // int hitPoints = 120;
    // int speed = 12;
    TrainedNinja(string n, Point loc):Ninja(n,loc,120,12){};
};
#endif