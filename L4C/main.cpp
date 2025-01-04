/* CSCI 200: L4C
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     //SFML documentation
 * Description: Learn how to use the graphics module in SFML.
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(800, 800), "L4C" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // Create textures and shapes
    Texture texture;
    if(!texture.loadFromFile("data/bubble.png")) {return -1;}

    Sprite sprite1;
    sprite1.setTexture(texture);
    sprite1.scale(.6,.6);
    sf::Vector2u textureSize = texture.getSize();
    sprite1.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    sprite1.setPosition(400, 400);

    Vertex vertices[] = {
        Vertex(Vector2f(100,100), Color::Blue, Vector2f(100,700)),
        Vertex(Vector2f(100,700), Color::Green, Vector2f(700,700)),
        Vertex(Vector2f(700,700), Color::Cyan, Vector2f(700,100)),
        Vertex(Vector2f(700,100), Color::Magenta, Vector2f(100,100))
    };

    CircleShape circle1(200);
    circle1.setPosition(200, 200);
    circle1.setFillColor(Color::Transparent);
    circle1.setOutlineColor(Color::White);
    circle1.setOutlineThickness(10);

    RectangleShape square(Vector2f(600, 600));
    square.setPosition(100, 100);
    square.setOutlineThickness(10);
    square.setOutlineColor(Color::Red);
    square.setFillColor(Color::Transparent);

    RectangleShape cross1(Vector2f(30, 210));
    cross1.setPosition(385, 295);
    cross1.setFillColor(Color::Black);

    RectangleShape cross2(Vector2f(150, 30));
    cross2.setPosition(325, 355);
    cross2.setFillColor(Color::Black);

    CircleShape cross3(40);
    cross3.setFillColor(Color::Transparent);
    cross3.setOutlineColor(Color::Black);
    cross3.setOutlineThickness(5);
    cross3.setOrigin(20, 20);
    cross3.setPosition(380, 350);

    Font font;
    if (!font.loadFromFile("data/arial.ttf")) {return -1;}

    Text text;
    text.setFont(font);
    text.setString("Click anywhere on the screen!");
    text.setCharacterSize(30);
    text.setFillColor(Color::Black);
    text.setPosition(200, 25);

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear(Color::White);

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        window.draw(sprite1);
        window.draw(vertices, 4, Quads);
        window.draw(circle1);
        window.draw(square);
        window.draw(cross1);
        window.draw(cross2);
        window.draw(cross3);
        window.draw(text);

        //  END  DRAWING HERE
        /////////////////////////////////////

        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            
            // Move circle1 to the mouse position on left-click
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    cross3.setPosition(static_cast<float>(mousePos.x) - 20, static_cast<float>(mousePos.y) - 20);
                    cross2.setPosition(static_cast<float>(mousePos.x) - 75, static_cast<float>(mousePos.y) - 15);
                    cross1.setPosition(static_cast<float>(mousePos.x) - 15, static_cast<float>(mousePos.y) - 75);
                }
            }
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}
