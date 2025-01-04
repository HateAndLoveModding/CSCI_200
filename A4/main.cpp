/* CSCI 200: A4
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //SFML documentation
 * Description: Learn how to use the graphics module in SFML.
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include "Bubble.h"
#include <random>
#include <chrono>
using namespace std;

int main() {
    RenderWindow window( VideoMode(800, 800), "A4" );
    vector<Bubble> bubbles;

    for(int i=0; i<5; i++) {
        Bubble bubble;
        bubbles.push_back(bubble);
    }

    Clock clock;
    const float frameTime = 1.0f / 60.0f;
    bool mousePressed = false;
    bool keyPressed = false;
    
    Event event;
    while( window.isOpen() ) {
        window.clear(Color::White);
        float elapsedTime = clock.getElapsedTime().asSeconds();

        for(Bubble &theBubble:bubbles) {
            if (elapsedTime >= frameTime) {
                theBubble.updatePosition(window.getSize().x, window.getSize().y);
                clock.restart();
            }
            theBubble.draw(window);
        }

        window.display();
        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }
        if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            if(!mousePressed) {  // Only add a bubble if the button was not previously pressed
                Bubble bubble(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
                bubbles.push_back(bubble);
                mousePressed = true;  // Set the flag to indicate the button is now pressed
            }
        }
        if(event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
            mousePressed = false;  // Reset the flag when the button is released
        }
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::D) {
            if(!keyPressed) {
                if(!bubbles.empty()) {
                    bubbles.pop_back();
                }
                //keyPressed = true;
            }
        }
        // if(event.type == Event::KeyReleased && event.key.code == Keyboard::D) {
        //     keyPressed = false;  // Reset the flag when the button is released
        // }

        if(event.type == Event::KeyPressed) {
            if(event.key.code == Keyboard::Escape || event.key.code == Keyboard::Q) {
                window.close();
            }
        }
    }
    return 0;
}
