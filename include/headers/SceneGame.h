#ifndef SCENEGAME_H
#define SCENEGAME_H
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <string>
#include "End.h"
#include <sstream>

class SceneGame
{
    public:
        SceneGame();
        void draw_text(sf::RenderWindow &window, int hp);
        static void add_score();
        static void clear_score();
        static int get_score();
        void show_record(End &end);
    private:
        sf::Font font;
        sf::Text hp_text;
        sf::Text score_text;
        sf::Text name;
        static int score;
};
#endif