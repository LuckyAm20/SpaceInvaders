#include "Invaders.h"
#include "PlayerBullet.h"
#include "InvaderBullet.h"
#include "Invader.h"
Invaders::Invaders()
{

}

void Invaders::add_inv()
{
    int height = 50;
    for (int j = 0; j < 5; j++)
    {        
        for (int i = 0; i < 11; i++)
        {
            invaders.push_back(new Invader(i  * 50.0 +50, height, 0.01f));
        }
        height += 40;
    }
}

void Invaders::add_inv_hard()
{
    speed_high = 0;
    int height = 50;
    for (int j = 0; j < 5; j++) 
    {
        for (int i = 0; i < 11; i++)
        {
           invaders.push_back(new Invader(i * 50.0 + 50, height, 0.05f));
        }
        height += 40;
    }
}
void Invaders::control(InvaderBullet& invaderbullet, Times& time)
{
    for (int i = 0; i < invaders.size(); i++)
    {
        
        /*
        if (invaders[i]->get_sprite().getPosition().x <=0)
            for (int i = 0; i < invaders.size(); i++)
            {
                invaders[i]->set_dir(2);
            }
        
        if (invaders[i]->get_sprite().getPosition().x >= 760)
            for (int i = 0; i < invaders.size(); i++)
            {
                invaders[i]->set_dir(1);
            }*/
        
        

        invaders[i]->control(time.get_sup());
        invaders[i]->atack(invaderbullet, time.get_inv_shoot(), time);
    }
}

void Invaders::draw_inv(sf::RenderWindow &window)
{
    for (int i = 0; i < invaders.size(); i++)
    {
        window.draw(invaders[i]->get_sprite());
    }
}

void Invaders::update_inv(PlayerBullet& playerbullet, Player* player)
{
    for(int i = 0; i < invaders.size(); i++)
    {
        playerbullet.check_invader_col(invaders[i]);
        player->check_col(invaders[i]);
        if(invaders[i]->is_dead())
        {
            delete invaders[i];
            invaders.erase(invaders.begin() + i);
        }
    }
}

void Invaders::game_over(bool& menu, bool& init)
{
    for (int i = 0; i < invaders.size(); i++)
    {
        if (invaders[i]->is_end())
        {
            init = false;
            menu = true;
        }
    }
}

void Invaders::clear()
{
    invaders.clear();
}