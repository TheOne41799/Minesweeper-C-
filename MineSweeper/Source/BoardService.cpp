#include "../Header/BoardService.h"


namespace Board 
{
    BoardService::BoardService() = default;

    BoardService::~BoardService() = default;

    void BoardService::InitializeGrid(int firstRow, int firstCol)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                grid[i][j].value = 0;
                grid[i][j].state = COVERED;
            }
        }

        srand(time(0));
        int minesPlaced = 0;
        while (minesPlaced < 10)
        {
            int r = rand() % 9;
            int c = rand() % 9;

            if ((r == firstRow && c == firstCol) || grid[r][c].value == -1) 
            {
                continue;
            }

            grid[r][c].value = -1;
            minesPlaced++;

            for (int dr = -1; dr <= 1; ++dr)
            {
                for (int dc = -1; dc <= 1; ++dc)
                {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < 9 && nc >= 0 && nc < 9 && grid[nr][nc].value != -1)
                    {
                        grid[nr][nc].value++;
                    }
                }
            }
        }

        UpdateAdjacentCells(firstRow, firstCol);
    }

    void BoardService::UpdateAdjacentCells(int firstRow, int firstCol)
    {
        for (int dr = -1; dr <= 1; ++dr)
        {
            for (int dc = -1; dc <= 1; ++dc)
            {
                int nr = firstRow + dr;
                int nc = firstCol + dc;
                if (nr >= 0 && nr < 9 && nc >= 0 && nc < 9 && grid[nr][nc].value != -1)
                {
                    grid[nr][nc].value++;
                }
            }
        }
    }

    void BoardService::DisplayGrid(bool revealAll) 
    {
        std::cout << "  ";
        for (int j = 0; j < 9; ++j)
            std::cout << j << " ";
        std::cout << std::endl;

        for (int i = 0; i < 9; ++i) 
        {
            std::cout << i << " ";
            for (int j = 0; j < 9; ++j) 
            {
                if (grid[i][j].state == COVERED)
                {
                    std::cout << "# ";
                }
                else if (grid[i][j].state == FLAGGED) 
                {
                    std::cout << "F ";
                }
                else if (revealAll || grid[i][j].value == -1) 
                {
                    std::cout << "* ";
                }
                else 
                {
                    std::cout << grid[i][j].value << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    bool BoardService::InBounds(int row, int col) 
    {
        return row >= 0 && row < 9 && col >= 0 && col < 9;
    }

    void BoardService::Reveal(int row, int col) 
    {
        if (!InBounds(row, col) || grid[row][col].state != COVERED)
            return;

        grid[row][col].state = REVEALED;

        if (grid[row][col].value == 0) 
        {
            for (int dr = -1; dr <= 1; ++dr)
            {
                for (int dc = -1; dc <= 1; ++dc) 
                {
                    if (dr == 0 && dc == 0) continue;
                    Reveal(row + dr, col + dc);
                }
            }
        }
    }

    bool BoardService::MakeMove(int row, int col, char action) 
    {
        if (action == 'r') 
        {
            if (grid[row][col].state == FLAGGED) 
            {
                std::cout << "Cell is flagged. Unflag it first.\n";
                return false;
            }

            if (grid[row][col].value == -1) 
            {
                std::cout << "Game Over! You hit a mine.\n";
                return true;
            }
            else 
            {
                Reveal(row, col);
                return false;
            }
        }
        else if (action == 'f') 
        {
            if (grid[row][col].state == COVERED) 
            {
                grid[row][col].state = FLAGGED;
            }
            else if (grid[row][col].state == FLAGGED) 
            {
                grid[row][col].state = COVERED;
            }
            return false;
        }

        return false;
    }

    bool BoardService::CheckWin() 
    {
        for (int i = 0; i < 9; ++i) 
        {
            for (int j = 0; j < 9; ++j) 
            {
                if (grid[i][j].state == COVERED && grid[i][j].value != -1)
                    return false;
            }
        }
        return true; 
    }
}








