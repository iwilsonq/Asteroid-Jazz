//
//  random.hpp
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/29/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#ifndef Asteroid_Jazz_Header_h
#define Asteroid_Jazz_Header_h

#include <cstdlib>
#include <ctime>

inline void rand_init()
{
    srand(time(NULL));
};

inline float random(float min,float max)
{
    return (rand()/float(RAND_MAX))*(max-min) + min;
}

inline int random(int min,int max)
{
    return rand()%(max-min+1) + min;
}

#endif
