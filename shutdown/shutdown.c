#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char * str[20];
	
	system("shutdown -s -t 300");
	while (1) {
		printf("���ĵ�����5���Ӻ󼴽��ػ�������:'������'����ػ� \r\n");
		scanf("%s",str);
		if (strcmp("������", str)==0) {
			system("shutdown -a");
			break;
		}
	}
	return 0;
}

