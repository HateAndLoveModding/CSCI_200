/* CSCI 200: A5
 *
 * Author: Ryker Phelps
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 * Description: Draw shapes in SFML if the shape is valid. 
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <fstream>
#include <string>
#include "Polygon.h"
#include "Coordinate.h"
#include "ScaleneTriangle.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "Rhombus.h"
using namespace std;

int main() {
    RenderWindow window( VideoMode(800, 800), "A5" );
    char temp;
    int index = 0;
    string temp1 = "";
    vector<char> dataType;
    vector<vector<double>> data;
    ifstream fin("polygons.dat");
    if(!fin) {
        return -1;
    }
    while(!fin.eof()) {
        temp = fin.get();
        if(temp==' ' && temp1!="") {
            data.at(index).push_back(stod(temp1));
            temp1 = "";
        } else if(temp=='\n') {
            data.at(index).push_back(stod(temp1));
            temp1 = "";
            index += 1;
        } else if(temp=='S' || temp=='I' || temp=='E' || temp=='R') {
            dataType.push_back(temp);
            data.push_back(vector<double>());
        } else {
            temp1 = temp1+temp;
        }
    }
    data.at(index).push_back(stod(temp1));
    temp1 = "";
    int size = 0;
    Polygon** validPolygons = new Polygon*[size];
    Polygon* poly = nullptr;
    for(size_t i=0; i<dataType.size(); i++) {
        int coordinates = 3;
        if(dataType.at(i)=='S') {
            poly = new ScaleneTriangle();
        } else if(dataType.at(i)=='E') {
            poly = new EquilateralTriangle();
        } else if(dataType.at(i)=='I') {
            poly = new IsoscelesTriangle();
        } else {
            poly = new Rhombus();
            coordinates = 4;
        }
        for(int j=0; j<coordinates; j++) {
            poly->setCoordinate(j, Coordinate(data.at(i).at(j*2), data.at(i).at(j*2+1)));
        }
        poly->setColor(Color(data.at(i).at(coordinates*2), data.at(i).at(coordinates*2+1), data.at(i).at(coordinates*2+2)));
        if(poly->validate()) {
            Polygon** tempArray = new Polygon*[size+1];
            for(int j=0; j<size; j++) {
                tempArray[j] = validPolygons[j];
            }
            tempArray[size] = poly;
            delete[] validPolygons;
            validPolygons = tempArray;
            size+=1;
        }
    }

    Event event;
    while( window.isOpen() ) {
        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear(Color::Black);
        for(int i=0; i<size; i++) {
            validPolygons[i]->draw(window);
        }
        window.display();
    }
    return 0;
}
