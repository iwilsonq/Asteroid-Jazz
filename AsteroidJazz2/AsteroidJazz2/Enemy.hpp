//
//  Enemy.h
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/29/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#ifndef __Asteroid_Jazz__Enemy__
#define __Asteroid_Jazz__Enemy__

#include <Entity.hpp>
#include <Configuration.hpp>


class Enemy : public Entity
{
public:
    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;
    Enemy(Configuration::Textures tex_id,World& world);
    
    virtual int getPoints()const = 0;
    virtual void onDestroy();
};

#endif /* defined(__Asteroid_Jazz__Enemy__) */
