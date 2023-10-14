#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(float x, float y, int dir)
{
    rect.setSize(sf::Vector2f(3,5));
    rect.setPosition(x, y);
    speed_n = 0.5f;
    dir_n = dir;
}

Bullet::Bullet(float x, float y, int dir, float speed)
{
    rect.setSize(sf::Vector2f(3,5));
    rect.setPosition(x, y);
    speed_n = speed;
    dir_n = dir;
}

sf::RectangleShape Bullet::get_rect()
{
    return rect;
}

void Bullet::move(sf::Time time)
{
    switch(dir_n)
    {
        case 1:
           rect.move(0, -1 * speed_n * time.asMilliseconds());
           break;
        case 2:
           rect.move(0, speed_n * time.asMilliseconds());
           break;
    }
}
