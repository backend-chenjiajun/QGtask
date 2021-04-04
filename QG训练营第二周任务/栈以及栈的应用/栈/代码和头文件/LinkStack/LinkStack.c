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
		s->top = NULL; //将top指针指向空
		s->count = 0;//coount初始化为0
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
			printf("栈不为空！\n");
		else
			printf("栈为空！\n");
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
			*e = s->top->data;          //将此时top指向的栈元素赋值给*e
			printf("栈顶的元素为 %d\n",*e);
		}
		else
			printf("栈为空！\n");
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
		LinkStackPtr p = s->top; //创建指针指向top指向的栈结点
		while (s->top)
		{
			s->top = s->top->next; //top往后移
			s->count--;       //count减1
			free(p);       //释放p指向的结点
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
		printf("摧毁链栈成功！\n");
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
		LinkStackPtr p = (StackNode*)malloc(sizeof(StackNode)); //创建新结点
		if (p) 
		{
			p->data = data;  //将data赋值给p点的data
			p->next = s->top;//p指向top的结点
			s->top = p;
			s->count++;   //count加一

		}
		else
		{
			printf("入栈失败！\n");
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
			printf("出栈成功，出栈的元素为%d\n", *data);
			s->top = s->top->next;
			s->count--;
			free(p);
		}
		else
		{
			printf("栈为空！出栈失败！\n");
		}
		return SUCCESS;
	}
	return ERROR;
}
