#include <stdio.h>
#include <stdlib.h>


//********** 2020_3_22 *************** 
//�۰�����㷨���ҵ���С��������������ָ��Ԫ���±�
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
			printf("�ҵ���,�±��ǣ�%d\n",middle);
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

**********дһ��������Ϸ***********
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
	printf("������֣�\n");
	while (1)
	{
		scanf("%d",&guess);
		if (guess>number)
		{
			printf("�´���\n");
		}
		else if (guess < number)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�����������\n");
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
		printf("��ѡ��\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("������Ϸ\n");
			Game();
			break;



		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
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









