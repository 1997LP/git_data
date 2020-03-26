#include <stdio.h>
//
//*************************2020_3_26日***************************
//计算斐波拉契数列
int Fib(int n) //递归的形式，算法时间复杂度太大
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

int Fib_2(int n)  //三个变量依次向上
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
////判断一个数是不是素数
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
		printf("%d是闰年", num);
	}
	else
	{
		printf("%d是不闰年", num);
	}
}
void swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}
//在屏幕上输出乘法口诀表
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

//打印一个数字的每一位
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

//求阶乘
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
//编写一个函数 reverse_string(char * string)（递归实现）
//
//实现：将参数字符串中的字符反向排列。
//
//要求：不能使用C函数库中的字符串操作函数。

char *reverse_string(char * string)
{


}

int main()
{
	/*bool ret = prime(9);
	if (ret)printf("是素数");
	else
	{
		printf("不是素数");
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
