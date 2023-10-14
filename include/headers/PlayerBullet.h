#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H
#include "Bullet.h"
class Invader;
class PlayerBullet : public Bullet
{
    public:
        PlayerBullet(float x, float y);
        PlayerBullet();

        void add_bullet(PlayerBullet& bullet);
        void draw_bullets(sf::RenderWindow& window);
        void control_bullets(sf::Time time);
        void check_invader_col(Invader* invader);
        void clear();
private:
    std::vector<PlayerBullet> p_bullet;
};
#endif
