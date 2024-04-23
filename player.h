#pragma once
#include "game.h"

namespace Tmpl8
{
	extern int partIndex;

	class Player
	{
	public:
		Player()
		{
			part[0].active = true;
			//part[0].x, part[0].y = 0;
			part[0].type = 0;
			part[1].type, part[2].type = 1;
			part[3].type, part[4].type = 2;
			part[5].type = 3;
		};

		void Move(float dx, float dy);
		void DetachPart(int detachIndex);
		void AttachPart(int attachIndex);
		void DrawPlayer(Surface* gameScreen);
		void ControlPart(int sx, int sy, int key);
		void SpawnPlayer(int x, int y, bool startLimb[6]);

		struct partData {
			bool active;
			int x, y;
			int type; // 0 = body, 1 = leg, 2 = arm, 3 = head
			char inventory;
		};
		partData part[10];
		bool hasLimb[6];

	};

}
