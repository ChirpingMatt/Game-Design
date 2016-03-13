#include "TitleScreen.h"


void Title::Display(sf::RenderWindow& window)
{
    sf::Texture image;
    if (!image.loadFromFile("Images/Image Test.jpg"))
    {
        std::cout << "Error: Occurred in Title::Display: Image not found." << std::endl;
        return;
    }

    sf::Sprite sprite(image);

    window.draw(sprite);
    window.display();

    sf::Event event;
    while (true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed
                || event.type == sf::Event::MouseButtonPressed
                || event.type == sf::Event::Closed)
            {
                return;
            }
        }
    }
}
