#ifndef INVADERBULLET_H
#define INVADERBULLET_H
#include "InvaderBullet.h"
#include "Bullet.h"
class Player;
class InvaderBullet : public Bullet
{
    public:
        InvaderBullet(float x, float y, float speed);
        InvaderBullet();

        void add_bullet(InvaderBullet& bullet);
        void draw_bullets(sf::RenderWindow& window);
        void control_bullets(sf::Time time);
        void check_player_col(Player* player);
        void clear();
private:
    std::vector<InvaderBullet> i_bullet;
};

#endif
