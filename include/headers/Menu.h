#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
class  Menu_1
{
public:
    Menu_1();
    void draw_menu(sf::RenderWindow& window);
    void close(sf::RenderWindow& window);
private:
    sf::Font font;
    sf::Text menu_text_1;
    sf::Text menu_text;
    sf::Texture texture;
    sf::Sprite sprite;
};