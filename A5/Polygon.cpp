#include <SFML/Graphics.hpp>
using namespace sf;
#include "Polygon.h"
#include <iostream>
using namespace std;

Polygon::Polygon() {
    _color = Color::Red;
    numVerticies = 0;
    verticies = nullptr;
}
Polygon::Polygon(int num) {
    _color = Color::Red;
    numVerticies = num;
    verticies = new Coordinate[num];
}
Polygon::~Polygon() {
    delete[] verticies;
}
void Polygon::setColor(sf::Color color) {
    _color = color;
}
void Polygon::draw(sf::RenderWindow& window) {
    ConvexShape shape;
    shape.setFillColor(_color);
    shape.setPointCount(numVerticies);
    for(int i=0; i<numVerticies; i++) {
        shape.setPoint(i, Vector2f(verticies[i]._x, verticies[i]._y));
    }
    window.draw(shape);
}

void Polygon::setCoordinate(int index, Coordinate theCoordinate) {
    verticies[index] = theCoordinate;
}
