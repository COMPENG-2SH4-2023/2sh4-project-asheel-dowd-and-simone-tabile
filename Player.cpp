#include "Player.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    playerPos = objPos(15, 7, '*');
    
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.x = playerPos.x;
    returnPos.y = playerPos.y;
    returnPos.symbol = playerPos.symbol;

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

    switch(myDir)
    {
        case(UP):
            if(playerPos.y == 1 && myDir == UP)
            {
                playerPos.y = 13;
            }
            else
            {
                playerPos.y--;
            }
            break;

        case(DOWN):
            if(playerPos.y == 13 && myDir == DOWN)
            {
                playerPos.y = 1;
            }
            else
            {
                playerPos.y++;
            }
            break;

        case(RIGHT):
            if(playerPos.x == 28 && myDir == RIGHT)
            {
                playerPos.x = 1;
            }
            else
            {
                playerPos.x++;
            }
            break;
        
        case(LEFT):
            if(playerPos.x == 1 && myDir == LEFT)
            {
                playerPos.x = 28;
            }
            else
            {
                playerPos.x--;
            }
            break;
        default:
            break;
    }
}

