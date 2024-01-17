
// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window -lsfml-system
#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

using namespace std;

void transform(sf::Image& input, FibLFSR* encrypt);

int main(int argc, char* argv[])
{
    //start
    if(argc !=4){
        cout << "Usage: ./PhotoMagic [input_file_name.type] [output_file_name.type] [seed(binary)]" << endl;
        return -1;
    }
    
    string iPic = argv[1];
    string oPic = argv[2];
    FibLFSR key(argv[3]);

    //Input pic
	sf::Image inPic;
	if (!inPic.loadFromFile(iPic)) return -1;

    //Output pic
    sf::Image outPic;
    if (!outPic.loadFromFile(iPic)) return -1;
    
    transform(outPic, &key);

    // window size set up
    sf::Vector2u size = inPic.getSize();
    sf::RenderWindow inPic_window(sf::VideoMode(size.x, size.y), "INPUT PICTURE");
    sf::RenderWindow outPic_window(sf::VideoMode(size.x, size.y), "OUTPUT PICTURE");

    //bring the image
    sf::Texture inPic_text, outPic_text;
    inPic_text.loadFromImage(inPic);
    outPic_text.loadFromImage(outPic);

    sf::Sprite inPic_spr, outPic_spr;

    inPic_spr.setTexture(inPic_text);
    outPic_spr.setTexture(outPic_text);

    while (inPic_window.isOpen() && outPic_window.isOpen())
    {
        sf::Event event;
        while (inPic_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                inPic_window.close();
        }

        while(outPic_window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                outPic_window.close();
        }
        inPic_window.clear();
        inPic_window.draw(inPic_spr);
        inPic_window.display();
        outPic_window.clear();
        outPic_window.draw(outPic_spr);
        outPic_window.display();
    }

    // fredm: saving a PNG segfaults for me, though it does properly
    //   write the file
    if (!outPic.saveToFile(oPic))
        return -1;

    return 0;
}

void transform(sf::Image& input, FibLFSR* encrypt){
    int x = 0, y = 0;

    sf::Vector2u size = input.getSize();

    sf::Color p;

    for (x = 0; x< (signed)size.x; x++) {
		for (y = 0; y< (signed)size.y; y++) {
			p = input.getPixel(x, y);
			p.r = p.r ^ encrypt->generate(8);
			p.g = p.g ^ encrypt->generate(8);
			p.b = p.b ^ encrypt->generate(8);
			input.setPixel(x, y, p);
		}
	}
}