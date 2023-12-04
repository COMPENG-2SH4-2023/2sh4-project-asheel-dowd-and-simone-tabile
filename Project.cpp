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

    while(gm->getExitFlagStatus() == false) //check exit flag condition and if false, then continue
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

    exitFlag = false; //set exitflag to false

    gm = new GameMechs(30, 15); //initialize gm

    player = new Player(gm); //initialize player

    srand(time(NULL)); //seed time

    objPosArrayList* playerPos; //set up player position list

    playerPos = player->getPlayerPos();

    gm->generateFood(playerPos);
}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        gm->setInput(MacUILib_getChar()); //use setter and MacUI function to get keyboard input
    }
}

void RunLogic(void)
{
    //movement logic
    player->updatePlayerDir();
    player->movePlayer();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPosArrayList* playerPos = player->getPlayerPos(); //initialize playPos list again
    //set up temps for pass by reference getters
    objPos temp2; //food temp
    objPos temp1; //player temp
    temp2 = objPos();
    temp1 = objPos();
    gm -> getFoodPos(temp2);
    bool isPrinted; ///check if food or player is printed
    for(int i = 0; i < gm->getBoardSizeY(); i++)
    {
        for(int j = 0; j < gm->getBoardSizeX(); j++)
        {
            if(i == 0 || i == 14 || j == 0 || j == 29) //border print conditions
            {
                MacUILib_printf("#");
            }    
            else
            {
                isPrinted = false;

                if ((temp2.x == j) && (temp2.y == i)) //food print conditions
                {
                    MacUILib_printf("%c", temp2.getSymbol());
                    isPrinted = true;
                }            

                for(int k = 0; k < playerPos->getSize() && !isPrinted; k++) //character print loop and if statement 
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

    MacUILib_printf("your score is %d", gm->getscore()); //score displayer

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if(gm->getLoseFlagStatus() == true) //suicide/lose message
    {
        MacUILib_printf("haha you lost");
        MacUILib_printf("\n");
        MacUILib_printf("your score was %d", gm->getscore());

    }
    MacUILib_uninit();
}
