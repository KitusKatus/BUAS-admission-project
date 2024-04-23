#include "game.h"
#include "surface.h"
#include "windows.h"
#include "player.h"
#include "levels.h"
#include <cstdio>
#include <cmath>;

namespace Tmpl8
{
    //Sprite tank(new Surface("assets/ctankbase.tga"), 16);
    int sx = 0, sy = 0;
    int levelIndex = 0;
    Player player;
    Level level;
    bool hasReadLevel = false;

    void Game::Init() 
    {

    }

    void Game::Shutdown() {}

    void Game::Tick(float deltaTime)
    {
        if (!hasReadLevel)
        {
            level.ReadLevel(0);
            hasReadLevel = true;
        }

        if (GetAsyncKeyState(0x41)) { sx = -1; }
        if (GetAsyncKeyState(0x44)) { sx = 1; }
        if (GetAsyncKeyState(0x57)) { sy = -1; }
        if (GetAsyncKeyState(0x53)) { sy = 1; }
        
        printf("x: %i\n", player.part[0].x);
        printf("y: %i\n", player.part[0].y);
        player.ControlPart(sx, sy, keyDown); //see what part can or can't do
        
        if (mouseDown == 1) //switch parts
        {
            for (int i = 0; i < 10; i++)
            {
                if (player.part[i].active && i != partIndex)
                {
                    int partDistance = sqrt(pow(mousex - player.part[i].x, 2) + pow(mousey - player.part[i].y, 2));
                    //printf("partDistace: %i \n", partDistance);
                    if (partDistance <= 15)
                    {
                        partIndex = i;
                        break;
                    }
                }
            }
        }

        mouseDown = false;
        keyDown = false;
        sx = 0; sy = 0;

        screen->Clear(0);
        level.DrawLevel(screen);
        player.DrawPlayer(screen);
    }
};