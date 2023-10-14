#include <SFML/Graphics.hpp>
#include "Times.h"
#include "Player.h"
#include "Invader.h"
#include "Entity.h"
#include "Bullet.h"
#include "PlayerBullet.h"
#include "InvaderBullet.h"
#include "Invaders.h"
#include "SceneGame.h"
#include "End.h"
#include "Menu.h"
int main()
{
    sf::RenderWindow window_1(sf::VideoMode(600, 600), "Space Invaders");
    Menu_1 m;
    while (window_1.isOpen())
    {
        sf::Event event;
        while (window_1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_1.close();
        }
        m.draw_menu(window_1);
        window_1.display();
        m.close(window_1);           
    }

    sf::RenderWindow window(sf::VideoMode(800, 800), "Space Invaders");
    Times time;
    End end;
    SceneGame scenegame;
    PlayerBullet playerbullet;
    InvaderBullet invaderbullet;
    Invaders invaders;
    Player player(400, 750);

    bool end_b = false;
    bool init = false;
    bool stage_2 = false;
    
    while (window.isOpen())
    {
        if(end_b == false)
        {
            if (init == false)
            {
                player.set_hp(3);
                invaders.add_inv();
                init = true;
            }

            if ((stage_2 == false) && (scenegame.get_score() == 550))
            {
                int hp_n = player.get_hp();
                player.set_hp(hp_n + 1);
                invaders.add_inv_hard();
                stage_2 = true;
            }

            if ((scenegame.get_score() == 1100))
            {
                end_b = true;
            }

            time.update_p_shoot();
            time.update_inv_shoot();

            while (time.get_times() > time.get_sup())
            {
                time.update_times();
                player.control(time.get_sup(), playerbullet, time.get_p_shoot(), time);
                invaders.control(invaderbullet, time);
                playerbullet.control_bullets(time.get_sup());
                invaderbullet.control_bullets(time.get_sup());

                invaderbullet.check_player_col(&player);
                invaders.update_inv(playerbullet, &player);
                invaders.game_over(end_b, init);
                player.game_over(end_b, init);
            }

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            scenegame.show_record(end);

            window.clear();
            scenegame.draw_text(window, player.get_hp());
            invaders.draw_inv(window);
            window.draw(player.get_sprite());
            playerbullet.draw_bullets(window);
            invaderbullet.draw_bullets(window);
            window.display();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            time.restart_times();
        }
        else
        {
            invaders.clear();
            playerbullet.clear();
            invaderbullet.clear();
            time.clear();
            scenegame.clear_score();

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            end.draw_end(window);
            window.display();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            } 
        }
    }
    return EXIT_SUCCESS;
}
