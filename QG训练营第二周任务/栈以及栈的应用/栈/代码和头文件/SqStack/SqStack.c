#include"SqStack.h"
#include<stdio.h>
#include<stdlib.h>




/**
 *  @name        : tatus initStack(SqStack* s, int sizes)
 *	@description : initialize a Stack
 *	@param		 : s,size
 *	@return		 : Status
 *  @notice      : None
 */
Status initStack(SqStack* s, int sizes)
{
	//s = (SqStack*)malloc(sizeof(SqStack));
	if (s)
	{
		s->elem = (int*)malloc(sizeof(int)*sizes);
		s->top = -1;
		s->size = sizes;
	}
		
	if(s == NULL)
		return ERROR;
	return SUCCESS;
}


/**
 *  @name        : Status isEmptyStack(SqStack* s)
 *	@description : Determine whether the stack is empty
 *	@param		 : s
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmptyStack(SqStack* s)
{
	if(s)
	{
		if (s->top == -1)
		{
			printf("栈为空！\n");
		}
		else
			printf("栈为非空！\n");
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

/**
 *  @name        : Status getTopStack(SqStack* s, ElemType* e)
 *	@description : get the top stackand and assign its value to e
 *	@param		 : s,e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopStack(SqStack* s, ElemType* e)
{
	if (s)
	{
		if (s->top != -1)
		{
			*e = s->elem[s->top];
			printf("栈顶的元素为 ：%d\n", *e);
		}
		else {
			printf("该栈为空栈！\n");
		}
		return SUCCESS;
	}
	else
		return ERROR;
	
}

/**
 *  @name        : Status clearStack(SqStack* s)
 *	@description : clear stack
 *	@param		 : s
 *	@return		 : Status
 *  @notice      : None
 */
Status clearStack(SqStack* s)
{
	if (s)
	{
		s->top = -1;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

/**
 *  @name        : Status destroyStack(SqStack* s)
 *	@description : destroy a stack, free all 
 *	@param		 : s
 *	@return		 : Status
 *  @notice      : None
 */
Status destroyStack(SqStack* s)
{
	if (s)
	{
		s->top = -1;
		free(s->elem);
		return SUCCESS;
	}
	else
		return ERROR;

}

/**
 *  @name        : Status stackLength(SqStack* s, int* length)
 *	@description : get the stacklength
 *	@param		 : s,length
 *	@return		 : Status
 *  @notice      : None
 */
Status stackLength(SqStack* s, int* length)
{
	if (s)
	{
		*length = s->top+1;
		return SUCCESS;
	}
	else
		return ERROR;
}

/**
 *  @name        : Status pushStack(SqStack* s, ElemType data)
 *	@description : push stack
 *	@param		 : s,data
 *	@return		 : Status
 *  @notice      : None
 */
Status pushStack(SqStack* s, ElemType data)
{
	if (s)
	{
		if (s->top == s->size - 1)
		{
			printf("栈已满，入栈失败！\n");
		}
		else
		{
			s->top++;
			s->elem[s->top] = data;
			printf("入栈成功！\n");
		}
		return SUCCESS;
	}
	else
		return ERROR;
}

/**
 *  @name        : Status popStack(SqStack* s, ElemType* data)
 *	@description : popstack
 *	@param		 : s,data
 *	@return		 : Status
 *  @notice      : None
 */
Status popStack(SqStack* s, ElemType* data)
{
	if (s)
	{
		if (s->top != -1)
		{
			*data = s->elem[s->top];
			s->top--;
			printf("出栈成功！出栈的元素为 %d\n", *data);
		}
		else
			printf("栈已经为空，无法再进行出栈操作！\n");
		return SUCCESS;
	}
	else
		return ERROR;
}