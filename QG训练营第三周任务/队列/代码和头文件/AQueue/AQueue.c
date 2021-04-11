#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void InitAQueue(AQueue* Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
	{
		Q->data[i] = (void*)malloc(50);
	}
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
}

void DestoryAQueue(AQueue* Q)
{

	int i;
	for (i = 0; i < MAXQUEUE; i++)
	{
		free(Q->data[i]);
	}
	Q->data[0] = NULL;
}

Status IsFullAQueue(const AQueue* Q)
{
	if ((Q->rear + 1) % (MAXQUEUE + 1) == Q->front)
		return TRUE;
	return FALSE;
}

Status IsEmptyAQueue(const AQueue* Q)
{
	if (Q->rear == Q->front)
		return TRUE;
	return FALSE;
}

Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	else
	{
		//调用mencpy实现多种类型的复制
		memcpy(e,Q->data[Q->front],datatype[Q->front]);
		return TRUE;
	}
	
}

int LengthAQueue(AQueue* Q)
{
	return Q->length;
}

Status EnAQueue(AQueue* Q, void* data)
{
	if (IsFullAQueue(Q)) 
	{
		return FALSE;
	}
	else 
	{
		
		//调用mencpy实现多种类型的复制
		memcpy(Q->data[Q->rear], data, datatype[Q->rear]);
		Q->rear = (Q->rear + 1) % (MAXQUEUE+1);
		Q->length++;
		return TRUE;
	}

}

Status DeAQueue(AQueue* Q)
{
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	else
	{
		Q->front = (Q->front + 1) % (MAXQUEUE+1);
		Q->length--;
	}
	return TRUE;
}

void ClearAQueue(AQueue* Q)
{

	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
}

Status TraverseAQueue(const AQueue* Q, void(*foo)(void* q,int datatype))
{
	//队列为空直接返回FALSE
	if (IsEmptyAQueue(Q)) {
		return FALSE;
	}
	else
	{
		int i = 0;
		//i先赋值为front
		for (i = Q->front; i != Q->rear; i = (i + 1) % (MAXQUEUE+1))
		{
			//调用函数打印
			foo(Q->data[i],datatype[i]);
		}
		printf("\n");
		return TRUE;
	}
	
}

void APrint(void* q,int datasize)
{
	if (datasize == sizeof(int))
	{
		printf("%d  ",*(int*)q);
	}
	if (datasize == sizeof(char))
	{
		printf("%c  ", *(char*)q);
	}
	if (datasize == sizeof(double))
	{
		printf("%lf  ", *(double*)q);
	}
}
