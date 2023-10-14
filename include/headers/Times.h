#ifndef TIMES_H
#define TIMES_H
#include <SFML/Graphics.hpp>
class Times
{
    public:
        Times();

        sf::Time get_times();
        sf::Time get_sup();
        sf::Time get_p_shoot();
        sf::Time get_inv_shoot();

        void update_times();
        void update_p_shoot();
        void update_inv_shoot();
        void restart_times();
        void restart_p_shoot();
        void restart_inv_shoot();
        void clear();

    private:
        sf::Clock clock;       
        sf::Clock p_shoot_clock;       
        sf::Clock inv_shoot_clock; 
        sf::Time times;
        sf::Time sup;
        sf::Time p_shoot;
        sf::Time inv_shoot;  
};
#endif 
