#include <stdio.h>
#include <string.h>

//ģ��ʵ�ֲ����ַ���strlen����
int my_string1(const char *str)//������ʱ����
{
	int length = 0;
	while (*str != '\0') {
		length++;
		str++;
	}
	return	length;
}
int my_string2(const char *str) //��������ʱ����
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

//ģ��ʵ��strcpy����
char *strcpy_1(char *target, const char *source)
{
	while (*source != '\0') {
		*target++ = *source++;
	}
	*target = '\0';
	return target;
}

