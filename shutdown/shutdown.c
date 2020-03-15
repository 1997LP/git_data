#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char * str[20];
	
	system("shutdown -s -t 300");
	while (1) {
		printf("您的电脑在5分钟后即将关机，输入:'我是猪'解除关机 \r\n");
		scanf("%s",str);
		if (strcmp("我是猪", str)==0) {
			system("shutdown -a");
			break;
		}
	}
	return 0;
}

