#include"qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Peer
{
	unsigned int begin;
	unsigned int end;
}Peer;
typedef struct Stack
{
	Peer* data;
	int   top;
}Stack;


void insertSort(int* a, int n)
{
	int i, j, temp;
	
	for (i = 1; i < n; i++)
	{
		
		for (j = i; j > 0&& a[j] < a[j - 1]; j--)
		{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
		}
	}
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int i = begin;
	int j = mid + 1;
	int k = 0;

	//将数组进行排序
	while (i <= mid && j <= end)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}

	//将剩余元素填充到数组中
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	//将剩余元素填充到数组中
	while (j <= end)
	{
		temp[k++] = a[j++];
	}

	//将temp数组的元素复制到a数组中
	for (i = 0; i < k; i++)
	{
		a[begin + i] = temp[i];
	}
}

void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin < end)
	{
		//中间索引
		int mid = (begin + end) / 2;
		//将中间索引左边的不断拆分
		MergeSort(a, begin, mid, temp);
		//将中间索引右边的不断拆分
		MergeSort(a, mid + 1, end, temp);
		//合并
		MergeArray(a, begin, mid, end, temp);

	}
}

void QuickSort_Recursion(int* a, int begin, int end)
{
	
	if (begin < end)
	{
		int p = Partition(a, begin, end);//基准
		QuickSort_Recursion(a, begin, p-1);//左边继续调用函数 
		QuickSort_Recursion(a, p+1, end);//右边继续调用函数 
	}
	
}

void QuickSort(int* a, int size)
{
	int n = (int)(log((double)size) / log((double)2)) + 1;
	Stack s;
	s.data = (Peer*)malloc(sizeof(Peer) * n);
	if (s.data)
	{
		//初始化栈
		s.top = 0;
		Peer p;
		p.begin = 0;
		p.end = size - 1;
		s.data[s.top++] = p;

		while (s.top != 0)
		{
			p = s.data[--s.top];
			int mid = Partition(a, p.begin, p.end);

			if (p.end - mid > 1)
			{
				Peer newp;
				newp.begin = mid + 1;
				newp.end = p.end;
				s.data[s.top++] = newp;
			}
			if (mid - p.begin > 1)
			{
				Peer newp;
				newp.begin = p.begin;
				newp.end = mid - 1;
				s.data[s.top++] = newp;
			}
		}
	}
	free(s.data);
}

int Partition(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	int temp;
	int i, j;

	//找到前中后三个数的中位数，并将中位数交换为首元素
	if (a[begin] <= a[mid] && a[mid] <= a[end] || a[end] <= a[mid] && a[mid] <= a[begin])
	{
		temp = a[begin];
		a[begin] = a[mid];
		a[mid] = temp;
	}
	if (a[begin] <= a[end] && a[end] <= a[mid] || a[mid] <= a[end] && a[end] <= a[begin])
	{
		temp = a[begin];
		a[begin] = a[end];
		a[end] = temp;
	}

	if (begin < end)
	{
		i = begin;
		j = end;
		int p = a[i];//基准为第一个元素

		while (i<j)
		{
			//如果最后一个元素比基准大，则j往前移一位
			while (i<j && a[j]>=p)
			{
				j--;
			}
			// 将索引为i的元素与索引为j的元素交换，并且i加一
			if (i < j) a[i++] = a[j];

			//如果前元素比基准小，则往后移一位
			while (i < j && a[i] < p)
			{
				i++;
			}
			// 将索引为j的元素与索引为i的元素交换，并且j减一
			if (i < j) a[j--] = a[i];
		}

		a[i] = p;
		//返回中间索引
		return i;

	}

	return begin;
}

void CountSort(int* a, int size, int max)
{
	int i;

	//动态内存分配
	int* count = (int*)malloc((max + 1) * sizeof(int));
	int* temp = (int*)malloc((size) * sizeof(int));

	if (count && temp)
	{
		//初始化数组为0	
		for (i = 0; i <= max; i++)
		{
			count[i] = 0;
		}
		//计算每种值的元素个数 
		for (i = 0; i < size; i++)
		{
			count[a[i]]++;
		}
		//计算小于等于该值的元素个数 
		for (i = 1; i <= max; i++)
		{
			count[i] += count[i - 1];
		}
		// 倒序将a数组上的元素对应count数组上的元素值减一后对应在temp数组上的位置上 
		for (i = size - 1; i >= 0; i--)
		{
			temp[--count[a[i]]] = a[i];
		}
		//将temp数组排序好的值复制到a数组上 
		for (i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
	}
	
	//释放内存 
	free(count);
	free(temp);

}

void RadixCountSort(int* a, int size)
{
	int i;
	int base = 1;
	int max = a[0];
	for (i = 1; i < size; i++)//找出最大值
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	
	int count[10] = {0};
	int* temp = (int*)malloc(size * sizeof(int));

		while ((max / base )> 0)
		{

			if (temp)
			{
				//初始化数组为0	
				//计算每种值的元素个数 
				for (i = 0; i < 10; i++)
				{
					count[a[i] / base % 10]++;
				}
				//计算小于等于该值的元素个数 
				for (i = 1; i < 10; i++)
				{
					count[i] += count[i - 1];
				}
				// 倒序将a数组上的元素对应count数组上的元素值减一后对应在temp数组上的位置上 
				for (i = size - 1; i >= 0; i--)
				{
					temp[(count[(a[i] / base) % 10])-1] = a[i];
					count[(a[i] / base) % 10]--;
				}

				//将temp数组排序好的值复制到a数组上 
				memcpy(a, temp, size * sizeof(int));
			
				base *= 10;
			}

		}
	
	//释放内存   
	free(temp);

}

void ColorSort(int* a, int size)
{
	int p1 = 0;//头索引
	int p2 = size - 1; // 尾索引
	int i = 1; //遍历索引
	int temp;//暂存数据

	//当遍历索引与尾索引相遇时停止循环
	while (i < p2)
	{
		//当遍历索引的数据为2时与尾索引数据交换，尾索引减一
		if (a[i] == 2)
		{
			temp = a[p2];
			a[p2--] = a[i];
			a[i] = temp;
		}
		//当遍历所有的数据为0时与头索引数据交换，头索引加一
		if (a[i] == 0)
		{
			temp = a[p1];
			a[p1++] = a[i];
			a[i] = temp;
		}

		//当遍历索引数据为1或者头索引与遍历索引相遇时，遍历索引加一
		if (a[i] == 1 || i == p1) i++;
	}
}


void findKthNum(int* a, int begin,int end,int k)
{
	int p = Partition(a, begin, end);

	if (p == k - 1)
	{
		printf("所求的数为：%d\n",a[p]);
	}
	else if (p > k-1)
	{
		findKthNum(a,begin,p-1,k);
	}
	else
	{
		findKthNum(a,p+1,end,k );
	}
}

