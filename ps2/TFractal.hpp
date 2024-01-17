#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>

using namespace std;

class Triangle: public sf::Drawable{
public:
    Triangle(int d, double l, double x, double y, int color);

    int getDepth() const;
    double getLength() const;

    // coordinates of the center
    double getX() const;
    double getY() const;

    ~Triangle();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(triangle, states);
    }
    int depth;
    double length;
    double pos_x;
    double pos_y;
    sf::ConvexShape triangle;
};

void fTree(const Triangle &parent, std::vector<Triangle> &v);

Triangle::Triangle(int d, double l, double x, double y, int color): depth(d), length(l), pos_x(x), pos_y(y) {
    
    double h = l*sqrt(3)/2; //height

    triangle.setPointCount(3);

    triangle.setPoint(0, sf::Vector2f(0,0)); // x = 0, y = 0;
    triangle.setPoint(1, sf::Vector2f(l, 0)); // x = l, y = 0;
    triangle.setPoint(2, sf::Vector2f(l/2, h)); // x = l/2, y = -h

    triangle.setFillColor(sf::Color::Black);
    triangle.setOutlineThickness(2.f);
    triangle.setOutlineColor(sf::Color(color, rand() % 255, rand() % 255)); //random color

    triangle.setPosition(pos_x,pos_y);
}

int Triangle::getDepth() const{
    return depth;
}  
double Triangle::getLength() const{
    return length;
}

double Triangle::getX() const{
    return pos_x;
}
double Triangle::getY() const{
    return pos_y;
}

Triangle::~Triangle(){
    length = 0;
    depth = 0;
}

void fTree(const Triangle &parent, vector<Triangle> &v){
    if(parent.getDepth() == 0) return;

    int color = rand() % 255;

    Triangle Left(parent.getDepth()-1.0, parent.getLength()/2.0,\
        parent.getX() - parent.getLength()/4.0, parent.getY() - parent.getLength()*sqrt(3.0)/4.0, color);

    Triangle Right(parent.getDepth()-1.0, parent.getLength()/2.0,\
        parent.getX() + parent.getLength(), parent.getY(), color);

    Triangle Bottom(parent.getDepth()-1.0, parent.getLength()/2.0,\
        parent.getX(), parent.getY() + parent.getLength()*sqrt(3.0)/2.0, color);

    v.push_back(Left);
    v.push_back(Right);
    v.push_back(Bottom);
    
    fTree(Left, v);
    fTree(Right, v);
    fTree(Bottom, v);

}