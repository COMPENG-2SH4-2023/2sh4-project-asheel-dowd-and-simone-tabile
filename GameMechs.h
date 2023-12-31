#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        objPos foodPos;
        
        int boardSizeX;
        int boardSizeY;
        int score;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        void setLoseFlag();
        void setExitTrue();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();
        int getscore();
        void incrementScore();

        void generateFood(objPosArrayList* blockOff);
        void getFoodPos(objPos &returnPos);
      

};

#endif