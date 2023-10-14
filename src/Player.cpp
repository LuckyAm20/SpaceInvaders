#include "Player.h"
#include "Invader.h"
Player::Player(float x, float y) : Entity(x, y, 3, 0.5f)
{
    set_texture("resources/player.png");
}

int Player::get_hp()
{
    return hp_n;
}

void Player::check_col(Invader* invader)
{
    if (invader->get_sprite().getGlobalBounds().intersects(this->get_sprite().getGlobalBounds()))
        {
        this->damage();
        invader->damage();
        }
}

void Player::control(sf::Time time, PlayerBullet &playerbullet, sf::Time shoottimer, Times &times)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(get_sprite().getPosition().x > 0)
        {
            move(time, 1,0.5f);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(get_sprite().getPosition().x < 760)
        {
            move(time, 2,0.5f);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(shoottimer.asSeconds() > 0.3f)
        {
           
            PlayerBullet temp(sprite.getPosition().x + 16, sprite.getPosition().y + 2);
            playerbullet.add_bullet(temp);
            times.restart_p_shoot();
        }
    }
}

void Player::game_over( bool &menu, bool &init)
{
    if(is_dead())
    {
        init = false;
        menu = true;
    }
}