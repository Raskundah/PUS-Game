#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>


int main()
{

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pepsi PISS FONT", sf::Style::None) ;

#pragma region initTextures

    

    sf::Texture playerTexture;
    sf::Texture grassTexture;
    sf::Texture stickTexture;

    if (!playerTexture.loadFromFile("Assets/Player_Stand.png"))
    {
        std::cout << "Texture load failed for Assets/Player_Stand.pg" << "\n";
    }
    else
        std::cout << "Texture loaded successfully" << "\n";

    if (!grassTexture.loadFromFile("Assets/Grass.png"))
    {
        std::cout << "Texture load failed for Assets\Grass.npg" << "\n";
    }
    else
        std::cout << "Texture loaded successfully" << "\n";

    if (!stickTexture.loadFromFile("Assets/Stick.png"))
    {
        std::cout << "Texture load failed for Assets\Stick.ppg" << "\n";
    }
    else
        std::cout << "Texture loaded successfully" << "\n";

#pragma endregion

#pragma region initSprites
    sf::Sprite playerSprite;
    sf::Sprite grassSprite;
    sf::Sprite stickSprite;

    std::vector<sf::Sprite> grassVector;
    std::vector<sf::Sprite> stickVector;

    playerSprite.setTexture(playerTexture);
    grassSprite.setTexture(grassTexture);
    stickSprite.setTexture(stickTexture);

    int numGrassToAdd = 20;
   
    for (int i = 0; i < numGrassToAdd; ++i)
    {
        grassVector.push_back(grassSprite);
    }

#pragma endregion

#pragma region Position

    playerSprite.setPosition(sf::Vector2f(200.0f, 200.0f));
    playerSprite.setRotation(0);



    int randx;
    int randy;
    srand(time(NULL));


    for (int i = 0; i < grassVector.size(); ++i)
    {
        int min = 5;
        int max = 255;
        int range = max - min;

        randx = rand() % (window.getSize().x - grassTexture.getSize().x);
        randy = rand() % (window.getSize().y - grassTexture.getSize().y);

        grassVector[i].setPosition(randx, randy);

        int randRed = rand() % range;
        int randGreen = rand() % range;
        int randBlue = rand() % range;
        int scaleX = rand() % 2;
        int scaleY = rand() % 2;

        grassVector[i].setColor(sf::Color(randRed, randGreen, randBlue));
        grassVector[i].setScale(sf::Vector2f(scaleX, scaleY));
    }

    stickSprite.setPosition(sf::Vector2f(rand() % (window.getSize().x - stickTexture.getSize().x), rand() % (window.getSize().y - stickTexture.getSize().y)));
    stickSprite.setRotation(rand() % 359);
    stickVector.push_back(stickSprite);



#pragma endregion


#pragma region eventPoll


    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

#pragma endregion
#pragma region Update

        sf::Vector2f direction(0, 0);

        direction.x = 0;
        direction.y = 0;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direction.x = -1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direction.x = 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direction.y = -1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction.y = 1;
        }




        sf::Vector2f newPosition =  playerSprite.getPosition() + direction*0.5f;

        playerSprite.setPosition(newPosition);



#pragma endregion



#pragma region Display



        window.clear(sf::Color(190,201, 91));

        //DRAW THINGS
        for (int i = 0; i < grassVector.size(); ++i)
        {
            window.draw(grassVector[i]);
        }

        window.draw(playerSprite);

        for (int i = 0; i < stickVector.size(); ++i)
        {
            window.draw(stickVector[i]);
        }


        window.display();
    }


#pragma endregion

    return 0;
}