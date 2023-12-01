#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    foodPos.x = 0;
    foodPos.y = 0;
    foodPos.symbol = 'f';
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    foodPos.x = 0;
    foodPos.y = 0;
    foodPos.symbol = 'f';
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getscore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

void GameMechs::generateFood(objPos blockOff)
{
    int check;
    int randX;
    int randY;

    check = 0;
    while(!check)
    {
        check = 1;
        randX = rand() % (getBoardSizeX()-2)+1;
        randY = rand() % (getBoardSizeY()-2)+1;
        if((randX != blockOff.x) && (randY != blockOff.y))
        {
            check = 1;
        }
        else
        {
            check = 0;
        }
    }

    foodPos.x = randX;
    foodPos.y = randY;
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;
}

