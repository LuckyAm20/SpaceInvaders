#include "SceneGame.h"

SceneGame::SceneGame()
{
    font.loadFromFile("resources/font.otf");
    hp_text.setPosition(10,0);
    hp_text.setScale(1, 1);
    hp_text.setFillColor(sf::Color::Red);
    hp_text.setFont(font);

    name.setPosition(285, -4);
    name.setScale(1.2, 1.2);
    name.setFillColor(sf::Color::Magenta);
    name.setFont(font);
    name.setString("Space Invaders");

    score_text.setPosition(660, 0);
    score_text.setFillColor(sf::Color::Green);
    score_text.setScale(1,1);
    score_text.setFont(font);
}




void SceneGame::draw_text(sf::RenderWindow &window, int hp)
{
    std::ostringstream hp_s;
    hp_s << hp;		
    std::ostringstream score_s;
    score_s << score;
    hp_text.setString("Health: " + hp_s.str());
    score_text.setString("Score: " + score_s.str());
    window.draw(hp_text);
    window.draw(score_text);
    window.draw(name);
}

int SceneGame::score = 0;

void SceneGame::add_score()
{
    score += 10;
}

void SceneGame::clear_score()
{
    score = 0;
}

int SceneGame::get_score()
{
    return score;
}

void SceneGame::show_record(End &end)
{
    end.check_record(score);
    
}
