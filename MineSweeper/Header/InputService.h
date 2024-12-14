#pragma once
#include <iostream>
using namespace std;


namespace Input 
{
    class InputService 
    {
    public:
        InputService() = default;
        ~InputService() = default;

        void GetInput(int& row, int& col, char& action);
    };
}








