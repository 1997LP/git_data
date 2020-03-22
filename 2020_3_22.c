#include <stdio.h>
#include <stdlib.h>


//********** 2020_3_22 *************** 
//折半查找算法，找到从小到大排列数组中指定元素下标
int Search(int *p,int length,int num)
{
	int left = 0;
	int right = length-1;
	int middle = (left+right)/2;
	while (left!=right)
	{
		if (p[middle] > num)
		{
			right = middle - 1;
			middle = (left + right) / 2;
		}
		if (p[middle] < num)
		{
			left = middle + 1;
			middle = (left + right) / 2;
		}
		if(p[middle] == num)
		{
			printf("找到了,下标是：%d\n",middle);
			return middle;
		}

	}
	return -1;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	Search(arr,10,7);
}

**********写一个猜谜游戏***********
**********2020_3_22****************
void Menu()
{
	printf("***********************\n");
	printf("*** 1.play    2.exit***\n");
	printf("***********************\n");
}
void Game()
{
	int guess;
	int number;
	number = rand()%100+1;
	printf("请猜数字：\n");
	while (1)
	{
		scanf("%d",&guess);
		if (guess>number)
		{
			printf("猜大了\n");
		}
		else if (guess < number)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了！！！！！！\n");
			return;
		}
	}
}
int main()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("请选择：\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("猜谜游戏\n");
			Game();
			break;



		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}


int main(void)
{
	int    i = 10;
	double fp = 1.5;
	char   s[] = "this is a string";
	char   c = '\n';
	FILE *stream;
	stream = fopen("fprintf.out", "a");
	fprintf(stream, "%s%c", s, c);
	fprintf(stream, "%d\n", i);
	fprintf(stream, "%f\n", fp);
	fclose(stream);
	system("type fprintf.out");
}









