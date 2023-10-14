#ifndef END_H
#define END_H
#include <SFML/Graphics.hpp>
#include <sstream>
class  End
{
    public:
        End();
        void check_record(int last);
        void draw_end(sf::RenderWindow &window);
    private:
        sf::Font font;
        sf::Text text_end;
        sf::Text text_end_1;
};
#endif 
