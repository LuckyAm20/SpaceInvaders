 #ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
    public:
        Bullet(float x, float y,  int dir, float speed);
        Bullet(float x, float y, int dir);
        Bullet();

        virtual void draw_bullets(sf::RenderWindow& window)=0;
        virtual void control_bullets(sf::Time time)=0;
        virtual void clear()=0;

        sf::RectangleShape get_rect();
        void move(sf::Time time);

    protected:
        float speed_n;
        sf::RectangleShape rect;
        int dir_n; 
};
#endif 
