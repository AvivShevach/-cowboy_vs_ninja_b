#ifndef TEAM_HPP
#define TEAM_HPP
#include "string"
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Team {
    public:
        vector <Character * > _team;
        Character *leader;
        Team(Character * l){leader = l; add(l);};
        void add(Character *c);
        int stillAlive();
        void attack(Team *other);
        void print();
        int find_victim(Team *other);

};
#endif