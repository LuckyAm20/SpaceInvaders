#include "Menu.h"
Menu_1::Menu_1()
{
    if (!font.loadFromFile("resources/font.otf"))
    {
        std::cerr << "error";
        exit(1);
        
    }

    menu_text.setScale(3, 3);
    menu_text.setFillColor(sf::Color::Blue);
    menu_text.setPosition(25, 100);
    menu_text.setFont(font);
    menu_text.setString("Space Inavaders");

    menu_text_1.setScale(2, 2);
    menu_text_1.setFillColor(sf::Color::Blue);
    menu_text_1.setPosition(70, 200);
    menu_text_1.setFont(font);
    menu_text_1.setString("press ENTER to play");

    texture.loadFromFile("resources/picture.png");
    sprite.setTexture(texture);
    sprite.setPosition(200,325);
}

void Menu_1::draw_menu(sf::RenderWindow& window)
{
    window.draw(menu_text);
    window.draw(menu_text_1);
    window.draw(sprite);
}

void Menu_1::close(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
         window.close();
    }
}