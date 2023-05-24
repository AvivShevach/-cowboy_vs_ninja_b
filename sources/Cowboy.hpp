#ifndef COWBOY_HPP
#define COWBOY_HPP
namespace ariel{};
#include <iostream>
#include "Character.hpp"
#include "Point.hpp"
using namespace std;
class Cowboy : public Character {
  public:
   // int hitPoints = 110;
    int bullets = 6;
    Cowboy(string n, Point q):Character(n,q,110){};
    void shoot(Character*);
    bool hasboolets();
    void reload();
    string print();
};
#endif