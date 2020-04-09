
#include "game.h"
int main()
{
	MOUSEMSG mouse;
	Graph_init();
	while (1)
	{
		while (1)
		{
			mouse = GetMouseMsg();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				if (mouse.x >= 560 && mouse.x <= 620 && mouse.y >= 325 && mouse.y <= 360)
				{
					Graph_init();
					MessageBox(NULL, "游戏开始", "开始", MB_OK);
					
					break;
				}
			}
		}
		play_game();
	}

}
