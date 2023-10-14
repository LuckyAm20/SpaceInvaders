#include "Entity.h"

Entity::Entity(float x, float y, float speed)
{
    start.x = x;
    start.y = y;
    hp_n = 1;
    speed_n = speed;
    sprite.setPosition(start);
}

Entity::Entity(float x, float y, int hp, float speed)
{
    start.x = x;
    start.y = y;
    hp_n = hp;
    speed_n = speed;
    sprite.setPosition(start);
}

sf::Sprite &Entity::get_sprite()
{
    return sprite;
}

sf::Vector2f Entity::get_start()
{
    return start;
}

void Entity::set_texture(std::string name)
{
    if(!texture.loadFromFile(name))
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        sprite.setTexture(texture);
    }
}

void Entity::set_hp(int value)
{
    hp_n = value;
}

void Entity::move(sf::Time time, int dir, float speed)
{
    switch(dir)
    {
        case 1: 
           sprite.move(-1 * speed * time.asMilliseconds(), 0);
           break;
        case 2: 
           sprite.move(speed * time.asMilliseconds(), 0);
           break;
        case 3: 
           sprite.move(0, -1 * speed * time.asMilliseconds());
           break;
        case 4: 
           sprite.move(0, speed * time.asMilliseconds());
           break;
    }
}

void Entity::damage()
{
    hp_n--;
}

bool Entity::is_dead()
{
    return (hp_n) ? false : true;
}


