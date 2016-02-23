//
//  Meteor.h
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/29/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#ifndef __Asteroid_Jazz__Meteor__
#define __Asteroid_Jazz__Meteor__

#include "Enemy.hpp"

class Meteor : public Enemy
{
public:
    Meteor(const Meteor&) = delete;
    Meteor& operator=(const Meteor&) = delete;
    using Enemy::Enemy;
    
    virtual bool isCollide(const Entity& other)const;
    virtual void update(sf::Time deltaTime);
};

class BigMeteor : public Meteor
{
    public :
    BigMeteor(World& world);
    virtual int getPoints()const;
    virtual void onDestroy();
};

class MediumMeteor : public Meteor
{
    public :
    MediumMeteor(World& world);
    virtual int getPoints()const;
    virtual void onDestroy();
};

class SmallMeteor : public Meteor
{
    public :
    SmallMeteor(World& world);
    virtual int getPoints()const;
    virtual void onDestroy();
};
#endif /* defined(__Asteroid_Jazz__Meteor__) */
