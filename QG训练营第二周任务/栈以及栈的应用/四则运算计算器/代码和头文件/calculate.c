#include "calculate.h"
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
			return SUCCESS;
		else
			return ERROR;
		
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
		}
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
			return SUCCESS;
		}
		return ERROR;

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
			s->top = s->top->next;
			s->count--;
			free(p);
			return SUCCESS;
		}
		return ERROR;
	}
	return ERROR;
}

/**
 *  @name        : int Priority(char s)
 *	@description : Judge operator level and return the level
 *	@param		 : op
 *	@return		 : int
 *  @notice      : None
 */
int Priority(char op)
{
	switch (op) 
	{
	case '+':

	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
		return 4;
	case ')':
		return 1;
	default:
		return 0;

	}


	return 0;
}

/**
 *  @name        : int Precede(char op1, char op2)
 *	@description : Comparison operator level
 *	@param		 : op1,op2
 *	@return		 : int
 *  @notice      : if op1 > op2 return 1;
 */
int Precede(char op1, char op2)
{
	if (Priority(op1) > Priority(op2))
		return 1;
		
	return 0;
}


/**
 *  @name        : int isOp(char op)
 *	@description : Jude  operator 
 *	@param		 : op
 *	@return		 : int
 *  @notice      : none
 */
int isOp(char op)
{
	if (op == '(' || op == ')' || op == '+' || op == '-' || op == '*' || op == '/')
		return 1;
	return 0;
}


/**
 *  @name        : Status Calculation(int *front, char op, int *after )
 *	@description : Judge operators and perform operations
 *	@param		 : *front ,op, *after
 *	@return		 : Status
 *  @notice      : none
 */
Status Calculation(int *front, char op, int *after )
{
	switch (op)
	{
	case '+':
		 *front = *front + *after;
		 return SUCCESS;
	case '-':
		*front = *front - *after;
		return SUCCESS;
	case '*':
		*front = *front * *after; 
		return SUCCESS;
	case '/':
		*front = *front / *after;
		return SUCCESS;
	default:
		return ERROR;
	}
}


/**
 *  @name        : int dataScan(char* data)
 *	@description : Judge the data whether it is illegal input
 *	@param		 : * data
 *	@return		 : int
 *  @notice      : none
 */
int dataScan(char* data)
{
	int i = 0;
	int t = 0;
	int countMark1 = 0; //记录 （ 出现的次数
	int countMark2 = 0; //记录  ) 出现的次数
	char ch;
	ch = getchar();

	while (ch != '\n')
	{
		data[i] = ch;
		ch = getchar();
		fflush(stdin);
		i++;
	}
	data[i] = '\0';

	//若输入只有一个字符且字符为#则退出程序
	if (i == 1 && data[0] == '#')
		exit(0);

	//若输入的首个字符 为换行字符 或者 非加减字符 或者 非数字则返回0
	if ((data[0] == '\0' || (Priority(data[0]) != 2 && Priority(data[0]) != 4)) && (data[0] > '9' || data[0] < '0'))
		return 0;

	//判断输入的字符是否含非法输入
	for (t = 0; t < i; t++)
	{

		//若输入的为非数字或者非四则运算符则返回0
		if ((data[t] > '9' || data[t] < '0') && isOp(data[t]) == 0)
		{
			return 0;
		}

		if ((data[t] < '9' && data[t] >= '0')&& (data[t+1] < '9' && data[t+1] >= '0'))
		{
			printf("SORRY，技术和时间有限暂不支持两位数或以上的运算。\n");
			return 0;
		}

		//判断当前一个字符与后一个字符为数字和运算符时
		if (isOp(data[t]) == 0 && isOp(data[t + 1]) != 0)
		{
			if (data[t + 1] == '(')    //若前一个为数字后一个为字符'(' 则返回0    比如 ： 5(6+5) 不符合运算规则
				return 0;
		}		
		if (isOp(data[t]) != 0 && isOp(data[t + 1]) == 0 && t != i - 1)
		{
			if (data[t] == ')')  //若前一个为字符')'后一个为数字则返回0       比如 : (6+5)5      
				return 0;
			if (data[t] == '/' && data[t + 1] == '0')
			{
				printf("请勿输入/0进行运算！\n");
				return 0;
			}


		}

		//当前后两个字符均为运算符时
		if (isOp(data[t]) && isOp(data[t + 1]))
		{
			if (data[t] == '(' && data[t + 1] == ')')          //前一个字符为'('后一个字符为')'返回0 
				return 0;

			if (data[t] == ')' && data[t + 1] == '(')        //前一个字符为')'后一个字符为'('返回0 
				return 0;

			if (data[t] != ')' && data[t + 1] == ')')         //前一个字符为不为')'后一个字符为')'返回0 
				return 0;

			if (data[t] == '(' && (data[t + 1] != '(' && data[t + 1] != '-'))
				return 0;
			if ((Priority(data[t]) == 2 || Priority(data[t]) == 3) && (Priority(data[t + 1]) == 2 || Priority(data[t + 1]) == 3))  //当前后字符均为四则运算符时返回0
				return 0;
		}
		if (isOp(data[i - 1]))
			if (data[i - 1] != ')')
				return 0;

	}

	//判断输入的表达式中 '(' 和 ')' 数量是否匹配
	for (t = 0; t < i; t++)
	{
		if (data[t] == '(')
			countMark1++;
		if (data[t] == ')')
			countMark2++;

		if (countMark2 > countMark1)
			return 0;
	}
	if (countMark1 != countMark2)
		return 0;

	return 1;
}

/**
 *  @name        : void view()
 *	@description : view
 *	@param		 : none
 *	@return		 : void
 *  @notice      : none
 */
void view()
{
	printf("***********************欢迎使用“破产版”四则运算计算器***************************\n");
	printf("*                                                                                *\n");
	printf("*            温馨提示： 1、 请使用英文输入法输入字符~~~~                         *\n");
	printf("*                       2、 输入  #   退出程序！                                 *\n");
	printf("*                       3、暂时不支持二位数或以上的计算                          *\n");
	printf("*	                4、若所得的商有余数，会往下取整                          *\n");
	printf("*	                5、所有输入单个数字的皆显示为0                           *\n");
	printf("*********************************************************************************\n");
	printf("*********************************************************************************\n");
	printf("************************          运算区          *******************************\n");
	printf("请输入 加减乘除 运算表达式：\n");

}

//将中缀表达式转化为后缀表达式
void ConvertToSuffix(LinkStack* s, char* n, char* temp)
{
	ElemType e;
	int i = 0;
	int t = 0;
	int aban;
	int bridge;//用于运算符从出栈时


	for (i = 0; n[i] != '\0'; i++)
	{

		if (isOp(n[i]) == 1)//若为运算符
		{
			if (n[i] == '(')//左括号，直接入栈
			{
				pushLStack(s, (int)n[i]);
				continue;
			}
			if (n[i] == ')')//右括号，将栈顶的运算符出栈，出栈再出栈，直到左括号。括号不作输出
			{
				getTopLStack(s, &e);
				while (e != '(')
				{
					popLStack(s, &bridge);
					temp[t] = bridge;
					t++;
					getTopLStack(s, &e);
				}
				popLStack(s, &aban);//将左括号出栈
				continue;
			}
			if (s->count != 0)
			{
				getTopLStack(s, &e);
				if (Precede(n[i], e))
				{
					pushLStack(s, (int)n[i]);
					continue;
				}
				else
				{
					while (Precede(n[i], e) == 0 && e != '(')
					{
						popLStack(s, &bridge);
						temp[t] = bridge;
						t++;
						getTopLStack(s, &e);
						if (s->count == 0 || e == '(')
							break;
					}
					pushLStack(s, (int)n[i]);

					continue;

				}
			}
			else
			{
				pushLStack(s, (int)n[i]);// 数字，直接输出.

				continue;
			}

		}
		else
		{
			temp[t] = n[i];
			t++;
		}
			

	}
	while (s->count!=0)
	{
		popLStack(s, &bridge);
		temp[t] = bridge;
		t++;
	}
	/*printf("t的值是--%d", t);
	system("pause");
	temp[t] = '\0';*/

	printf("后缀表达式为：");
	for (i = 0; temp[i]!='\0'; i++)
	{
		printf("%c", temp[i]);
   }
	printf("\n");
	system("pause");

	
}


//将后缀表达式求值
void getValue(LinkStack* s, char* suffix)
{
	int front = 0;//记录进行运算时出栈的第二个数
	int after = 0;//记录进行运算时出栈的第一个数
	int i = 0;

		for (i = 0; suffix[i] != '\0'; i++)
		{
			if (isOp(suffix[i]))//若为运算符
			{
				
				popLStack(s, &after); //出栈并将值赋给after
				if (s->count == 0)
				{
					front = 0;       //若当前栈中无元素，则front为0
				}
				else
				{
					popLStack(s, &front);//否则出栈并将值赋给front
				}
				if (Calculation(&front, suffix[i], &after)) //对出栈的数进行运算
				{
					pushLStack(s, front);//将运算结果再进栈
				}
					
					
			}
			else
			{
				pushLStack(s, suffix[i]-'0'); //若为非运算符则入栈
			}
		}
		printf("结果为：%d\n", front);
		system("pause");


}


