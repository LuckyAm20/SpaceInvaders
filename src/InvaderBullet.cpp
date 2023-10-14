#include "InvaderBullet.h"
#include "Player.h"
InvaderBullet::InvaderBullet(float x, float y, float speed) : Bullet(x,y,2, speed)
{

}

InvaderBullet::InvaderBullet()
{

}

void InvaderBullet::add_bullet(InvaderBullet& bullet)
{
    i_bullet.push_back(bullet);
}

void InvaderBullet::draw_bullets(sf::RenderWindow& window)
{ 
    for (int i = 0; i < i_bullet.size(); i++)
    {
        window.draw(i_bullet[i].get_rect());
    }
}

void InvaderBullet::control_bullets(sf::Time time)
{
    for (int i = 0; i < i_bullet.size(); i++)
    {
        i_bullet[i].move(time);
    }
}

void InvaderBullet::check_player_col(Player* player)
{
    for (int i = 0; i < i_bullet.size(); i++)
    {
        if (i_bullet[i].get_rect().getPosition().y > 800)
        {
            i_bullet.erase(i_bullet.begin() + i);
        }
        else if (player->get_sprite().getGlobalBounds().intersects(i_bullet[i].get_rect().getGlobalBounds()))
        {
            player->damage();
            i_bullet.erase(i_bullet.begin() + i);
        }
    }
}

void InvaderBullet::clear()
{
    i_bullet.clear();
}