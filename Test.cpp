namespace ariel{};
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "sources/Team.hpp"
#include "doctest.h"

Point p1{0, 1};
Point p2{5, 1};
Point p3{7, -4};
Point q1{-6, -9};
Point q2{-9, 5};

Cowboy *Tom = new Cowboy("Tom",p1);
Cowboy *Alice = new Cowboy("Alice",p1);
Cowboy *Aviv = new Cowboy("Aviv", p2);

YoungNinja *a = new YoungNinja("1", p1);
YoungNinja *b = new YoungNinja("2", p1);
OldNinja *c = new OldNinja("3", p2);
OldNinja *d = new OldNinja("4", p2);
TrainedNinja *e = new TrainedNinja("5", p3);
TrainedNinja *f = new TrainedNinja("6", p3);
Cowboy *g = new Cowboy("7", p1);
Cowboy *h = new Cowboy("8", p1);
Cowboy *i = new Cowboy("9", p1);
Cowboy *j = new Cowboy("10", p1);
Cowboy *k = new Cowboy("11", p1);

TEST_CASE("Name")
  {
   CHECK_EQ((Tom->name), "Tom");
   CHECK_EQ((Alice->name), "Alice");
   CHECK_EQ((Aviv->name), "Aviv");
  }
 TEST_CASE("Distance")
 {
    CHECK(p1.distance(p2) ==  p2.distance(p1));
    CHECK(p2.distance(p3) ==  p3.distance(p2));
    CHECK(q1.distance(q2) ==  q2.distance(q1));

    CHECK(p1.distance(p1) ==  0);
    CHECK(p1.distance(p2) ==  5);

 }
  TEST_CASE("Move")
  {
   double d = (Tom->p).distance(Aviv->p);
 //  Tom->move(Aviv);
   double d2 = (Tom->p).distance(Aviv->p);
   CHECK(d > d2);
   double d3 = (Tom->p).distance(Alice->p);
 //  Tom->move(Alice);
   double d4 = (Tom->p).distance(Alice->p);
   CHECK(d4 == d3);

  }
  TEST_CASE("Team")
  {
    Team team_A(Tom);
    team_A.add(Alice);
    Team team_B(Aviv);

    CHECK_EQ(team_A.stillAlive() , 2);
    CHECK_EQ(team_B.stillAlive() , 1);

    CHECK_THROWS(team_A.add(Aviv));
    CHECK_THROWS(team_B.add(Tom));
    CHECK_THROWS(team_B.add(Alice));
     while(team_B.stillAlive() > 0)
     {
        team_A.attack(&team_B);
     }
     CHECK_EQ(team_B.stillAlive(), 0);
     CHECK_THROWS(team_A.attack(&team_B));
     CHECK_THROWS(team_B.attack(&team_A));
     CHECK(team_B.stillAlive() < 0);

     Team team_c(a);
     team_c.add(b);
     team_c.add(c);
     team_c.add(d);
     team_c.add(e);
     team_c.add(f);
     team_c.add(g);
     team_c.add(h);
     team_c.add(i);
     team_c.add(j);

     CHECK_THROWS(team_c.add(k));
  }

  
 

    

