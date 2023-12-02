#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include <time.h>

GameMechs *gm; 
Player *player;

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(gm->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();


}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;

    gm = new GameMechs(30, 15);

    player = new Player(gm);

    srand(time(NULL));

    objPosArrayList* playerPos;

    playerPos = player->getPlayerPos();

    gm->generateFood(playerPos);
}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        gm->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPosArrayList* playerPos = player->getPlayerPos();
    objPos temp2; //food temp
    objPos temp1; //player temp
    temp2 = objPos();
    temp1 = objPos();
    gm -> getFoodPos(temp2);
    bool isPrinted;
    for(int i = 0; i < gm->getBoardSizeY(); i++)
    {
        for(int j = 0; j < gm->getBoardSizeX(); j++)
        {
            if(i == 0 || i == 14 || j == 0 || j == 29)
            {
                MacUILib_printf("#");
            }    
            else
            {
                isPrinted = false;

                if ((temp2.x == j) && (temp2.y == i) && !isPrinted
                ) 
                {
                    MacUILib_printf("%c", temp2.getSymbol());
                    isPrinted = true;
                }            

                for(int k = 0; k < playerPos->getSize() && !isPrinted; k++)
                {
                    playerPos->getElement(temp1, k);
                    if(temp1.x == j && temp1.y == i)
                    {
                        MacUILib_printf("%c", temp1.getSymbol());
                        isPrinted = true;
                    }
                }

                if (!isPrinted)
                    MacUILib_printf(" ");
            }    
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("your score is %d", gm->getscore());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if(gm->getLoseFlagStatus() == true)
    {
        MacUILib_printf("haha you lost");
        MacUILib_printf("\n");
        MacUILib_printf("your score was %d", gm->getscore());

    }
  
    MacUILib_uninit();
}
