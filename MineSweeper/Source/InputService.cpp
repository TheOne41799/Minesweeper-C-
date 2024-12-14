#include "../Header/InputService.h"


namespace Input 
{
    void InputService::GetInput(int& row, int& col, char& action) 
    {
        cout << "Enter row and column (0-8 0-8): " << endl;
        cin >> row >> col;
        cout << "Enter action (r - reveal, f - flag): ";
        cin >> action;
    }
}

