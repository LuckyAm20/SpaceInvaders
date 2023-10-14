#include "Invader.h"
Invader::Invader(float x, float y, float speed) : Entity(x, y, speed)
{
    int num=rand() % 4 + 1;
    switch (num)
    {
    case 1:
        set_texture("resources/green.png");
        break;
    case 2:
        set_texture("resources/red.png");
        break;
    case 3:
        set_texture("resources/red_1.png");
        break;
    case 4:
        set_texture("resources/red_2.png");
        break;
    }
    dir_n = 2;
    end = 0;
}

float speed_high = 0;
Invader::~Invader()
{
    SceneGame::add_score();
    speed_high += 0.01f;
}

bool Invader::is_end()
{
    return (end) ? true : false;
}

void Invader::set_dir(int dir)
{
    dir_n = dir;
}

void Invader::control(sf::Time time)
{
    
    if (get_sprite().getPosition().x >= get_start().x + 210)
    {
        dir_n = 1;
    }
    else if (get_sprite().getPosition().x <= get_start().x - 50)
    {
        dir_n = 2;
    }
    if ((get_sprite().getPosition().x <= get_start().x - 45)||(get_sprite().getPosition().x >= get_start().x + 205))
        move(time, 4, speed_n + speed_high);

    





    move(time, dir_n, speed_n + speed_high);
    if (get_sprite().getPosition().y > 800)
        end = 1;
}

void Invader::atack(InvaderBullet& invaderbullet, sf::Time time, Times &times)
{
    int new_time = rand() % 3 + 1;
    int delta = rand() % 10;
    float now_time = new_time + (delta / 10);
    if(time.asSeconds() >= now_time)
    {
        bool shoot = false;
        int rand;
        if(SceneGame::get_score() >= 550)
        {
            rand = std::rand() % 4 + 9;
        }
        else
        {
            rand = std::rand() % 9 + 5;
        }

        if(rand == 10 && (shoot == false))
        {
            shoot = true;
            int rand_speed = std::rand() % 3 + 4;
            InvaderBullet temp(sprite.getPosition().x + 16, sprite.getPosition().y - 20, rand_speed / 10.0f);
            invaderbullet.add_bullet(temp);
        }
       times.restart_inv_shoot();
    }
}



