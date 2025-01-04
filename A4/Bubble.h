#ifndef BUBBLE
#define BUBBLE

#include <SFML/Graphics.hpp>

class Bubble {
    public:
        Bubble();
        Bubble(double, double);
        double getXDir();
        double getYDir();
        void updatePosition(int, int);
        void setXDir(double x);
        void setYDir(double y);
        void draw(sf::RenderWindow& window);
    private:
        sf::CircleShape _circle;
        double _xDir, _yDir;
};

#endif
