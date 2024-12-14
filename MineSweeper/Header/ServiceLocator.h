#pragma once
#include "InputService.h"
#include "BoardService.h"


namespace Global
{
    class ServiceLocator 
    {
    private:
        Input::InputService* inputService;
        Board::BoardService* boardService;

    public:
        ServiceLocator();
        ~ServiceLocator();

        void CreateServices();
        void DestroyServices();
        static ServiceLocator* GetInstance();

        Input::InputService* GetInputService() { return inputService; }
        Board::BoardService* GetBoardService() { return boardService; }
    };
}
