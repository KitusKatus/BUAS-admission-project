#include "surface.h"
#include "windows.h"
#include "levels.h"
#include "game.h"
#include "player.h"
#include <algorithm>
#include <iterator>
#include <cstdio>

namespace Tmpl8
{
	Player playerStart;
	char currentLevel[18][96];
	Surface tiles("assets/tiles.png");

	void DrawTile(int tx, int ty, Surface* screen, int x, int y) //code from tutorials
	{
		Pixel* src = tiles.GetBuffer() + 1 + tx * 61 + (1 + ty * 61) * tiles.GetWidth(); //+1 and 61 to avoid borders, 60 = tile size
		Pixel* dst = screen->GetBuffer() + x + y * screen->GetWidth();
		for (int i = 0; i < 60; i++, src += tiles.GetWidth(), dst += screen->GetWidth())
			for (int j = 0; j < 60; j++)
				dst[j] = src[j];
	}

	void CopyLevel(char map[18][96])
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				currentLevel[i][j] = map[i][j];
			}
		}
	}

	void Level::ReadLevel(int levelIndex)
	{
		switch (levelIndex)
		{
		case 0:

			bool startLimb[6] = { true, true, true, true, true, true };

			playerStart.SpawnPlayer(100, 100, startLimb);
			
			char map[18][96] = {
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			};

			CopyLevel(map);
			

		}
	};

	void Level::DrawLevel(Surface* gameScreen)
	{
		for (int yl = 0; yl < 6; yl++)
			for (int xl = 0; xl < 7; xl++)
			{
				int tx = currentLevel[yl][xl * 3] - 'a';
				int ty = currentLevel[yl][xl * 3 + 1] - 'a'; //+1 to get second character
				DrawTile(tx, ty, gameScreen, xl * 60, yl * 60); //*60 because tile is 60 pixels
			}

	}

}