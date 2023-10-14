#ifndef INVADERS_H
#define INVADERS_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Invader.h"
#include "PlayerBullet.h"
#include "InvaderBullet.h"
#include "Player.h"
#include "Times.h"
class Player;
class Invaders
{
    public:
        Invaders();
        void add_inv();
        void add_inv_hard();
        void control(InvaderBullet& invaderbullet, Times& time);
        void update_inv(PlayerBullet& playerbullet, Player* player); 
        void draw_inv(sf::RenderWindow& window);
        void clear();
        void game_over(bool& menu, bool& init);
    private:
        std::vector<Invader*> invaders;
};
#endif 
