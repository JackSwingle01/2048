#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printGrid(int grid[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j];
            cout << " ";
        }
    }
}

void moveRight(int grid[4][4])
{
    for (int n = 0; n < 3; n++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 2; j >= 0; j--)
            {
                if (grid[i][j] != 0 && grid[i][j + 1] == 0) // check if empty space is to the right
                {
                    grid[i][j + 1] = grid[i][j];
                    grid[i][j] = 0;
                }
            }
        }
    } // initial shift

    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            if (grid[i][j + 1] == grid[i][j])
            {
                grid[i][j + 1] += grid[i][j];
                grid[i][j] = 0;
            }
        }
    } // merge

    for (int i = 0; i < 4; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            if (grid[i][j] != 0 && grid[i][j + 1] == 0) // check if empty space is to the right
            {
                grid[i][j + 1] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    } // final shift
}

void moveLeft(int grid[4][4])
{
    for (int n = 0; n < 3; n++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                if (grid[i][j] != 0 && grid[i][j - 1] == 0)
                {
                    grid[i][j - 1] = grid[i][j];
                    grid[i][j] = 0;
                }
            }
        }
    } // initial shift

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (grid[i][j - 1] == grid[i][j])
            {
                grid[i][j - 1] += grid[i][j];
                grid[i][j] = 0;
            }
        }
    } // merge

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (grid[i][j] != 0 && grid[i][j - 1] == 0)
            {
                grid[i][j - 1] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    } // final shift
}

void moveUp(int grid[4][4])
{
    for (int n = 0; n < 3; n++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 1; i < 4; i++)
            {
                if (grid[i][j] != 0 && grid[i - 1][j] == 0)
                {
                    grid[i - 1][j] = grid[i][j];
                    grid[i][j] = 0;
                }
            }
        }
    } // initial shift into empty spaces

    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i < 4; i++)
        {
            if (grid[i - 1][j] == grid[i][j])
            {
                grid[i - 1][j] += grid[i][j];
                grid[i][j] = 0;
            }
        }
    } // merge equal numbers

    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i < 4; i++)
        {
            if (grid[i][j] != 0 && grid[i - 1][j] == 0)
            {
                grid[i - 1][j] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
    // final shift into empty spaces
}

void moveDown(int grid[4][4])
{
    for (int n = 0; n < 3; n++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 2; i >= 0; i--)
            {
                if (grid[i][j] != 0 && grid[i + 1][j] == 0)
                {
                    grid[i + 1][j] = grid[i][j];
                    grid[i][j] = 0;
                }
            }
        }
    } // initial shift into empty spaces

    for (int j = 0; j < 4; j++)
    {
        for (int i = 2; i >= 0; i--)
        {
            if (grid[i + 1][j] == grid[i][j])
            {
                grid[i + 1][j] += grid[i][j];
                grid[i][j] = 0;
            }
        }
    } // merge equal numbers

    for (int j = 0; j < 4; j++)
    {
        for (int i = 2; i >= 0; i--)
        {
            if (grid[i][j] != 0 && grid[i + 1][j] == 0)
            {
                grid[i + 1][j] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
    // final shift into empty spaces
}

void readStartState(int grid[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> grid[i][j];
        }
    } // get input
}

int main(void)
{
    char direction = ' ';
    int grid[4][4];
    int x,y;

    srand(time(0)); //seed random number function

    readStartState(grid); // read start grid

    while (direction != 'q')
    {
        cin >> direction; // read direction

        if (direction == 'a') // left
        {
            moveLeft(grid);
        }
        else if (direction == 'w') // up
        {
            moveUp(grid);
        }
        else if (direction == 'd') // right
        {
            moveRight(grid);
        }
        else if (direction == 's') // down
        {
            moveDown(grid);
        }

        x = rand() % 4;
        y = rand() % 4;
        if (grid[y][x] == 0) 
        {
            grid[y][x] = ((rand() % 2) + 1) * 2; 
        }

        printGrid(grid); // print output
    }
}
