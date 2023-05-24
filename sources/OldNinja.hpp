#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
namespace ariel{};
#include "Ninja.hpp"
#include "Cowboy.hpp"
class OldNinja : public Ninja{
    public:
    // int hitPoints = 150;
    // int speed = 8;
    OldNinja(string n, Point loc):Ninja(n,loc,150,8){};
    // double distance(Cowboy *c)
    // {
    //    return Ninja::distance( *((Character *)c));
    // };

};

#endif