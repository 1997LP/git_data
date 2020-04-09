#include "game.h"

char buf[21][21] = { 0 };
IMAGE SUCCESS;
void Graph_init()
{
	IMAGE img;
	initgraph(750, 550);
	loadimage(&img,     "view.jfif", 750, 550); //先把图片放在工程项目下，使用L+"绝对路径"
	loadimage(&SUCCESS, "success.jfif", 50, 50);
	putimage(0, 0, &img);//显示图片
	setlinecolor(BLACK);
	for (int i = 25; i <= 525; i += 25)
	{
		line(i,25,i,525);//画列线
		line(25,i,525,i);//画列线
	}

	line(24, 25, 24,  525) ;
	line(526, 25, 526,525) ;
	line(25, 24, 525, 24)  ;
	line(25, 526, 525, 526);

	settextstyle(27,0,0);//字体高度，宽度：0为自适应，字体名称
	outtextxy(560,100, "玩家一：黑色");
	outtextxy(560,200, "玩家二：白色");
	
	settextstyle(30, 0, 0);//字体高度，宽度：0为自适应，字体名称
	outtextxy(560, 325, "开始");

	mciSendString("open music.mp3",0,0,0);		//打开音乐
	mciSendString("play music.mp3", 0, 0, 0);   //打开音乐


}

void play_game()
{
	int flag = 0;
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	MOUSEMSG mouse;
	
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			buf[i][j] = 0;
		}
	}

	while (1)
	{
		mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN)//判断鼠标左键是否按下
		{
			for (i=1;i<22;i++)
			{
				for ( j=1;j<22;j++)
				{
					if (abs(mouse.x-i*25)<12 && abs(mouse.y - j * 25) < 12)
					{
						x = i * 25;
						y = j * 25;
						goto Go;
					}
				}
			}
		Go:
			switch (buf[j - 1][i - 1])
			{
				case 0:
					if (flag % 2 == 0) //先下棋的人该下棋了
					{
						setfillcolor(BLACK);
						solidcircle(x, y, 10);
						buf[j - 1][i - 1] = 1;
						if (Success(j - 1, i - 1,1)==1)
						{
							printf("\a\a\a");
							putimage(580, 130, &SUCCESS);//显示图片
							return;
						}
						flag++;
					}
					else			   //后下棋的人该下棋了
					{
						setfillcolor(WHITE);
						solidcircle(x, y, 10);
						buf[j - 1][i - 1] = 2;
						if (Success(j - 1, i - 1,2)==2)
						{
							printf("\a\a\a");
							putimage(580, 230, &SUCCESS);//显示图片
							return;
						}
						flag++;
					}
					break;
				case 1:printf("\a\a\a\a\a"); 
					break;
				
				case 2:printf("\a\a\a\a\a"); 
					break;
				
				default:
					break;
			}
		}
	}
}

//函数功能：判断玩家是否胜利
//入口参数：数组的下标，行 列 , 棋子的种类1：黑色； 2：白色

int Success(int x,int y ,int num)
{
	int ret = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < 5; i++)//判断列方向
	{
		ret = 0;
		for ( j = 0; j < 5; j++)
		{
			if (!buf[x - i + j][y] || buf[x - i + j][y] != num)
				break;
			ret += buf[x - i + j][y];
		}
		if (ret == 5 )
			return 1;
		if (ret == 10)
			return 2;
	}
	
	for (i = 0; i < 5; i++)//判断行方向
	{
		ret = 0;
		for (j = 0; j < 5; j++)
		{
			if (!buf[x][y - i + j] || buf[x][y - i + j]!=num)
				break;
			ret += buf[x][y - i + j];
		}
		if (ret == 5)
			return 1;
		if (ret == 10)
			return 2;
	}

	
	for (i = 0; i < 5; i++)//判断斜右上的方向
	{
		ret = 0;
		for (j = 0; j < 5; j++)
		{
			if (!buf[x - i - j][y - i + j] || buf[x - i - j][y - i + j] != num)
				break;
			ret += buf[x - i - j][y - i + j];
		}
		if (ret == 5)
			return 1;
		if (ret == 10)
			return 2;
	}

	for (i = 0; i < 5; i++)//判断斜左上的方向
	{
		ret = 0;
		for (j = 0; j < 5; j++)
		{
			if (!buf[x - i + j][y - i + j] || buf[x - i + j][y - i + j] != num)
				break;
			ret += buf[x - i + j][y - i + j];
		}
		if (ret == 5)
			return 1;
		if (ret == 10)
			return 2;
	}

	return 0;
}

