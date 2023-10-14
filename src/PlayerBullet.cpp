#include "PlayerBullet.h"
#include "Invader.h"

PlayerBullet::PlayerBullet(float x, float y) : Bullet(x, y, 1)
{

}

PlayerBullet::PlayerBullet()
{

}

void PlayerBullet::add_bullet(PlayerBullet& bullet) 
{
    p_bullet.push_back(bullet);
}

void PlayerBullet::draw_bullets(sf::RenderWindow& window) 
{
    for (int i=0;i< p_bullet.size(); i++)
    {
        window.draw(p_bullet[i].get_rect());
    }
}

void PlayerBullet::control_bullets(sf::Time time)
{
    for (int i = 0; i < p_bullet.size(); i++)
    {
        p_bullet[i].move(time);
    } 
}

void PlayerBullet::check_invader_col(Invader* invader)
{
    for (int i = 0; i < p_bullet.size(); i++)
    {
        if (p_bullet[i].get_rect().getPosition().y < 0)
        {
            p_bullet.erase(p_bullet.begin() + i);
        }
        else if (invader->get_sprite().getGlobalBounds().intersects(p_bullet[i].get_rect().getGlobalBounds()))
        {
            p_bullet.erase(p_bullet.begin() + i);
            invader->damage();
        }
    }
}

void PlayerBullet::clear()
{
    p_bullet.clear();
}