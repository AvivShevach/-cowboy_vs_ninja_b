#include "Cowboy.hpp"

void Cowboy::shoot(Character* other)
{
    if(!isAlive())
        throw runtime_error("Dead characters cannot attack");
    
    if(!other->isAlive())
        throw runtime_error("characters cannot attack a dead enemy");
    
    Cowboy* c = dynamic_cast<Cowboy*>(other);
    if(this == c)
        throw runtime_error("No self harm");
    if(hasboolets())
    {
        other->hitPoints -= 10;
        bullets--;
    }
}

bool Cowboy::hasboolets()
{
    return bullets > 0;
}

void Cowboy::reload()
{
    if (!isAlive())
        throw runtime_error("Dead cowboy can not reload");
    bullets = 6;
}
string Cowboy::print()
{
    cout << "C ";
    Character::print();
    return "";
}