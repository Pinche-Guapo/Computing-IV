if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) spritePosition.y -= yVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) spritePosition.y += yVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) spritePosition.x -= xVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) spritePosition.x += xVelocity;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) sprite.setScale(-1,1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) sprite.setScale(1,1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) sprite.rotate(10.f);
