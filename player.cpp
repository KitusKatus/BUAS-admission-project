#include "surface.h"
#include "windows.h"
#include "player.h"
#include <cstdio>
#include <cmath>;

namespace Tmpl8
{
    bool hasLimb[6];
    int partIndex = 0;
    Sprite tank(new Surface("assets/ctankbase.tga"), 16);
    Game game;


    void Player::SpawnPlayer(int sx, int sy, bool startLimb[6])
    {
        part[0].x = sx; part[0].y = sy;
        for (int i = 0; i < 6; i++)
        {
            hasLimb[i] = startLimb[i];
        }
    }

    void Player::Move(int dx, int dy)
    {
        part[partIndex].x += dx; part[partIndex].y += dy;
    }

    void Player::DetachPart(int detachIndex)
    {
        hasLimb[detachIndex] = false; //for type of limb
        part[detachIndex].x = part[0].x; part[detachIndex].y = part[0].y;
        part[detachIndex].active = true;
        partIndex = detachIndex;
    }

    void Player::AttachPart(int attachIndex)
    {
        hasLimb[attachIndex] = true; //for type of limb
        part[attachIndex].active = false;
        partIndex = 0;
    }

    void Player::DrawPlayer(Surface* gameScreen)
    {
        for (int i = 0; i < 10; i++)
        {
            if (part[i].active)
            {
                tank.Draw(gameScreen, part[i].x - 20, part[i].y - 20);
            }
        }
    }

    void Player::ControlPart(int sx, int sy, int key)
    {

        switch (part[partIndex].type)
        {
        case 0: //torso

            if (hasLimb[1] || hasLimb[2] || hasLimb[3] || hasLimb[4])
            {
                Move(sx, sy);
            }

            if (key == 30 && hasLimb[1]) { DetachPart(1); }
            if (key == 31 && hasLimb[2]) { DetachPart(2); }
            if (key == 32 && hasLimb[3]) { DetachPart(3); }
            if (key == 33 && hasLimb[4]) { DetachPart(4); }
            if (key == 34 && hasLimb[5]) { DetachPart(5); }
            break;

        case 1: // leg
            Move(sx, sy);
            break;
        case 2: //arm
            Move(sx, sy);
            break;
        case 3: //head
            Move(sx, sy);
            break;

        }

        if (key == 44 && partIndex != 0) //attach part by hitting space
        {
            int partDistance = sqrt(pow(part[partIndex].x - part[0].x, 2) + pow(part[partIndex].y - part[0].y, 2)); 
            if (partDistance <= 15)
            {
                AttachPart(partIndex);
            }
        }


    }
};