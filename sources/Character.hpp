#ifndef CHARACTER_HPP
#define CHARACTER_HPP
//using namespace std;
#include <iostream>
#include "Point.hpp"
//#include "Cowboy.hpp"
class Character {
  public:
    string name;
    Point p;
    int hitPoints;
    bool teamMember = false;
    Character(string n, Point loc, int hp){name = n; p = loc; hitPoints = hp;};
    bool isAlive();
    double distance(Character&);
    double distance(Character *c);
    void hit(int);
    string getName();
    Point getLocation();
    virtual ~Character() {};
    string print();
    protected:
      Point setLocation(Point q);

};
#endif