#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include"qgsort.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>



//������
void view()
{

	printf("==================================================================\n");
	printf("=                                                                =\n");
	printf("=            1 --- �ⲻͬ�Ĵ��������µ�������ʱ                  =\n");
	printf("=            2 --- �����С�����µ�������ʱ                      =\n");
	printf("=            3 --- ʵ����ɫ����                                  =\n");
	printf("=            4 --- ���������ҵ���k��/С��ֵ                      =\n");
	printf("=            5 --- �˳�                                          =\n");
	printf("=                                                                =\n");
	printf("==================================================================\n");
	printf("������1-5����ѡ��:\n");
}

//��ȡ���ֵ
int getMax(int* a, int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}
//�ж��Ƿ�����ɹ�
int isSorted(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (a[i + 1] < a[i])
		{
			return 0;
		}
	}
	return 1;
}

//��ӡ����
void print(int* a, int size)
{

	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//�������0-size���� 0 - max ��С���������,�����浽�ļ���
void getRadomAndSave(int size,int max)
{
	int* a;
	FILE* fp = fopen("data.txt", "w");
	a = (int*)malloc(size * sizeof(int));
	srand((unsigned)time(NULL));
	if (a)
	{
		for (int i = 0; i < size; i++)
		{
			a[i] = rand() % (max+1);
			fprintf(fp, "%d ", a[i]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	free(a);
}

//���ļ��ж�ȡ��������
void readData(int *a)
{
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("data.txt", "w");
	}
	for(int i = 0;!feof(fp);i++)
	{
		fscanf(fp, "%d ", &a[i]);
	}
	fscanf(fp, "\n");
	fclose(fp);
}

//���뺯����ֻ�����������֣�
int dataScan()
{
	int i = 0;
	int t = 0;
	char getdata[1024];//�洢���������
	char ch = getchar();
	fflush(stdin);
	while (ch != '\n')
	{

		getdata[i] = ch;
		ch = getchar();
		fflush(stdin);
		i++;
	}
	getdata[i] = '\0';

	if (getdata[0] == '\0') //�������ĵ�һ���Ƿ�Ϊ���У���������Ϊ�ǷǷ�����
		return -1;

	for (t = 0; t < i; t++)
	{
		if (getdata[t] > '9' || getdata[t] < '0')
		{
			return -1;                  //��������ڷ����֣����ж�Ϊ�Ƿ�����
		}
	}
	return atoi(getdata);
}
//��ȡ��������ʱ
double readTime(int* a, int looptime)
{
	//��ȡ������ʱ
	clock_t read_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		readData(a);
	}
	clock_t read_end = clock();
	return ((double)read_end - (double)read_begin) / CLOCKS_PER_SEC * 1000;

}

//�õ����ֵ����ʱ
double getMaxTime(int* a, int size,int looptime)
{
	int max;
	clock_t read_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		max = getMax(a, size);
	}
	clock_t read_end = clock();
	return ((double)read_end - (double)read_begin) / CLOCKS_PER_SEC * 1000;

}
//���������ʱ
void InsertSortTestTime(int *a,int size, int looptime)
{
	if (a)
	{
		//����+��ȡ��������ʱ
		clock_t time_begin = clock();
		for (int i = 0; i < looptime; i++)
		{
			//��ȡ����
			readData(a);
			insertSort(a, size);

		}
		clock_t time_end = clock();
		double readtime = readTime(a, looptime);
		double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
		printf("�������򻨷ѵ�ʱ��Ϊ��%lf ms\n",totalTime- readtime);
	}
}
//�鲢�����ʱ
void MergeSortTestTime(int* a, int size, int looptime)
{

	int* temp = (int*)malloc(sizeof(int) * size);
	if (a)
	{

		//����+��ȡ��������ʱ
		clock_t time_begin = clock();
		for (int i = 0; i < looptime; i++)
		{
			//��ȡ����
			readData(a);
			MergeSort(a, 0,size-1,temp);

		}
		clock_t time_end = clock();
		double readtime = readTime(a, looptime);
		double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
		printf("�鲢���򻨷ѵ�ʱ��Ϊ��%lf ms\n", totalTime - readtime);
	}
	free(temp);
}
//���ŵݹ���ʱ
void QuickSort_RecursionTestTime(int* a, int size, int looptime)
{


	   //����+��ȡ��������ʱ
		clock_t time_begin = clock();
		for (int i = 0; i < looptime; i++)
		{
			//��ȡ����
			readData(a);
			QuickSort_Recursion(a, 0, size - 1);

		}
		clock_t time_end = clock();
		double readtime = readTime(a, looptime);
		double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
		printf("���ţ��ݹ�棩���򻨷ѵ�ʱ��Ϊ��%lf ms\n", totalTime - readtime);
}
//���ŷǵݹ���ʱ
void QuickSortTestTime(int* a, int size, int looptime)
{
	//����+��ȡ��������ʱ
	clock_t time_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		//��ȡ����
		readData(a);
		QuickSort(a, size);

	}
	clock_t time_end = clock();
	double readtime = readTime(a, looptime);
	double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
	printf("���ţ��ǵݹ�棩���򻨷ѵ�ʱ��Ϊ��%lf ms\n", totalTime - readtime);
}
//���������ʱ
void CountSortTestTime(int* a, int size, int looptime)
{
	int max = 0;
	//����+��ȡ��������ʱ
	clock_t time_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		//��ȡ����
		readData(a);
		max = getMax(a, size);
		CountSort(a, size,max);

	}
	clock_t time_end = clock();
	double readtime = readTime(a, looptime);
	double getmaxTime = getMaxTime(a, size, looptime);
	double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
	printf("�������򻨷ѵ�ʱ��Ϊ��%lf ms\n", totalTime - readtime-getmaxTime);

}
//�������������ʱ
void RadixCountSortTestTime(int* a, int size, int looptime)
{
	//����+��ȡ��������ʱ
	clock_t time_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		//��ȡ����
		readData(a);
		RadixCountSort(a, size);

	}
	clock_t time_end = clock();
	double readtime = readTime(a, looptime);
	double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
	printf("�����������򻨷ѵ�ʱ��Ϊ��%lf ms\n", totalTime - readtime);
}

int main()
{
	int* a;
	 int looptimes;
	int size;
	unsigned int max;

	while (1)
	{
		system("cls");
		view();
		int chosen = dataScan();
		double readtime;
		int* a;
		switch (chosen)
		{
		case 1:
			printf("��ѡ��������� 1 -- 10000��2 -- 50000��3 -- 200000 4 -- �Զ���������\n");
			int select = dataScan();
			if (select >= 1 && select <= 4)
			{
				switch (select)
				{
				case 1:
					size = 10000;
					break;
				case 2:
					size = 50000;
					break;
				case 3:
					size = 200000;
					break;
				case 4:
					printf("���������Զ������������\n");
					size = dataScan();
					if (size == -1)
					{
						printf("�Ƿ����룡���������룺\n");
						size = dataScan();
					}
					break;
				default:
					printf("�������\n");
					system("pause");
				}
				printf("��������Ҫ���������������ֵmax��\n");
				max = dataScan();
				printf("��������Ҫ����ѭ���Ĵ�����\n");
				looptimes = dataScan();
				printf("���Ե�\n");
				a = (int*)malloc(size * sizeof(int));
				getRadomAndSave(size, max);
				InsertSortTestTime(a, size, looptimes);
				MergeSortTestTime(a, size, looptimes);
				QuickSort_RecursionTestTime(a, size, looptimes);
				QuickSortTestTime(a, size, looptimes);
				CountSortTestTime(a, size, looptimes);
				//	RadixCountSortTestTime(a, size, looptimes);
				free(a);
			}
			else
			{
				printf("�������\n");
			}
			system("pause");
			break;

		case 2:
			printf("1 -- 100 * 100k ������ (���ݵ�ȡֵΪ0-100)    2 --- �Զ������鳤�ȡ���С�ʹ�������\n");
			printf("��ѡ�� 1 �� 2��\n");
			int choice = dataScan();
			if (choice == 1 || choice == 2)
			{
				if (choice == 1)
				{
					size = 100;
					max = 100;
					looptimes = 100000;
				}
				else
				{
					printf("��������Ҫ�����������ĳ���size��\n");
					size = dataScan();
					if (size == -1)
					{
						printf("�Ƿ����룡���������룺\n");
						size = dataScan();
					}
					printf("��������Ҫ���������������ֵmax��\n");
					max = dataScan();
					if (max == -1)
					{
						printf("�Ƿ����룡���������룺\n");
						max = dataScan();
					}
					printf("��������Ҫ����ѭ���Ĵ�����\n");
					looptimes = dataScan();
					if (looptimes == -1)
					{
						printf("�Ƿ����룡���������룺\n");
						looptimes = dataScan();
					}
				}
				printf("���Ե�\n");
				a = (int*)malloc(size * sizeof(int));
				getRadomAndSave(size, max);
				InsertSortTestTime(a, size, looptimes);
				MergeSortTestTime(a, size, looptimes);
				QuickSort_RecursionTestTime(a, size, looptimes);
				QuickSortTestTime(a, size, looptimes);
				CountSortTestTime(a, size, looptimes);
				//	RadixCountSortTestTime(a, size, looptimes);
				free(a);
			}
			else
			{
				printf("�������\n");
			}
			system("pause");
			break;
		case 3:

			printf("���������鳤�ȣ�\n");
			size = dataScan();
			if (size == -1 || size == 0)
			{
				printf("�Ƿ����룡���������룺\n");
				size = dataScan();
			}
			a = (int*)malloc(size * sizeof(int));
			getRadomAndSave(size, 2);
			readData(a);
			printf("����ǰ��\n");
			print(a, size);
			ColorSort(a, size);
			printf("�����\n");
			print(a, size);
			system("pause");
			free(a);
			break;

		case 4:
			printf("��ѡ����  1 --- ��KС   2 --- ��K��  \n");
			int c = dataScan();
			if (c == 1 || c == 2)
			{
				printf("������K��\n");
				int k = dataScan();
				if (k == -1)
				{
					printf("�Ƿ����룡���������룺\n");
					k = dataScan();
				}
				printf("��������Ҫ�����������ĳ���size��\n");
				size = dataScan();
				if (size == -1 || size == 0)
				{
					printf("�Ƿ����룡���������룺\n");
					size = dataScan();
				}
				printf("��������Ҫ���������������ֵmax��\n");
				max = dataScan();
				if (max == -1 || max == 0)
				{
					printf("�Ƿ����룡���������룺\n");
					max = dataScan();
				}
				a = (int*)malloc(size * sizeof(int));
				getRadomAndSave(size, max);
				readData(a);
				printf("����Ϊ��\n");
				print(a, size);
				if (c == 1)
				{
					findKthNum(a, 0, size - 1, k);
				}
				else if (c == 2)
				{
					findKthNum(a, 0, size - 1, size - k);
				}
				free(a);
			}
			else
			{
				printf(" ѡ�����\n");
			}
			system("pause");

			break;
		case 5:
			printf("�����˳�������\n");
			system("pause");
			exit(0);
		default:
			printf("������󣡷Ƿ�����!\n");
			system("pause");
			break;
		}


	}
}