#include <stdio.h>
//
//*************************2020_3_26��***************************
//����쳲���������
int Fib(int n) //�ݹ����ʽ���㷨ʱ�临�Ӷ�̫��
{
	if (n==1 || n==2)
	{
		return	1;
	}
	else
	{
		return Fib(n-1) + Fib(n-2);
	}
}

int Fib_2(int n)  //����������������
{
	int a = 1;
	int b = 1;
	int c = 0;
	if (n<=2)
	{
		c = 1;
	}
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	printf("%d\n", Fib_2(6));
}
////�ж�һ�����ǲ�������
bool prime(int num)
{

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}
void print_prime()
{
	for (int i = 100; i <= 200; i++)
	{
		if (prime(i))printf("%d\n", i);
	}
}

void year_test(int num)
{
	if (((num % 4 == 0) && (num % 100 != 0)) || (num % 400 == 0))
	{
		printf("%d������", num);
	}
	else
	{
		printf("%d�ǲ�����", num);
	}
}
void swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}
//����Ļ������˷��ھ���
void Print_(int num)
{
	for (int i = 1; i < num + 1; i++)
	{
		for (int j = i; j < num + 1; j++)
		{
			printf("%2d*%2d = %2d  ", i, j, i*j);
		}
		printf("\n");
	}
}
int Fun(int n)
{
	if (n == 5)
		return 2;
	else
		return 2 * Fun(n + 1);
}

//��ӡһ�����ֵ�ÿһλ
void print_char(int num)
{
	if (num < 9)
	{
		printf("%d ", num);
	}
	else
	{
		print_char(num / 10);
		printf("%d ", num % 10);
	}
}

//��׳�
int mul(int num)
{
	if (num == 1)return 1;
	else
	{
		return num * mul(num - 1);
	}
}

int mul_for(int num)
{
	int ret = num;
	for (int i = num - 1; i > 1; i--)
	{
		ret *= i;
	}
	return ret;
}
int my_strlen(char *p)
{
	int ret = 0;
	while (*p++ != '\0')
	{
		ret++;
	}
	return ret;
}
int my_str_2(char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_str_2(str + 1);
	}
}
//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//
//ʵ�֣��������ַ����е��ַ��������С�
//
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

char *reverse_string(char * string)
{


}

int main()
{
	/*bool ret = prime(9);
	if (ret)printf("������");
	else
	{
		printf("��������");
	}*/
	year_test(2001);
	/*int a = 10;
	int b = 9;
	printf("%d,%d\n", a, b);

	swap(&a,&b);
	printf("%d,%d\n",a,b);*/
	/*Print_(100);*/
	print_char(123);
	char str[] = "1234567";
	printf("%s\n", reverse_string(str));
}
