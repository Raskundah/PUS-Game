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

#pragma endregion

#pragma region initSprites
    sf::Sprite playerSprite;
    sf::Sprite grassSprite;
    std::vector<sf::Sprite> grassVector;
    

    playerSprite.setTexture(playerTexture);
    grassSprite.setTexture(grassTexture);

    int numGrassToAdd = 20;
   
    for (int i = 0; i < numGrassToAdd; ++i)
    {
        grassVector.push_back(grassSprite);
    }



#pragma endregion

#pragma region Position

    playerSprite.setPosition(sf::Vector2f(000.0f, 100.0f));

    int randx;
    int randy;
    srand(time(NULL));


    for (int i = 0; i < grassVector.size(); ++i)
    {
        randx = rand() % (window.getSize().x - grassTexture.getSize().x);
        randy = rand() % (window.getSize().y - grassTexture.getSize().y);

        grassVector[i].setPosition(randx, randy);
    }




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

#pragma region Display



        window.clear(sf::Color(190,201, 91));

        //DRAW THINGS
        for (int i = 0; i < grassVector.size(); ++i)
        {
            window.draw(grassVector[i]);
        }

        window.draw(playerSprite);


        window.display();
    }


#pragma endregion

    return 0;
}