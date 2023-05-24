#include "Team2.hpp"
void Team2::attack(Team *other)
{
    if(other == nullptr)
        throw invalid_argument("");
    if( !(leader->isAlive()) )
    {
        Character* tmpLeader;
        double min_d = MAXFLOAT;
        double d;
        for(unsigned int i = 0; i<_team.size();  i++)
        {
           if(!_team[i]->isAlive())
                continue;
           d = leader->distance(*_team[i]);
           if(min_d > d)
           {
                min_d = d;
                tmpLeader = _team[i];
           }
        }
        leader = tmpLeader;
    }
    unsigned int victim;
    int victim2 = find_victim(other);
    if(victim2 == -1)
        throw runtime_error("Team cannot attack a dead team");
    victim = (unsigned int)victim2;
    for(unsigned int i = 0; i < _team.size();  i++)
        {
            if(!_team[i]->isAlive())
                continue;
            if(!other->_team[victim]->isAlive())
            {
                victim2 = find_victim(other);
                if(victim2 == -1)
                    break;
            }
            if(victim2 == -1)
                break;
            victim = (unsigned int)victim2;
            Cowboy* c = dynamic_cast<Cowboy*>(_team[i]);
            if (c)
            {
               if(c->hasboolets())
                    c->shoot(other->_team[victim]);
               else
                    c->reload();
            }
            else// if (typeid(Ninja) == typeid(_team[i]))
            {
                Ninja* n = dynamic_cast<Ninja*>(_team[i]);
                if(n->distance(*(other->_team[victim])) <= 1 )
                    n->slash(other->_team[victim]);
                else
                    n->move(other->_team[victim]);
            } 

        }
}


void Team2::print()
{
    for(unsigned int i = 0; i< _team.size(); i++)
    {
        Cowboy* c = dynamic_cast<Cowboy*>(_team[i]);
        if (c)
            c->print();
        else
        {
            Ninja* n = (Ninja*)(_team[i]);
            n->print();
        }
    }
}