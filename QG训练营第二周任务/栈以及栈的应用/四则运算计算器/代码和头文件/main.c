#include"calculate.h"
#include<stdio.h>
#include<stdlib.h>





int main()
{
	char n[1024] = {0};
	char temp[1024] = {0};
	int i;
	LinkStack s;
	if (!initLStack(&s))//��ʼ��ջ
	{
		printf("ջ��ʼ��ʧ��.....�����˳�����\n");
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
			//����׺���ʽת��Ϊ��׺���ʽ
			ConvertToSuffix(&s, n, temp);
			//�õ����
			getValue(&s, temp);
			
			//������黺��
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
			printf("�Ƿ����룡\n");
			system("pause");
		}

	}
	
}