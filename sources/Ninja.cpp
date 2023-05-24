#include "Ninja.hpp"

void Ninja::move(Character* other)
{
    setLocation(p.moveTowards(other->getLocation(), (double)speed));
}


void Ninja::slash(Character* other)
{
    if(!isAlive())
        throw runtime_error("Dead characters cannot attack");
    
    if(!other->isAlive())
        throw runtime_error("characters cannot attack a dead enemy");
    
    Ninja* n = dynamic_cast<Ninja*>(other);
    if(this == n)
        throw runtime_error("No self harm");
    
    if(p.distance(other->getLocation()) < 1)
    {
        other->hitPoints -= 40;
    }
}
string Ninja::print()
{
    cout << "N ";
    Character::print();
    return "";
}