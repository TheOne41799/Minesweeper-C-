#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


namespace Board 
{
    enum Cell { COVERED, REVEALED, FLAGGED };

    struct GridCell 
    {
        int value;
        Cell state;
    };

    class BoardService 
    {

    private:
        bool InBounds(int row, int col);

    public:
        BoardService();
        ~BoardService();

        void InitializeGrid(int firstRow, int firstCol);
        void UpdateAdjacentCells(int firstRow, int firstCol);

        void DisplayGrid(bool revealAll = false);
        void Reveal(int row, int col);

        bool MakeMove(int row, int col, char action);
        bool CheckWin();

        GridCell grid[9][9];
    };
}



