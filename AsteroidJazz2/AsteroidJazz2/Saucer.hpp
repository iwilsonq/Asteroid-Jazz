//
//  Saucer.hpp
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/29/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#ifndef __Asteroid_Jazz__Saucer__
#define __Asteroid_Jazz__Saucer__

#include <Enemy.hpp>

class Saucer : public Enemy
{
    
public:
    Saucer(const Saucer&) = delete;
    Saucer& operator=(const Saucer&) = delete;
    using Enemy::Enemy;
    
    virtual bool isCollide(const Entity& other)const;
    virtual void update(sf::Time deltaTime);
    virtual void onDestroy();
    static void newSaucer(World& world);

};

class SmallSaucer : public Saucer
{
    public :
    SmallSaucer(World& world);
    virtual int getPoints()const;
    virtual void update(sf::Time deltaTime);
private:
    sf::Time _timeSinceLastShoot;
};

class BigSaucer : public Saucer
{
public:
    BigSaucer(World& world);
    virtual int getPoints()const;
};

#endif /* defined(__Asteroid_Jazz__Saucer__) */
