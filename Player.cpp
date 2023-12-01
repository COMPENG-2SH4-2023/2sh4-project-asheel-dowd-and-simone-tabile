#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    objPos newPos;
    newPos = objPos(15, 7, '*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(newPos);
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
    delete playerPosList;
}

void Player::getPlayerPos(objPosArrayList* returnPos)
{
    // return the reference to the playerPos arrray list
    // returnPos.x = playerPos.x;
    // returnPos.y = playerPos.y;
    // returnPos.symbol = playerPos.symbol;

    returnPos = playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic        
    if(mainGameMechsRef->getInput() != 0)  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {                      
            case '.':  // exit
                mainGameMechsRef->setExitTrue();
                break;

            case 'w':
                if(myDir != DOWN)
                {
                    myDir = UP;
                }
                break;
        
            case 'a':
                if(myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;
            case 's':
                if(myDir != UP)
                {
                    myDir= DOWN;
                }
                break;
            case 'd':
                if(myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;
        }
        mainGameMechsRef->setInput(0);
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos movePos;
    movePos = objPos();

    switch(myDir)
    {
        case(UP):
            if(movePos.y == 1 && myDir == UP)
            {
                movePos.y = 13;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            else
            {
                movePos.y--;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            break;

        case(DOWN):
            if(movePos.y == 13 && myDir == DOWN)
            {
                movePos.y = 1;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            else
            {
                movePos.y++;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            break;

        case(RIGHT):
            if(movePos.x == 28 && myDir == RIGHT)
            {
                movePos.x = 1;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            else
            {
                movePos.x++;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            break;
        
        case(LEFT):
            if(movePos.x == 1 && myDir == LEFT)
            {
                movePos.x = 28;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            else
            {
                movePos.x--;
                playerPosList->insertHead(movePos);
                playerPosList->removeTail();
            }
            break;
        default:
            break;

    }
}

