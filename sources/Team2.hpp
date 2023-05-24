#include "Team.hpp"

class Team2 : public Team {
  public:
    Team2(Character * l):Team(l){};
    void attack(Team *other);
    void print();
};