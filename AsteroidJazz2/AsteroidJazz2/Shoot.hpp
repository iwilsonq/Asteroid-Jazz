//
//  Shoot.hpp
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/29/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#ifndef __Asteroid_Jazz__Shoot__
#define __Asteroid_Jazz__Shoot__

#include "Entity.hpp"

class Shoot : public Entity
{
public:
    Shoot(const Shoot&) = delete;
    Shoot& operator=(const Shoot&) = delete;
    using Entity::Entity;
    virtual void update(sf::Time deltaTime);
protected:
    sf::Time _duration;
};

class ShootPlayer : public Shoot
{
    public :
    ShootPlayer(const ShootPlayer&) = delete;
    ShootPlayer& operator=(const ShootPlayer&) = delete;
    ShootPlayer(Player& from);
    
    virtual bool isCollide(const Entity& other)const;
};

class SmallSaucer;

class ShootSaucer : public Shoot
{
    public :
    ShootSaucer(const ShootSaucer&) = delete;
    ShootSaucer& operator=(const ShootSaucer&) = delete;
    
    ShootSaucer(SmallSaucer& from);
    virtual bool isCollide(const Entity& other)const;
};
#endif /* defined(__Asteroid_Jazz__Shoot__) */
