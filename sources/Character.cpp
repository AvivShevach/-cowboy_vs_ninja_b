#include "Character.hpp"

bool Character::isAlive()
{
    return hitPoints > 0;
}

double Character::distance(Character& c)
{
   return (c.p).distance(p);
}

double Character::distance(Character *c)
{
    return (c->p).distance(p);
};

string Character::getName()
{
    return name;
}
Point Character::getLocation()
{
    return p;
}

void Character::hit(int h)
{
    if(h < 0)
        throw invalid_argument("Invalid argument: value must be not negative");
    hitPoints-=h;
}

Point Character::setLocation(Point q)
{
    p.x = q.x;
    p.y = q.y;
    return p;
}

string Character::print()
{
    // if (typeid(*this) == typeid(Cowboy))
    //     std::cout << "C";
    // else
    //     std::cout << "N";

    if(isAlive())
        std::cout << name << " " << hitPoints << " ";
    else
        std::cout << "(" << name << ") " << " ";

    p.print();
    return "";
}
