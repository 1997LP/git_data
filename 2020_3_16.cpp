#include <stdio.h>
#include <string.h>

//模拟实现测量字符串strlen函数
int my_string1(const char *str)//创建临时变量
{
	int length = 0;
	while (*str != '\0') {
		length++;
		str++;
	}
	return	length;
}
int my_string2(const char *str) //不创建临时变量
{
	if (*str == '\0')return 0;
	else return 1 + my_string2(++str);
}

int my_string3(const char *str)
{
	const char *P = str;
	while (*P != '\0') {
		P++;
	}
	return P - str;
}

//模拟实现strcpy函数
char *strcpy_1(char *target, const char *source)
{
	while (*source != '\0') {
		*target++ = *source++;
	}
	*target = '\0';
	return target;
}

