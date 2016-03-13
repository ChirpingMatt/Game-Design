#include "Menus.h"

std::vector<GameMenu> menuVector;

GameMenu::GameMenu (GameMenu::MenuType t)
{
    mType = t;
}

GameMenu::MenuItem::MenuItem (GameMenu::MenuItem::itemType t, std::string name)
{
    iType = t;
    itemName = name;
    resultNumber = -1;
    isSelected = false;
}

GameMenu::MenuItem::MenuItem (GameMenu::MenuItem::itemType t, int nResult, std::string name)
{
    iType = t;
    itemName = name;
    resultNumber = nResult;
    isSelected = false;
}

void GameMenu::Display(sf::RenderWindow& window, sf::Texture beneathMenu)
{
    sf::Sprite below(beneathMenu);
    int s = itemVector.size();

    sf::Font menuFont;
    if (!menuFont.loadFromFile("Fonts/COPRGTB.ttf"))
    {
        std::cout << "Error: Occurred in GameMenu::Display: Font file not found." << std::endl;
        return;
    }
    sf::Text itemText[s];

    for (int a=0; a<s; a++)
    {
        itemText[a].setString(itemVector[a].itemName);
        itemText[a].setCharacterSize(30);
    }

    itemVector[0].isSelected = true;
    int selectedItem = 0;

    while (true)
    {
        window.draw(below);
        switch (mType)
        {
            case TitleMenu:
            {
                for (int i=0; i<s; i++)
                {
                    if (itemVector[i].isSelected == true)
                    {
                        itemText[i].setColor(sf::Color::Yellow);
                        selectedItem = i;
                    }
                    else
                    {
                        itemText[i].setColor(sf::Color::White);
                    }
                    itemText[i].setPosition(100,100 + 50*i);
                    window.draw(itemText[i]);
                }
                window.display();
                break;
            }
            case PauseMenu:
            {
                sf::Texture pauseBG;
                pauseBG.loadFromFile("Images/PauseMenuBG.jpg");
                sf::Sprite BGSprite(pauseBG);
                BGSprite.setPosition(100, 100);
                window.draw(BGSprite);
                for (int i=0; i<s; i++)
                {
                    if (itemVector[i].isSelected == true)
                    {
                        itemText[i].setColor(sf::Color::Yellow);
                        selectedItem = i;
                    }
                    else
                    {
                        itemText[i].setColor(sf::Color::White);
                    }
                    itemText[i].setPosition(200,150 + 40*i);
                    window.draw(itemText[i]);
                }
                window.display();
                break;
            }
            case SubMenu:
            {
                sf::Texture subBG;
                subBG.loadFromFile("Images/SubMenuBG.jpg");
                sf::Sprite BGSprite(subBG);
                BGSprite.setPosition(200, 150);
                window.draw(BGSprite);
                for (int i=0; i<s; i++)
                {
                    if (itemVector[i].isSelected == true)
                    {
                        itemText[i].setColor(sf::Color::Yellow);
                        selectedItem = i;
                    }
                    else
                    {
                        itemText[i].setColor(sf::Color::White);
                    }
                    itemText[i].setPosition(300,200 + 40*i);
                    window.draw(itemText[i]);
                }
                window.display();
                break;
            }
        }
        switch(HandleMenuInteraction(itemVector))
        {

        }
    }
}
