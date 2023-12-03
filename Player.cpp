#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"


Player::Player(GameMechs* thisGMRef) //main constructor with iteration 3 implementation
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    objPos newPos;
    newPos = objPos(15, 7, 'O');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(newPos);
}


Player::~Player() //destructor
{
    // delete any heap members here
    delete mainGameMechsRef;
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() //position getter
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
    objPos tempfoodpos;
    objPos tempcheck;

    playerPosList->getHeadElement(currHead);
    mainGameMechsRef->getFoodPos(tempfoodpos);

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

    if((tempfoodpos.x == currHead.x) && (tempfoodpos.y == currHead.y))//adding sneak head when on food
    {
        playerPosList->insertHead(currHead);
        mainGameMechsRef->generateFood(playerPosList);
        if(playerPosList->getSize() > 1)
        {
            mainGameMechsRef->incrementScore();
        }
    }

    
    else//general movement scheme
    {
        playerPosList->insertHead(currHead);
        playerPosList->removeTail();
    }

    for(int i=1; i < playerPosList->getSize(); i++) //suicide check
    {
        playerPosList->getElement(tempcheck, i);
        if((currHead.x == tempcheck.x) && (currHead.y == tempcheck.y) && (playerPosList->getSize() > 2))
        {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
    }
    
}

