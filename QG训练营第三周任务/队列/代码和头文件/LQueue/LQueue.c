#include "LQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void InitLQueue(LQueue* Q)
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head)
	{
		head->next = NULL;
		Q->front = Q->rear = head;
		Q->front->datasize = 0;
		Q->length = 0;
	}
}

void DestoryLQueue(LQueue* Q)
{
	ClearLQueue(Q);
	free(Q->front);
}

Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length == 0)
		return TRUE;
	return FALSE;
}

Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	else
	{
		memcpy(e, Q->front->next->data, Q->front->next->datasize);
		return TRUE;
	}
	
}

int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

Status EnLQueue(LQueue* Q, void* data)
{
	Node* pMove = (Node*)malloc(sizeof(Node));
	if (!pMove)
		return FALSE;
	else
	{
		pMove->data = (void*)malloc(sizeof(type));
		pMove->next = NULL;
		pMove->datasize = type;
		memcpy(pMove->data, data, type);
		Q->rear->next = pMove;
		Q->rear = pMove;
		Q->length++;
		return TRUE;
	}
	

}

Status DeLQueue(LQueue* Q)
{
	if (!IsEmptyLQueue(Q))
	{
		Node* pMove = (Node*)malloc(sizeof(Node));
		pMove = Q->front->next;
		if (pMove->next == NULL)
		{
			Q->rear = Q->front;
		}
		if (pMove)
		{
			Q->front->next = pMove->next;
			free(pMove);
			Q->length--;
		}
		return TRUE;
	}
	return FALSE;
}


void ClearLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		return;
	}
	else
	{
		while (DeLQueue(Q));
	}
}

Status TraverseLQueue(const LQueue* Q, void(*foo)(void* q,int datasize))
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	else
	{
		Node* pMove = Q->front->next;
		while (pMove)
		{
			foo(pMove->data, pMove->datasize);
			pMove = pMove->next;
		}
		printf("\n");
	}
	return TRUE;
}

void LPrint(void* q,int datasize)
{
	if (datasize == sizeof(int))
	{
		printf("%d  ", *(int*)q);
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
