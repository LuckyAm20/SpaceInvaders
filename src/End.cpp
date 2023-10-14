#include "End.h"

End::End()
{
    font.loadFromFile("resources/font.otf");

    text_end.setScale(3, 3);
    text_end.setFillColor(sf::Color::Blue);
    text_end.setPosition(230,200);
    text_end.setFont(font);

    text_end_1.setScale(3, 3);
    text_end_1.setFillColor(sf::Color::Blue);
    text_end_1.setPosition(250,350);
    text_end_1.setFont(font);
}

void End::check_record(int last)
{
    if (last == 1100)
        text_end.setString("You win");
    else
        text_end.setString("Game Over");
    std::ostringstream score;
    score << last;
    text_end_1.setString("SCORE:"+score.str());
    
}

void End::draw_end(sf::RenderWindow &window)
{
    window.draw(text_end_1);
    window.draw(text_end);
}




