#include <SFML/Graphics.hpp>
using namespace sf;
#include "Bubble.h"
#include <random>
#include <chrono>
using namespace std;

Bubble::Bubble() {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> intDistr(100, 400);
    uniform_int_distribution<int> intDistr1(10, 50);
    uniform_int_distribution<int> intDistr2(0, 256);
    uniform_real_distribution<float> floatDistr(-5, nextafter(5, numeric_limits<float>::max()));
    _xDir = floatDistr(mt);
    _yDir = floatDistr(mt);
    _circle.setRadius(intDistr1(mt));
    _circle.setPosition(intDistr(mt), intDistr(mt));
    _circle.setFillColor(Color(intDistr2(mt), intDistr2(mt), intDistr2(mt)));
}
Bubble::Bubble(double x, double y) {
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> intDistr1(10, 50);
    uniform_int_distribution<int> intDistr2(0, 256);
    uniform_real_distribution<float> floatDistr(-5, nextafter(5, numeric_limits<float>::max()));
    _xDir = floatDistr(mt);
    _yDir = floatDistr(mt);
    _circle.setRadius(intDistr1(mt));
    _circle.setPosition(x, y);
    _circle.setFillColor(Color(intDistr2(mt), intDistr2(mt), intDistr2(mt)));
}
double Bubble::getXDir() {
    return _xDir;
}
double Bubble::getYDir() {
    return _yDir;
}
void Bubble::updatePosition(int width, int height) {
    double x = _circle.getPosition().x;
    double y = _circle.getPosition().y;
    double diameter = _circle.getRadius()*2;
    if(x < 0) {
        _xDir *= -1;
        x = 0;
    } else if(x+diameter > width) {
        _xDir *= -1;
        x = width-diameter;
    }
    if(y < 0) {
        _yDir *= -1;
        y = 0;
    } else if(y+diameter > height) {
        _yDir *= -1;
        y = height-diameter;
    }
    _circle.setPosition(x,y);
    _circle.move(_xDir, _yDir);
}
void Bubble::setXDir(double x) {
    _xDir = x;
}
void Bubble::setYDir(double y) {
    _yDir = y;
}
void Bubble::draw(RenderWindow& window) {
    window.draw(_circle);
}

