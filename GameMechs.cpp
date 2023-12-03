#include "GameMechs.h"

GameMechs::GameMechs() //main constructor
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

GameMechs::GameMechs(int boardX, int boardY) //custom constructor
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



bool GameMechs::getExitFlagStatus() //exit flag getter
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() //lose flag getter
{
    return loseFlag;
}

char GameMechs::getInput() // keyboard input getter 
{
    return input;
}

int GameMechs::getBoardSizeX() //x border getter
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() //y border getter
{
    return boardSizeY;
}


void GameMechs::setExitTrue() //exit flag setter
{
    exitFlag = true;
}

void GameMechs::setLoseFlag() //lose flag setter
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input) //input setter
{
    input = this_input;
}

void GameMechs::clearInput() //input setter
{
    input = 0;
}

int GameMechs::getscore() //score getter
{
    return score;
}

void GameMechs::incrementScore() //score increment
{
    score++;
}

void GameMechs::generateFood(objPosArrayList* blockOff) //generateFood function using ppa3 logic and iteration 3 alterations (pass by pointer)
{
    int check;
    int randX;
    int randY;

    objPos tempPos;

    tempPos = objPos();

    check = 0;
    while(!check)
    {
        check = 1;
        randX = rand() % (getBoardSizeX()-2)+1;
        randY = rand() % (getBoardSizeY()-2)+1;

        for(int i=0; i < blockOff->getSize(); i++)
        {
            blockOff->getElement(tempPos, i);
            {
                if((randX == tempPos.x) && (randY == tempPos.y))
                {
                    check = 0;
                    break;
                }
                else
                {
                    check = 1;
                }
            }
        }
    }

    foodPos.x = randX;
    foodPos.y = randY;
}

void GameMechs::getFoodPos(objPos &returnPos) //food position getter (pass by reference)
{
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;
}

