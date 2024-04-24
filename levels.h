#pragma once
#include "player.h"

namespace Tmpl8
{
	class Level
	{
	public:
		void ReadLevel(int levelIndex);
		void DrawLevel(Surface* gameScreen);
		Player player;
		bool CheckTile(int x, int y) { return canWalk; };
	private:
		bool canWalk;
	};

}
