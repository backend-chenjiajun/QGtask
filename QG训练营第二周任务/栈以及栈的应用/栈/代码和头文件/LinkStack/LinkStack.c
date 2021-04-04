#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

/**
 *  @name        : Status initLStack(LinkStack* s)
 *	@description : initialize a LinkStack
 *	@param		 : s
 *	@return		 : Status
 *  @notice      : None
 */
Status initLStack(LinkStack* s)
{

	if (s)
	{
		s->top = NULL; //��topָ��ָ���
		s->count = 0;//coount��ʼ��Ϊ0
		return SUCCESS;
	}
	return ERROR;

}


/**
 *  @name        : Status isEmptyLStack(LinkStack* s)
 *	@description : Determine whether the Linkstack is empty
 *	@param		 : s
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmptyLStack(LinkStack* s)
{
	if (s)
	{
		if (s->top)
			printf("ջ��Ϊ�գ�\n");
		else
			printf("ջΪ�գ�\n");
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
	
}

/**
 *  @name        : Status getTopLStack(LinkStack* s, ElemType* e)
 *	@description : get the top stack and and assign its value to e
 *	@param		 : s,e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (s)
	{
		if (s->top)
		{
			*e = s->top->data;          //����ʱtopָ���ջԪ�ظ�ֵ��*e
			printf("ջ����Ԫ��Ϊ %d\n",*e);
		}
		else
			printf("ջΪ�գ�\n");
		return SUCCESS;
	}
	else
		return ERROR;


}

/**
 *  @name        : Status clearLStack(LinkStack* s)
 *	@description : clear Linkstack
 *	@param		 : s
 *	@return		 : Status
 *  @notice      : None
 */
Status clearLStack(LinkStack* s)
{
	if (s)
	{
		LinkStackPtr p = s->top; //����ָ��ָ��topָ���ջ���
		while (s->top)
		{
			s->top = s->top->next; //top������
			s->count--;       //count��1
			free(p);       //�ͷ�pָ��Ľ��
			p = s->top;
		}
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

/**
 *  @name        : Status destroyLStack(LinkStack* s)
 *	@description : destroy a stack, free all
 *	@param		 : s
 *	@return		 : Status
 *  @notice      : None
 */
Status destroyLStack(LinkStack* s)
{
	if (s)
	{
		clearLStack(s);
		printf("�ݻ���ջ�ɹ���\n");
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}

}

/**
 *  @name        : Status LStackLength(LinkStack* s, int* length)
 *	@description : get the stacklength
 *	@param		 : s,length
 *	@return		 : Status
 *  @notice      : None
 */
Status LStackLength(LinkStack* s, int* length)
{
	if (s)
	{
		*length = s->count;
		return SUCCESS;
	}
	else
		return ERROR;

}

/**
 *  @name        : Status pushLStack(LinkStack* s, ElemType data)
 *	@description : push stack
 *	@param		 : s,data
 *	@return		 : Status
 *  @notice      : None
 */
Status pushLStack(LinkStack* s, ElemType data)
{
	
	if (s)
	{
		LinkStackPtr p = (StackNode*)malloc(sizeof(StackNode)); //�����½��
		if (p) 
		{
			p->data = data;  //��data��ֵ��p���data
			p->next = s->top;//pָ��top�Ľ��
			s->top = p;
			s->count++;   //count��һ

		}
		else
		{
			printf("��ջʧ�ܣ�\n");
		}
		return SUCCESS;
		
	}
	else
	{
		return ERROR;
	}
	


}

/**
 *  @name        : Status popLStack(LinkStack* s, ElemType* data)
 *	@description : popstack
 *	@param		 : s,data
 *	@return		 : Status
 *  @notice      : None
 */
Status popLStack(LinkStack* s, ElemType* data)
{
	if (s)
	{
		if (s->top)
		{
			LinkStackPtr p = s->top;
			*data = p->data;
			printf("��ջ�ɹ�����ջ��Ԫ��Ϊ%d\n", *data);
			s->top = s->top->next;
			s->count--;
			free(p);
		}
		else
		{
			printf("ջΪ�գ���ջʧ�ܣ�\n");
		}
		return SUCCESS;
	}
	return ERROR;
}
