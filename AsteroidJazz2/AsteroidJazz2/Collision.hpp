//
//  Collision.h
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/28/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#ifndef __Asteroid_Jazz__Collision__
#define __Asteroid_Jazz__Collision__

#include <SFML/Graphics.hpp>

class Collision
{
public:
    Collision() = delete;
    Collision(const Collision&) = delete;
    Collision& operator=(const Collision&) = delete;
    static bool circleTest(const sf::Sprite& first, const sf::Sprite& second);
};


#endif /* defined(__Asteroid_Jazz__Collision__) */
