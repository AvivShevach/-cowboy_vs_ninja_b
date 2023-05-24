#include "Team.hpp"

void Team::add(Character *c)
{
    if (_team.size() >= 10)
        throw runtime_error("The team can have up to 10 teammates"); 

    if (c->teamMember)
        throw runtime_error("");
    
    if(_team.size() < 10)
    {
        _team.push_back(c);
        c->teamMember = true;
    }
}

int Team::stillAlive()
{
    int k =0;
    for(unsigned int i = 0; i< _team.size(); i++)
    {
        if(_team[i]->isAlive())
            k++;
    }
    return k;
}

void Team::attack(Team *other)
{
    if(other == nullptr)
        throw invalid_argument("");
    
    if(other->stillAlive() == 0)
        throw runtime_error("Team cannot attack a dead team");
    
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
    // if(victim2 == -1)
    //     throw runtime_error("Team cannot attack a dead team");
    victim = (unsigned int)victim2;
    for(unsigned int i = 0; i < _team.size();  i++)
        {
            if(!_team[i]->isAlive())
                continue;
            Cowboy* c = dynamic_cast<Cowboy*>(_team[i]);
            if (c == nullptr)
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
            if(c->hasboolets())
                c->shoot(other->_team[victim]);
            else
                c->reload();
        }
    for(unsigned int i = 0; i < _team.size();  i++)
        {
            if(!_team[i]->isAlive())
                continue;
            Ninja* n = dynamic_cast<Ninja*>(_team[i]);
            if (n == nullptr)
                continue;
            if(!other->_team[victim]->isAlive())
            {
                victim2 = find_victim(other);
                if(victim2 == -1)
                    break;
            }
            victim = (unsigned int)victim2;
            if(n->distance(*(other->_team[victim])) <= 1 )
                n->slash(other->_team[victim]);
            else
                n->move(other->_team[victim]);
        }
}
int Team::find_victim(Team *other)
{
    double min_d = MAXFLOAT;
    double d;
    int victim = -1;
    for(unsigned int i = 0; i < other->_team.size();  i++)
    {
        if(!(other->_team[i])->isAlive())
                continue;
        d = leader->distance(*(other->_team[i]));
        if(min_d > d)
        {
            min_d = d;
            victim = (int)i;
        }
    }
    // if(victim == -1)
    //     throw runtime_error("");
    return victim;
}

void Team::print()
{
    for(unsigned int i = 0; i< _team.size(); i++)
    {
        Cowboy* c = dynamic_cast<Cowboy*>(_team[i]);
        if (c)
            c->print();
    }

    for(unsigned int i = 0; i< _team.size(); i++)
    {
        Ninja* n = dynamic_cast<Ninja*>(_team[i]);
        if (n)
            n->print();
    }
    

}