#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Entity
{
    public:
        Entity(float x, float y, int hp, float speed);
        Entity(float x, float y, float speed);

        sf::Sprite &get_sprite();
        sf::Vector2f get_start();

        void set_texture(std::string name);
        void set_hp(int value);

        void move(sf::Time time,int dir, float speed);
        void damage();
        bool is_dead();
     
    protected:
        sf::Vector2f start;
        sf::Texture texture;
        sf::Sprite sprite;
        float speed_n;
        int hp_n;
};
#endif
