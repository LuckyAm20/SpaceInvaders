#ifndef INVADER_H
#define INVADER_H
#include "Entity.h"
#include "InvaderBullet.h"
#include "Times.h"
#include "SceneGame.h"
extern float speed_high;
class Invader : public Entity
{
    public:
        Invader(float x, float y, float speed);
        ~Invader();
        void atack(InvaderBullet& invaderbullet, sf::Time time, Times &times);
        void control(sf::Time time);
        void set_dir(int dir);
        bool is_end();
    private:
        int dir_n;
        int end;
};
#endif 
