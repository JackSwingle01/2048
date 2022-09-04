#include <bits/stdc++.h>
#include <vector>
using namespace std;

void moveRight(int grid[4][4]) 
{
    for(int n = 0; n < 4; n++){
        for (int i = 0; i < 4; i++){
            for (int j = 2; j >= 0; j--){
                if (grid[i][j] != 0 && grid[i][j + 1] == 0) //check if empty space is to the right
                {
                    grid[i][j + 1] = grid[i][j];
                    grid[i][j] = 0;   
                }
            }
        }
    } //moves all blocks to the right
    
    for (int i = 0; i < 4; i++){
        for (int j = 2; j >= 0; j--){
            if (grid[i][j + 1] == grid[i][j]) 
            {
                grid[i][j + 1] = grid[i][j] * 2;
                grid[i][j] = 0;              
            }
        }
    }
}

void moveLeft(int grid[4][4])
{

}

void moveUp(int grid[4][4])
{

}

void moveDown(int grid[4][4])
{

}

void readStartState(int grid[4][4])
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cin >> grid[i][j];
        }
    } //get input
}

void printGrid(int grid[4][4]){
    for (int i = 0; i < 4; i++){
        cout << "\n";
        for (int j = 0; j < 4; j++){
            cout << grid[i][j];
            cout << " ";
        }
    }
}

int main(void)
{
    int direction;
    int grid[4][4];

    readStartState(grid); //read start grid
    cin >> direction; //read direction

    if (direction == 0) //left
    { 

    }
    else if (direction == 1)//up
    {
     //test  
    }
    else if (direction == 2)//right
    {
        moveRight(grid);
    }
    else if (direction == 3)//down
    {

    }

    printGrid(grid);//print output

}

