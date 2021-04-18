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

	//�������������
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

	//��ʣ��Ԫ����䵽������
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	//��ʣ��Ԫ����䵽������
	while (j <= end)
	{
		temp[k++] = a[j++];
	}

	//��temp�����Ԫ�ظ��Ƶ�a������
	for (i = 0; i < k; i++)
	{
		a[begin + i] = temp[i];
	}
}

void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin < end)
	{
		//�м�����
		int mid = (begin + end) / 2;
		//���м�������ߵĲ��ϲ��
		MergeSort(a, begin, mid, temp);
		//���м������ұߵĲ��ϲ��
		MergeSort(a, mid + 1, end, temp);
		//�ϲ�
		MergeArray(a, begin, mid, end, temp);

	}
}

void QuickSort_Recursion(int* a, int begin, int end)
{
	
	if (begin < end)
	{
		int p = Partition(a, begin, end);//��׼
		QuickSort_Recursion(a, begin, p-1);//��߼������ú��� 
		QuickSort_Recursion(a, p+1, end);//�ұ߼������ú��� 
	}
	
}

void QuickSort(int* a, int size)
{
	int n = (int)(log((double)size) / log((double)2)) + 1;
	Stack s;
	s.data = (Peer*)malloc(sizeof(Peer) * n);
	if (s.data)
	{
		//��ʼ��ջ
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

	//�ҵ�ǰ�к�����������λ����������λ������Ϊ��Ԫ��
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
		int p = a[i];//��׼Ϊ��һ��Ԫ��

		while (i<j)
		{
			//������һ��Ԫ�رȻ�׼����j��ǰ��һλ
			while (i<j && a[j]>=p)
			{
				j--;
			}
			// ������Ϊi��Ԫ��������Ϊj��Ԫ�ؽ���������i��һ
			if (i < j) a[i++] = a[j];

			//���ǰԪ�رȻ�׼С����������һλ
			while (i < j && a[i] < p)
			{
				i++;
			}
			// ������Ϊj��Ԫ��������Ϊi��Ԫ�ؽ���������j��һ
			if (i < j) a[j--] = a[i];
		}

		a[i] = p;
		//�����м�����
		return i;

	}

	return begin;
}

void CountSort(int* a, int size, int max)
{
	int i;

	//��̬�ڴ����
	int* count = (int*)malloc((max + 1) * sizeof(int));
	int* temp = (int*)malloc((size) * sizeof(int));

	if (count && temp)
	{
		//��ʼ������Ϊ0	
		for (i = 0; i <= max; i++)
		{
			count[i] = 0;
		}
		//����ÿ��ֵ��Ԫ�ظ��� 
		for (i = 0; i < size; i++)
		{
			count[a[i]]++;
		}
		//����С�ڵ��ڸ�ֵ��Ԫ�ظ��� 
		for (i = 1; i <= max; i++)
		{
			count[i] += count[i - 1];
		}
		// ����a�����ϵ�Ԫ�ض�Ӧcount�����ϵ�Ԫ��ֵ��һ���Ӧ��temp�����ϵ�λ���� 
		for (i = size - 1; i >= 0; i--)
		{
			temp[--count[a[i]]] = a[i];
		}
		//��temp��������õ�ֵ���Ƶ�a������ 
		for (i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
	}
	
	//�ͷ��ڴ� 
	free(count);
	free(temp);

}

void RadixCountSort(int* a, int size)
{
	int i;
	int base = 1;
	int max = a[0];
	for (i = 1; i < size; i++)//�ҳ����ֵ
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
				//��ʼ������Ϊ0	
				//����ÿ��ֵ��Ԫ�ظ��� 
				for (i = 0; i < 10; i++)
				{
					count[a[i] / base % 10]++;
				}
				//����С�ڵ��ڸ�ֵ��Ԫ�ظ��� 
				for (i = 1; i < 10; i++)
				{
					count[i] += count[i - 1];
				}
				// ����a�����ϵ�Ԫ�ض�Ӧcount�����ϵ�Ԫ��ֵ��һ���Ӧ��temp�����ϵ�λ���� 
				for (i = size - 1; i >= 0; i--)
				{
					temp[(count[(a[i] / base) % 10])-1] = a[i];
					count[(a[i] / base) % 10]--;
				}

				//��temp��������õ�ֵ���Ƶ�a������ 
				memcpy(a, temp, size * sizeof(int));
			
				base *= 10;
			}

		}
	
	//�ͷ��ڴ�   
	free(temp);

}

void ColorSort(int* a, int size)
{
	int p1 = 0;//ͷ����
	int p2 = size - 1; // β����
	int i = 1; //��������
	int temp;//�ݴ�����

	//������������β��������ʱֹͣѭ��
	while (i < p2)
	{
		//����������������Ϊ2ʱ��β�������ݽ�����β������һ
		if (a[i] == 2)
		{
			temp = a[p2];
			a[p2--] = a[i];
			a[i] = temp;
		}
		//���������е�����Ϊ0ʱ��ͷ�������ݽ�����ͷ������һ
		if (a[i] == 0)
		{
			temp = a[p1];
			a[p1++] = a[i];
			a[i] = temp;
		}

		//��������������Ϊ1����ͷ�����������������ʱ������������һ
		if (a[i] == 1 || i == p1) i++;
	}
}


void findKthNum(int* a, int begin,int end,int k)
{
	int p = Partition(a, begin, end);

	if (p == k - 1)
	{
		printf("�������Ϊ��%d\n",a[p]);
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

