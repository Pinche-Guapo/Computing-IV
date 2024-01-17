#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>
#include "TFractal.hpp"

using namespace std;

int main(int argc, char* argv[]){

    int color = rand() % 255;

    double length ;
    int depth ;

    cout << "Input format: depth of the Sierpinski triangle(enter)\t length of the triangle (enter)\n";
    cin >> depth;
    cin >> length;

    vector<Triangle> triTree;

    //put the first triangle to the vector
    triTree.push_back(Triangle(depth, length, length*5/7, length, color));

    //iterate the function to create more triangles
    fTree(triTree.front(), triTree);

    sf::RenderWindow window(sf:: VideoMode(length*3,length*3), "Sierpinski triangle");
    window.setFramerateLimit(60);
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        //iterate the vector to draw
        vector<Triangle>::iterator p;
        for(p = triTree.begin(); p!= triTree.end(); ++p){
            window.draw(*p);
        }
        window.display();
    }    

    return 0;
}

