#include "SmartTeam.hpp"

void SmartTeam::attack(Team *other)
{
    if(other == nullptr)
        throw invalid_argument("");
    if(other->stillAlive() == 0)
        throw runtime_error("Team cannot attack a dead team");

    unsigned int victim;
    for(unsigned int i = 0; i < _team.size();  i++)
    {
        if(!_team[i]->isAlive())
            continue;
        if(other->stillAlive() == 0)
            victim = smart_find_victim(_team[i], other);
        else
            break;
        Cowboy* c = dynamic_cast<Cowboy*>(_team[i]);
        if (c)
            c->shoot(other->_team[victim]);

        Ninja* n = dynamic_cast<Ninja*>(_team[i]);
        if(n)
        {
            if(n->distance(other->_team[victim]) < 1)
                n->slash(other->_team[victim]);
            else
                n->move(other->_team[victim]);
        }
         
    }    
}

unsigned SmartTeam::smart_find_victim(Character* attacker,Team *other)
{
    unsigned int victim;
    int minHitPoints = INT_MAX;
    Cowboy* c = dynamic_cast<Cowboy*>(attacker);
    if(c)
    {
        for(unsigned int i = 0; i < other->_team.size();  i++)
        {
            if(!other->_team[i]->isAlive())
                continue;
            if(other->_team[i]->hitPoints < minHitPoints)
            {
                minHitPoints = other->_team[i]->hitPoints;
                victim = i;
            }

            
        }

    }
    int d;
    int min_d = INT_MAX;
    Ninja* n = dynamic_cast<Ninja*>(attacker);
    if(n)
    {
        for(unsigned int i = 0; i < other->_team.size();  i++)
        {
            if(!other->_team[i]->isAlive())
                continue;

            d = attacker->distance(other->_team[i]);
            if(d < min_d)
            {
                min_d = d;
                victim = i;
            } 
        }
    }
    
    return victim;

}