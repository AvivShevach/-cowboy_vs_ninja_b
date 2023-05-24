#include "Team.hpp"

class SmartTeam : public Team {
  public:
    SmartTeam(Character * l):Team(l){};
    void attack(Team *other);
    unsigned int smart_find_victim(Character* attacker, Team *other);
};