#include <iostream>
#include "Header/GameService.h"
using namespace std;


int main()
{
    Main::GameService* gameService = new Main::GameService(*Global::ServiceLocator::GetInstance());
    
    gameService->StartTheGame();

    while (gameService->IsRunning()) 
    {
        gameService->Update();
    }

    delete gameService;

	return 0;
}

