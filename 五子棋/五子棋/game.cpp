#include "game.h"

char buf[21][21] = { 0 };
IMAGE SUCCESS;
void Graph_init()
{
	IMAGE img;
	initgraph(750, 550);
	loadimage(&img,     "view.jfif", 750, 550); //�Ȱ�ͼƬ���ڹ�����Ŀ�£�ʹ��L+"����·��"
	loadimage(&SUCCESS, "success.jfif", 50, 50);
	putimage(0, 0, &img);//��ʾͼƬ
	setlinecolor(BLACK);
	for (int i = 25; i <= 525; i += 25)
	{
		line(i,25,i,525);//������
		line(25,i,525,i);//������
	}

	line(24, 25, 24,  525) ;
	line(526, 25, 526,525) ;
	line(25, 24, 525, 24)  ;
	line(25, 526, 525, 526);

	settextstyle(27,0,0);//����߶ȣ���ȣ�0Ϊ����Ӧ����������
	outtextxy(560,100, "���һ����ɫ");
	outtextxy(560,200, "��Ҷ�����ɫ");
	
	settextstyle(30, 0, 0);//����߶ȣ���ȣ�0Ϊ����Ӧ����������
	outtextxy(560, 325, "��ʼ");

	mciSendString("open music.mp3",0,0,0);		//������
	mciSendString("play music.mp3", 0, 0, 0);   //������


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
		if (mouse.uMsg == WM_LBUTTONDOWN)//�ж��������Ƿ���
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
					if (flag % 2 == 0) //��������˸�������
					{
						setfillcolor(BLACK);
						solidcircle(x, y, 10);
						buf[j - 1][i - 1] = 1;
						if (Success(j - 1, i - 1,1)==1)
						{
							printf("\a\a\a");
							putimage(580, 130, &SUCCESS);//��ʾͼƬ
							return;
						}
						flag++;
					}
					else			   //��������˸�������
					{
						setfillcolor(WHITE);
						solidcircle(x, y, 10);
						buf[j - 1][i - 1] = 2;
						if (Success(j - 1, i - 1,2)==2)
						{
							printf("\a\a\a");
							putimage(580, 230, &SUCCESS);//��ʾͼƬ
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

//�������ܣ��ж�����Ƿ�ʤ��
//��ڲ�����������±꣬�� �� , ���ӵ�����1����ɫ�� 2����ɫ

int Success(int x,int y ,int num)
{
	int ret = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < 5; i++)//�ж��з���
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
	
	for (i = 0; i < 5; i++)//�ж��з���
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

	
	for (i = 0; i < 5; i++)//�ж�б���ϵķ���
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

	for (i = 0; i < 5; i++)//�ж�б���ϵķ���
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

