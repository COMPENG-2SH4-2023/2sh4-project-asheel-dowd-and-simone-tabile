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

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    // returnPos.x = playerPos.x;
    // returnPos.y = playerPos.y;
    // returnPos.symbol = playerPos.symbol;

    return playerPosList;
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

    objPos currHead;
    playerPosList->getHeadElement(currHead);

    switch(myDir)
    {
        case(UP):
            if(currHead.y == 1 && myDir == UP)
            {
                currHead.y = 13;
                
            }
            else
            {
                currHead.y--;
                
            }
            break;

        case(DOWN):
            if(currHead.y == 13 && myDir == DOWN)
            {
                currHead.y = 1;
                
            }
            else
            {
                currHead.y++;
                
            }
            break;

        case(RIGHT):
            if(currHead.x == 28 && myDir == RIGHT)
            {
                currHead.x = 1;
                
            }
            else
            {
                currHead.x++;
                
            }
            break;
        
        case(LEFT):
            if(currHead.x == 1 && myDir == LEFT)
            {
                currHead.x = 28;
                
            }
            else
            {
                currHead.x--;
                
            }
            break;
        default:
            break;
    }
    playerPosList->insertHead(currHead);
    playerPosList->removeTail();
}

