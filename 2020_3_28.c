#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//函数功能：整形转字符串,十进制字符串
//char *itoa(int value, char *string, int radix);
//	*char p[9];
//  *_itoa(13, p, 16);
//value:	要转换的整形
//string：  转换结果，与返回值相同
//radix:	转换的进制数 2 – 36（转换的基数，取值范围2-36）

///////////////////////////////////////////////////
//函数功能：整形转字符串（十进制）
//入口参数：
//		value：要转换的整数
//		buf:   转换后的字符串保存位置
//返回值：
//		无
//////////////////////////////////////////////////

void My_itoa(unsigned short value,char buf[] )  //0-65535
{
	int i = 0;
	int j = 5;
	if (value < 10)
	{
		buf[0] = value+'0';
		buf[1] = '\0';
	}
	else if ( value < 100)
	{
		buf[0] = value/10   + '0';
		buf[1] = value % 10 + '0';
		buf[2] = '\0';
	}
	else if ( value < 1000)
	{
		buf[0] = value / 100    + '0';
		buf[1] = value %100 /10 + '0';
		buf[2] = value % 10     + '0';
		buf[3] = '\0';
	}
	else if (value < 10000)
	{
		buf[0] = value / 1000 +       '0';
		buf[1] = value % 1000 / 100 + '0';
		buf[2] = value % 100/10 +     '0';
		buf[3] = value % 10 +         '0';
		buf[4] = '\0';
	}
	else if ( value < 65536)
	{
		buf[0] = value / 10000 +        '0';
		buf[1] = value % 10000 / 1000 + '0';
		buf[2] = value % 1000 / 100 +   '0';
		buf[3] = value % 100 /10 +      '0';
		buf[4] = value % 10 +           '0';
		buf[5] = '\0';
	}
}


///////////////////////////////////////////////////
//函数功能：整形转字符串（十进制）
//入口参数：
//		value：要转换的整数
//		buf:   转换后的字符串保存位置
//      N:	   整数的位数
//返回值：
//		无
//////////////////////////////////////////////////

void My_itoa_For(unsigned int value, char buf[] , int N)  
{
	int i = 0;
	int j = 0;
	for (int j=N;j>0;j--)
	{		
		//将整数value的第j位转换为字符:最低位为1（整数value第n位 = value%10^n/10^(n-1)）
		buf[i++] = (value %  (int)pow(10, j) )/ (int)pow(10, j - 1)+ '0';
	}
	buf[N] = '\0';
}


//int atoi(const char *string);
//字符串转整形，十进制整形


////////////////////////////////////////
//函数功能：字符串转整形，十或十六进制
//入口参数：
//			str：要转换的字符串
//			num：转换类型，10.十进制转换；16：十六进制转换
//返回值：	转换结果
///////////////////////////////////////

unsigned int  My_atoi(const char *str, char num)
{
	int ret = 0;
	int i = 0;

	if (str == NULL || *str == '\0')return 0;
	else
	{	
		if ('a' <= str[0] && str[0] <= 'z')  //得到对应的十六进制数
		{
			ret = str[0] - 'W';
		}

		else if('0' <= str[0] && str[0] <= '9')//得到对应的十进制数
		{
			ret = str[0] - '0';
		}

		else if ('A' <= str[0] && str[0] <= 'Z')//得到对应的十六进制数
		{
			ret = str[0] - 55;
		}

		while (*(str + i + 1) != '\0')  //确定该位所在的位置
		{
			i++;
		}

		if (num==10) //转换为十进制
		{
			if (ret > 9) exit(1);//参数输入错误
			ret *= pow(10, i); //十进制转换
			return ret + My_atoi(str + 1, 10);
		}
	
		if (num==16)//转换为十六进制
		{
			ret *= pow(16, i);//十六进制转换
			return ret + My_atoi(str + 1, 16);
		}
	}
}


////////////////////////////////////////
//函数功能：返回字符串长度
//入口参数：
//			P：要测量字符串
//返回值：	字符串长度
///////////////////////////////////////
int my_strlen(char *p)
{
	int ret = 0;
	while (*p++ != '\0')
	{
		ret++;
	}
	return ret;
}


////////////////////////////////////////
//函数功能：返回字符串长度
//入口参数：
//			P：要测量字符串
//返回值：	字符串长度
//递归实现
///////////////////////////////////////

int my_str_2(char *str)
{
	if (str == NULL)
	{
		return 0;
	}
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_str_2(str + 1);
	}
}
int main()
{
	printf("%d",My_atoi("A2",10));
}











