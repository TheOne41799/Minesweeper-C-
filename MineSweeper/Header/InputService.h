#pragma once


namespace InputService
{
	class InputService
	{
	public:
		InputService() = default;
		~InputService() = default;

		virtual void GetFirstMove(int& x, int& y) = 0;
		virtual void GetPlayerInput(int& action, int& x, int& y) = 0;
	};
}
