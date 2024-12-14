#include "../Header/GameService.h"
#include <iostream>
using namespace std;


namespace Main 
{
    GameService::GameService(Global::ServiceLocator& serviceLocator)
        : serviceLocator(serviceLocator), running(true) 
    {
        boardService = serviceLocator.GetBoardService();
        inputService = serviceLocator.GetInputService();
    }

    GameService::~GameService() = default;

    void GameService::StartTheGame() 
    {
        for (int i = 0; i < 69; i++) {
            cout << "-";
        }
        cout << endl;
        cout << "|                                                                   |\n";
        cout << "|                   WELCOME TO MINESWEEPER GAME                     |\n";
        cout << "|                                                                   |\n";
        for (int i = 0; i < 69; i++) {
            cout << "-";
        }

        cout << endl;

        cout <<
            " RULES:\n"
            "1. The board is divided into cells, with mines distributed.\n"
            "2. To win, you need to open all the cells.\n"
            "3. The number on a cell shows the no of mines adjacent to it.Using this you can determine cells that are safe,"
            "and cell that contains mines"
            "4. Interact, evolve and enjoy\n\n"
            " How to Play :\n"
            "1. user will input x & y(coordinates where they want to click).\n"
            "2. In each step check win or lose case.\n";

        cout << endl << endl;

        cout << "This is the first input before placing the mines" << endl;
        int firstRow, firstCol;
        char firstAction;
        inputService->GetInput(firstRow, firstCol, firstAction);

        boardService->InitializeGrid(firstRow, firstCol);

        boardService->Reveal(firstRow, firstCol);

        cout << endl;

        cout << "Starting the game........." << endl;

        boardService->DisplayGrid();
    }

    void GameService::Update() 
    {
        int row, col;
        char action;
        inputService->GetInput(row, col, action);

        if (row < 0 || row >= 9 || col < 0 || col >= 9) {
            std::cout << "Invalid coordinates.\n";
            return;
        }

        bool gameOver = boardService->MakeMove(row, col, action);

        boardService->DisplayGrid();

        if (gameOver) {
            boardService->DisplayGrid(true);
            running = false;
            return;
        }

        if (boardService->CheckWin()) 
        {
            std::cout << "Congratulations! You've won the game!\n";
            boardService->DisplayGrid(true);
            running = false;
        }
    }

    bool GameService::IsRunning() 
    {
        return running;
    }
}
