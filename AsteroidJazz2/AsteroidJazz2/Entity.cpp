//
//  Entity.cpp
//  Asteroid Jazz
//
//  Created by Ian Wilson on 12/28/15.
//  Copyright (c) 2015 APM. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(Configuration::Textures tex_id, World& world)
: _world(world)
, _alive(true)
{
    sf::Texture& texture = Configuration::textures.get(tex_id);
    _sprite.setTexture(texture);
    _sprite.setOrigin(texture.getSize().x/2.f,texture.getSize().y/2.f);
}
Entity::~Entity()
{
}


const sf::Vector2f& Entity::getPosition() const
{
    return _sprite.getPosition();
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite,states);
}

bool Entity::isAlive() const
{
    return _alive;
}

void Entity::onDestroy()
{
    _alive = false;
}