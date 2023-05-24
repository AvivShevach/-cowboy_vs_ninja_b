#ifndef NINJA_H
#define NINJA_H

#include "Character.hpp"
class Ninja : public Character {
  public:
    // string name;
    // Point p;
   // int hitPoints;
    int speed;
   // Ninja();
    Ninja(string n, Point q, int hp, int s):Character(n,q,hp){speed = s;};

    void move(Character*);

    void slash(Character*);
    
    string print();
};

#endif
