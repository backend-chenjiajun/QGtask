#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include"qgsort.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>



//主界面
void view()
{

	printf("==================================================================\n");
	printf("=                                                                =\n");
	printf("=            1 --- 测不同的大数据量下的排序用时                  =\n");
	printf("=            2 --- 测大量小数组下的排序用时                      =\n");
	printf("=            3 --- 实现颜色排序                                  =\n");
	printf("=            4 --- 在数组中找到第k大/小的值                      =\n");
	printf("=            5 --- 退出                                          =\n");
	printf("=                                                                =\n");
	printf("==================================================================\n");
	printf("请输入1-5进行选择:\n");
}

//获取最大值
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
//判断是否排序成功
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

//打印数组
void print(int* a, int size)
{

	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//随机生成0-size长度 0 - max 大小的随机数组,并保存到文件中
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

//从文件中读取数组数据
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

//输入函数（只允许输入数字）
int dataScan()
{
	int i = 0;
	int t = 0;
	char getdata[1024];//存储输入的数据
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

	if (getdata[0] == '\0') //检查输入的第一个是否为换行，若是则认为是非法输入
		return -1;

	for (t = 0; t < i; t++)
	{
		if (getdata[t] > '9' || getdata[t] < '0')
		{
			return -1;                  //若输入存在非数字，则判定为非法输入
		}
	}
	return atoi(getdata);
}
//读取数据总用时
double readTime(int* a, int looptime)
{
	//读取数据用时
	clock_t read_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		readData(a);
	}
	clock_t read_end = clock();
	return ((double)read_end - (double)read_begin) / CLOCKS_PER_SEC * 1000;

}

//得到最大值总用时
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
//插入排序测时
void InsertSortTestTime(int *a,int size, int looptime)
{
	if (a)
	{
		//排序+读取数据总用时
		clock_t time_begin = clock();
		for (int i = 0; i < looptime; i++)
		{
			//读取数据
			readData(a);
			insertSort(a, size);

		}
		clock_t time_end = clock();
		double readtime = readTime(a, looptime);
		double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
		printf("插入排序花费的时间为：%lf ms\n",totalTime- readtime);
	}
}
//归并排序测时
void MergeSortTestTime(int* a, int size, int looptime)
{

	int* temp = (int*)malloc(sizeof(int) * size);
	if (a)
	{

		//排序+读取数据总用时
		clock_t time_begin = clock();
		for (int i = 0; i < looptime; i++)
		{
			//读取数据
			readData(a);
			MergeSort(a, 0,size-1,temp);

		}
		clock_t time_end = clock();
		double readtime = readTime(a, looptime);
		double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
		printf("归并排序花费的时间为：%lf ms\n", totalTime - readtime);
	}
	free(temp);
}
//快排递归版测时
void QuickSort_RecursionTestTime(int* a, int size, int looptime)
{


	   //排序+读取数据总用时
		clock_t time_begin = clock();
		for (int i = 0; i < looptime; i++)
		{
			//读取数据
			readData(a);
			QuickSort_Recursion(a, 0, size - 1);

		}
		clock_t time_end = clock();
		double readtime = readTime(a, looptime);
		double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
		printf("快排（递归版）排序花费的时间为：%lf ms\n", totalTime - readtime);
}
//快排非递归版测时
void QuickSortTestTime(int* a, int size, int looptime)
{
	//排序+读取数据总用时
	clock_t time_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		//读取数据
		readData(a);
		QuickSort(a, size);

	}
	clock_t time_end = clock();
	double readtime = readTime(a, looptime);
	double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
	printf("快排（非递归版）排序花费的时间为：%lf ms\n", totalTime - readtime);
}
//计数排序测时
void CountSortTestTime(int* a, int size, int looptime)
{
	int max = 0;
	//排序+读取数据总用时
	clock_t time_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		//读取数据
		readData(a);
		max = getMax(a, size);
		CountSort(a, size,max);

	}
	clock_t time_end = clock();
	double readtime = readTime(a, looptime);
	double getmaxTime = getMaxTime(a, size, looptime);
	double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
	printf("计数排序花费的时间为：%lf ms\n", totalTime - readtime-getmaxTime);

}
//基数计数排序测时
void RadixCountSortTestTime(int* a, int size, int looptime)
{
	//排序+读取数据总用时
	clock_t time_begin = clock();
	for (int i = 0; i < looptime; i++)
	{
		//读取数据
		readData(a);
		RadixCountSort(a, size);

	}
	clock_t time_end = clock();
	double readtime = readTime(a, looptime);
	double totalTime = ((double)time_end - (double)time_begin) / CLOCKS_PER_SEC * 1000;
	printf("基数计数排序花费的时间为：%lf ms\n", totalTime - readtime);
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
			printf("请选择大数据量 1 -- 10000、2 -- 50000、3 -- 200000 4 -- 自定义数据量\n");
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
					printf("请输入您自定义的数据量：\n");
					size = dataScan();
					if (size == -1)
					{
						printf("非法输入！请重新输入：\n");
						size = dataScan();
					}
					break;
				default:
					printf("输入错误！\n");
					system("pause");
				}
				printf("请输入您要创建随机数组的最大值max：\n");
				max = dataScan();
				printf("请输入您要进行循环的次数：\n");
				looptimes = dataScan();
				printf("请稍等\n");
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
				printf("输入错误！\n");
			}
			system("pause");
			break;

		case 2:
			printf("1 -- 100 * 100k 次排序 (数据的取值为0-100)    2 --- 自定义数组长度、大小和次数排序\n");
			printf("请选择 1 或 2：\n");
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
					printf("请输入您要创建随机数组的长度size：\n");
					size = dataScan();
					if (size == -1)
					{
						printf("非法输入！请重新输入：\n");
						size = dataScan();
					}
					printf("请输入您要创建随机数组的最大值max：\n");
					max = dataScan();
					if (max == -1)
					{
						printf("非法输入！请重新输入：\n");
						max = dataScan();
					}
					printf("请输入您要进行循环的次数：\n");
					looptimes = dataScan();
					if (looptimes == -1)
					{
						printf("非法输入！请重新输入：\n");
						looptimes = dataScan();
					}
				}
				printf("请稍等\n");
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
				printf("输入错误！\n");
			}
			system("pause");
			break;
		case 3:

			printf("请输入数组长度：\n");
			size = dataScan();
			if (size == -1 || size == 0)
			{
				printf("非法输入！请重新输入：\n");
				size = dataScan();
			}
			a = (int*)malloc(size * sizeof(int));
			getRadomAndSave(size, 2);
			readData(a);
			printf("排序前：\n");
			print(a, size);
			ColorSort(a, size);
			printf("排序后：\n");
			print(a, size);
			system("pause");
			free(a);
			break;

		case 4:
			printf("请选择找  1 --- 第K小   2 --- 第K大  \n");
			int c = dataScan();
			if (c == 1 || c == 2)
			{
				printf("请输入K：\n");
				int k = dataScan();
				if (k == -1)
				{
					printf("非法输入！请重新输入：\n");
					k = dataScan();
				}
				printf("请输入您要创建随机数组的长度size：\n");
				size = dataScan();
				if (size == -1 || size == 0)
				{
					printf("非法输入！请重新输入：\n");
					size = dataScan();
				}
				printf("请输入您要创建随机数组的最大值max：\n");
				max = dataScan();
				if (max == -1 || max == 0)
				{
					printf("非法输入！请重新输入：\n");
					max = dataScan();
				}
				a = (int*)malloc(size * sizeof(int));
				getRadomAndSave(size, max);
				readData(a);
				printf("数组为：\n");
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
				printf(" 选择错误！\n");
			}
			system("pause");

			break;
		case 5:
			printf("正在退出···\n");
			system("pause");
			exit(0);
		default:
			printf("输入错误！非法输入!\n");
			system("pause");
			break;
		}


	}
}