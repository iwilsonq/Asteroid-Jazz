//
//  World.h
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/28/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#ifndef __Asteroid_Jazz__World__
#define __Asteroid_Jazz__World__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Configuration.hpp>
#include <list>
#include <memory>

class Entity;
class World : public sf::Drawable
{
public:
    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(float x, float y);
    ~World();
    
    void add(Entity* entity);
    void clear();
    bool isCollide(const Entity& other);
    int size();
    
    void add(Configuration::Sounds sound_id);
    
    const std::list<Entity*> getEntities() const;
    int getX() const;
    int getY() const;
    void update(sf::Time deltaTime);
    
private:
    std::list<Entity*> _entities;
    std::list<Entity*> _entities_tmp;
    std::list<std::unique_ptr<sf::Sound>> _sounds;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    const int _x;
    const int _y;
    
    
};


#endif /* defined(__Asteroid_Jazz__World__) */
