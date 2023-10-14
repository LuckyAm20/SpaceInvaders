#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerBullet.h"
#include "Entity.h"
#include "Times.h"
class Invader;
class Player : public Entity
{
    public:
        Player(float x, float y);
        int get_hp();
        void control(sf::Time time, PlayerBullet &playerbullet, sf::Time shoottimer, Times &times);
        void game_over(bool &menu, bool &init);
        void check_col(Invader* invader);
};
#endif 
