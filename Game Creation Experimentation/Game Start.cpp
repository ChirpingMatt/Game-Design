#include "TitleScreen.h"
#include "Game.h"

void Game::Start(void)
{
    if (_gameState != Initializing)
    {
        return;
    }

    _mainWindow.create(sf::VideoMode(1024,768,32), "MyGame");
    _gameState = Game::TitleScreen;

    while(!IsExiting())
    {
        GameLoop();
    }

    _mainWindow.close();
}

bool Game::IsExiting()
{
    if (_gameState == Game::Closing)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while (_mainWindow.pollEvent(currentEvent))
    {
        switch (_gameState)
        {
            case Game::TitleScreen:
            {
                ShowTitleScreen();
                break;
            }
            case Game::Playing:
            {
                _mainWindow.clear(sf::Color(255,0,0));
                _mainWindow.display();

                if (currentEvent.type == sf::Event::Closed)
                {
                    _gameState = Game::Closing;
                }
                break;
            }
        }
    }
}

void Game::ShowTitleScreen()
{
    Title _titleScreen;
    _titleScreen.Display(_mainWindow);
    _gameState = Game::Playing;
}

Game::GameState Game::_gameState = Initializing;
sf::RenderWindow Game::_mainWindow;

int main(int argc, char* argv[])
{
    Game::Start();

    return 0;
}
