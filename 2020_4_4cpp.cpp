
////////////////////////////////////
//   2020��4��3��
//	�������ܣ�ͳ�������������������ж��ٸ�λ��ͬ
///////////////////////////////////

int Statistics(int data, int data2)
{
	int num = data ^ data2;
	int ret = 0;
	for (int i = 0; i < sizeof(num) * 8; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			ret++;
		}
	}
	return ret;
}
////////////////////////////////////
//   2020��4��3��
//	�������ܣ���ȡһ���������������������е�ż��λ������λ��
//	�ֱ��ӡ������������
///////////////////////////////////
void  Binary(int data)
{
	int i = 0;
	int k = 0;
	printf("%d ������λ��\r\n", data);
	for (i = sizeof(int) * 8 - 2; i >= 0; i -= 2) //��ӡ����λ
	{
		if ((data >> i) & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n%d ��ż��λ��\r\n", data);
	for (i = sizeof(int) * 8 - 1; i > 0; i -= 2) //��ӡż��λ
	{
		if ((data >> i) & 1)
			printf("1");
		else
			printf("0");
	}
}
////////////////////////////////////
//   2020��4��3��
//	�������ܣ�дһ���������ز����������� 1 �ĸ�����
//
///////////////////////////////////

int  Binary_num(int data)
{
	int ret = 0;
	for (int i = 0; i < sizeof(data) * 8; i++)
	{
		if ((data >> i) & 1)
			ret++;
	}
	return ret;
}
////////////////////////////////////
//   2020��4��3��
//	�������ܣ�����������ʱ������������������������
//
///////////////////////////////////

void Swap(int *data, int *num)
{
	*data = *data^*num;
	*num = *data^*num;
	*data = *data^*num;
}
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	short *p = (short*)arr;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		*(p + i) = 0;
//	}
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//
//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long *pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d, %d\n", *pulPtr, *(pulPtr + 3));
//
//	return 0;
//}
//


////////////////////////////////////
//   2020��4��3��
//	�������ܣ�дһ��������ӡarr��������ݣ�
//��ʹ�������±꣬ʹ��ָ�롣arr��һ������һά���顣
//
///////////////////////////////////
int Printarr(int *buf, int length)
{
	if (buf == NULL)
		return -1;
	else
	{
		for (int i = 0; i < length; i++)
		{
			printf("%d", *(buf + i));
		}
	}
	return 0;
}
////////////////////////////////////
//   2020��4��3��
//	�������ܣ�дһ����������������һ���ַ��������ݡ�
//
///////////////////////////////////
void String_ret(char *str)
{
	int num = 0;
	if (str == NULL)
	{
		printf("�����������\n");
		return;
	}
	else
	{
		while (*str++ != '\0')
		{
			num++;
		}
		str -= 2;
		while (num)
		{
			printf("%c", *str--);
			num--;
		}
	}
}
//
//int main()
//{
//	char buf[] = "Liupeng Liye!";
//	printf("%s\n",buf);
//	String_ret(buf);
//	return 0;
//}
//
//int main()
//{
//	int a = 0x11223344;
//	char *pc = (char*)&a;
//	*pc = 0;
//	printf("%x\n", a);
//	return 0;
//}

////////////////////////////////////
//   2020��4��3��
//	�������ܣ���Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//	���磺2 + 22 + 222 + 2222 + 22222
///////////////////////////////////

unsigned int Sum_a(int a)
{
	if (a > 100000)return 0;
	else
	{
		return a + Sum_a(a * 10 + a % 10);
	}
}
//	return a + a * 10 + a + (a * 10 + a) * 10 + a + ((a * 10 + a) * 10 + a) * 10 + a +
//(((a * 10 + a) * 10 + a) * 10 + a) * 10 + a;

//���0��100000֮������С�ˮ�ɻ������������

//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ���������:153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������


////////////////////////////////////
//   2020��4��3��
//	�������ܣ����0��100000֮������С�ˮ�ɻ������������
//	���磺2 + 22 + 222 + 2222 + 22222
///////////////////////////////////
void Daffodil(int data)
{
	int sum = 0;
	int bit[6];
	int k = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < data + 1; i++)
	{
		sum = 0;
		if (i < 10)
			k = 1;
		else if (i < 100)
			k = 2;
		else if (i >= 100 && i < 1000)
			k = 3;
		else if (i >= 1000 && i < 10000)
			k = 4;
		else if (i >= 10000 && i < 100000)
			k = 5;

		for (j = 0; j < k; j++)
		{
			bit[j] = i % (int)pow(10, j + 1) / (int)pow(10, j);
		}

		for (j = 0; j < k; j++)
		{
			sum += pow(bit[j], k);//bit[j]^k;
		}

		if (sum == i)
			printf("%d\n", i);
	}

}



int main()
{
	return 0;
}

