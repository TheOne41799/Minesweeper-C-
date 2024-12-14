#pragma once
#include "InputService.h"
#include "BoardService.h"
#include "ServiceLocator.h"


namespace Main 
{
    class GameService 
    {
    private:
        Global::ServiceLocator& serviceLocator;
        bool running;
        Board::BoardService* boardService;
        Input::InputService* inputService;

    public:
        GameService(Global::ServiceLocator& serviceLocator);
        ~GameService();

        void StartTheGame();
        void Update();
        bool IsRunning();
    };
}







