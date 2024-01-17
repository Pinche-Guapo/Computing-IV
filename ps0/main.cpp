#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{


    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);


    sf::Texture texture;
    if(!texture.loadFromFile("/home/j/Desktop/comp4/ps0/sprite.png")){
        cout << "Could not load sprite texture";
        return 0;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    sf::Vector2f spritePosition(0,0);
    sprite.setOrigin(sf::Vector2f(88, 125));

    

    sprite.setPosition(spritePosition);

    float xVelocity = 10;
    float yVelocity = 5;


    while (window.isOpen())
    {
        
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) spritePosition.y -= yVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) spritePosition.y += yVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) spritePosition.x -= xVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) spritePosition.x += xVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) sprite.setScale(-1,1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) sprite.setScale(1,1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) sprite.rotate(10.f);
        
        // Setting the limit

        if (spritePosition.x < 0 + 88 ) spritePosition.x = 800 - 88;
        if (spritePosition.x > 800 - 88) spritePosition.x = 0 + 88;
        if (spritePosition.y < 0 + 125 ) spritePosition.y = 600-125;
        if (spritePosition.y > 600 - 125) spritePosition.y = 0 + 125;

        //physics

        sprite.setPosition(spritePosition);

        window.clear();
        window.draw(sprite);
        window.display();
        
    }

    return 0;
}
