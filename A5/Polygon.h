#ifndef POLYGON
#define POLYGON
#include <SFML/Graphics.hpp>
#include "Coordinate.h"
class Polygon {
    public:
        Polygon();
        Polygon(int);
        virtual ~Polygon();
        void setColor(sf::Color);
        void draw(sf::RenderWindow&);
        void setCoordinate(int, Coordinate);
        virtual bool validate() = 0;
    protected:
        short int numVerticies;
        Coordinate* verticies;
    private:
        sf::Color _color;
};

#endif