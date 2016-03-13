#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

class GameMenu
{
public:
    enum MenuType {TitleMenu, PauseMenu, SubMenu};
    MenuType mType;

    GameMenu (MenuType);

    struct MenuItem
    {
        enum itemType {newMenu, intOption, boolOption, select, exitMenu, exitGame};
        int resultNumber;
        std::string itemName;
        bool isSelected;
        itemType iType;

        MenuItem (itemType, std::string);
        MenuItem (itemType, int, std::string);
    };
    enum MenuResult {newMenu, optionHandled, optionSelected, menuExited, gameExited};

    void Display(sf::RenderWindow& window, sf::Texture beneathMenu);

private:
    MenuResult HandleMenuInteraction(std::vector<MenuItem>& _menuItems);
    std::vector<MenuItem> itemVector;
};

#endif // MENUS_H_INCLUDED
