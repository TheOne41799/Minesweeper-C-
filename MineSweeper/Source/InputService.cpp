#include "../Header/InputService.h"
#include <iostream>


namespace InputService
{
	void InputService::GetFirstMove(int& x, int& y)
	{
		std::cout << "Enter your first move (x y): ";
		std::cin >> x >> y;
	}


	void InputService::GetPlayerInput(int& action, int& x, int& y) 
	{
		std::cout << "\nEnter your next move (1 for reveal, 2 for flag), followed by (x y): ";
		std::cin >> action >> x >> y;
	}
}

