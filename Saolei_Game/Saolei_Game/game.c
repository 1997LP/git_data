#include "game.h"

char show_thunder[ROW][COL];
char base_thunder[ROW][COL];

void Board_init()
{
	int i = 0;
	system("title 扫雷游戏");//设置标题
	system("mode con cols=24 lines=12");//控制窗口大小
	printf("******************\n\n");
	printf("*****扫雷游戏*****\n\n");
	printf("******************\n\n");
	while (1)
	{
		printf("***（1）开始游戏**\n\n");
		printf("***（2）退出游戏**\n\n");
		printf("请选择：\n");
		scanf("%d", &i);
		if (i == 1)
		{
			srand((unsigned int)time(NULL));
			Play_game();
		}
		else if (i==2)
		{
			exit(0);
		}
		
	}
	
}
void Play_game()
{
	Thunder_init(show_thunder, ROW, COL, '*');
	Thunder_init(base_thunder, ROW, COL, '0');
	Thunder_Design(base_thunder);
	Show_buf(show_thunder, ROW_R,COL_R);
	Show_buf(base_thunder, ROW_R, COL_R);
	Thunder_find(base_thunder);//排雷
}


void Thunder_init(char buf[][COL],int row, int col,char data)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
		for (j=0;j<col;j++)
		{
			buf[i][j] = data;
		}
}

void Thunder_Design(char buf[][COL])
{
	int x = 0;
	int y = 0;
	for (int i=0;i< THUNDER_NUM;)
	{
		x = rand() % ROW_R + 1;
		y = rand() % COL_R + 1;
		if (buf[x][y]!= '1')
		{
			buf[x][y] = '1';
			i++;
		}
	}
}

void Show_buf(char buf[][COL],int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0;i<= COL_R;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", buf[i][j]);
		}
		printf("\n");
	}
}

void To_Dis(char buf[][COL], int x , int y)
{
	char num = 0;
	for (int i=x-1;i<(x+2);i++)
	{
		for (int j=y-1;j<(y+2);j++)
		{
			num += buf[i][j] - '0';
		}
	}
	show_thunder[x][y] = num + '0';

	Show_buf(show_thunder, ROW_R, COL_R);
}
void Thunder_find(char buf[][ROW] )
{
	int num = ROW_R* COL_R-THUNDER_NUM;
	int x = 0;
	int y = 0;

	while (num!=0)
	{
		printf("请输入排雷位置： ");
		scanf("%d%d",&x,&y);
		if (x>0 && x<=ROW_R && y>0 && y <=COL_R)
		{
			if (buf[x][y] == '1')
			{
				printf("你踩到雷了，游戏结束！！！\n");
				break;
			}
			else   //没有踩到雷，更新显示
			{
				To_Dis(base_thunder,x,y);
				num--;
			}
		}
		else
		{
			printf("不在雷区范围，请重新输入\n");
		}
	}
	if (num==0)
	{
		printf("恭喜你，通过挑战！！！\n");
	}
}