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
	char currentLevel[18][96];
	Surface tiles("assets/tiles.png");

	void DrawTile(int tx, int ty, Surface* screen, int x, int y) //code from tutorials
	{
		int screenWidth = screen->GetWidth();
		int screenHeight = screen->GetHeight();

		Pixel* src = tiles.GetBuffer() + 1 + tx * 61 + (1 + ty * 61) * tiles.GetWidth(); //+1 and 61 to avoid borders, 60 = tile size
		Pixel* dst = screen->GetBuffer() + x + y * screenWidth;
		
		for (int i = 0; i < 60; i++, src += tiles.GetWidth(), dst += screenWidth)
			for (int j = 0; j < 60; j++)
				if (dst < screen->GetBuffer() + screenWidth * screenHeight)
					dst[j] = src[j];
	}

	void CopyLevel(char map[14][72])
	{
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 93; j++)
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

			player.SpawnPlayer(100, 100, startLimb);
			
			char map[14][72] = {
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia cc da da dc ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ca aa aa ea db db db db dd ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia bc ba ba ec ab ab ab ab eb ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia cd bh bg bg bg ab ab ab ab eb ia cc da dc ia ia ia",
			"ia ia cd db db db db ab aa aa aa aa ab ab ab ab eb ia ca aa ea ia ia ia",
			"ia ia cb ab ab ab ab ab aa aa aa aa ab ab ab ab eb ia bc ba ec ia ia ia",
			"ia ia cb ab ab ab ab ab aa aa aa aa ab ab ab ab eb ia ja ja ja ia ia ia",
			"ia ia bd bb bb bb bb ab aa aa aa aa ab bb bb bb ed ia ia ia ia ia ia ia",
			"ia ia ib ib ib ib ib bd bb bb bb bb ed ib ib ib ib ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ib ib ib ib ib ib ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			"ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia ia",
			};

			CopyLevel(map);
			

		}
	};

	void Level::DrawLevel(Surface* gameScreen)
	{
		for (int yl = 0; yl < 14; yl++)
			for (int xl = 0; xl < 24; xl++)
			{
				int tx = currentLevel[yl][xl * 3] - 'a';
				int ty = currentLevel[yl][xl * 3 + 1] - 'a'; //+1 to get second character
				DrawTile(tx, ty, gameScreen, xl * 60, yl * 60); //*60 because tile is 60 pixels
			}

	}

}