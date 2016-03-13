#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


class Game
{
public:
    static void Start();

private:
    static bool IsExiting();
    static void GameLoop();

    static void ShowTitleScreen();

    enum GameState {Initializing, TitleScreen, MainMenu, Playing, Paused, Closing};

    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
};


#endif // GAME_H_INCLUDED
