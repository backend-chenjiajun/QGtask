#include"calculate.h"
#include<stdio.h>
#include<stdlib.h>





int main()
{
	char n[1024] = {0};
	char temp[1024] = {0};
	int i;
	LinkStack s;
	if (!initLStack(&s))//初始化栈
	{
		printf("栈初始化失败.....正在退出程序！\n");
		system("pause");
		exit(0);
	}
	while (1)
	{

		clearLStack(&s);
		system("cls");
		view();
		if (dataScan(n))
		{
			//将中缀表达式转化为后缀表达式
			ConvertToSuffix(&s, n, temp);
			//得到结果
			getValue(&s, temp);
			
			//清空数组缓存
			for (i = 0; i < 1024; i++)
			{
				n[i] = 0;
			}
			for (i = 0; i < 1024; i++)
			{

				temp[i] = 0;
			}
		}
		else
		{
			printf("非法输入！\n");
			system("pause");
		}

	}
	
}