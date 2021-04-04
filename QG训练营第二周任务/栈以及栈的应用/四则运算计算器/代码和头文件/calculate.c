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
			*e = s->top->data;          //����ʱtopָ���ջԪ�ظ�ֵ��*e
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
	int countMark1 = 0; //��¼ �� ���ֵĴ���
	int countMark2 = 0; //��¼  ) ���ֵĴ���
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

	//������ֻ��һ���ַ����ַ�Ϊ#���˳�����
	if (i == 1 && data[0] == '#')
		exit(0);

	//��������׸��ַ� Ϊ�����ַ� ���� �ǼӼ��ַ� ���� �������򷵻�0
	if ((data[0] == '\0' || (Priority(data[0]) != 2 && Priority(data[0]) != 4)) && (data[0] > '9' || data[0] < '0'))
		return 0;

	//�ж�������ַ��Ƿ񺬷Ƿ�����
	for (t = 0; t < i; t++)
	{

		//�������Ϊ�����ֻ��߷�����������򷵻�0
		if ((data[t] > '9' || data[t] < '0') && isOp(data[t]) == 0)
		{
			return 0;
		}

		if ((data[t] < '9' && data[t] >= '0')&& (data[t+1] < '9' && data[t+1] >= '0'))
		{
			printf("SORRY��������ʱ�������ݲ�֧����λ�������ϵ����㡣\n");
			return 0;
		}

		//�жϵ�ǰһ���ַ����һ���ַ�Ϊ���ֺ������ʱ
		if (isOp(data[t]) == 0 && isOp(data[t + 1]) != 0)
		{
			if (data[t + 1] == '(')    //��ǰһ��Ϊ���ֺ�һ��Ϊ�ַ�'(' �򷵻�0    ���� �� 5(6+5) �������������
				return 0;
		}		
		if (isOp(data[t]) != 0 && isOp(data[t + 1]) == 0 && t != i - 1)
		{
			if (data[t] == ')')  //��ǰһ��Ϊ�ַ�')'��һ��Ϊ�����򷵻�0       ���� : (6+5)5      
				return 0;
			if (data[t] == '/' && data[t + 1] == '0')
			{
				printf("��������/0�������㣡\n");
				return 0;
			}


		}

		//��ǰ�������ַ���Ϊ�����ʱ
		if (isOp(data[t]) && isOp(data[t + 1]))
		{
			if (data[t] == '(' && data[t + 1] == ')')          //ǰһ���ַ�Ϊ'('��һ���ַ�Ϊ')'����0 
				return 0;

			if (data[t] == ')' && data[t + 1] == '(')        //ǰһ���ַ�Ϊ')'��һ���ַ�Ϊ'('����0 
				return 0;

			if (data[t] != ')' && data[t + 1] == ')')         //ǰһ���ַ�Ϊ��Ϊ')'��һ���ַ�Ϊ')'����0 
				return 0;

			if (data[t] == '(' && (data[t + 1] != '(' && data[t + 1] != '-'))
				return 0;
			if ((Priority(data[t]) == 2 || Priority(data[t]) == 3) && (Priority(data[t + 1]) == 2 || Priority(data[t + 1]) == 3))  //��ǰ���ַ���Ϊ���������ʱ����0
				return 0;
		}
		if (isOp(data[i - 1]))
			if (data[i - 1] != ')')
				return 0;

	}

	//�ж�����ı��ʽ�� '(' �� ')' �����Ƿ�ƥ��
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
	printf("***********************��ӭʹ�á��Ʋ��桱�������������***************************\n");
	printf("*                                                                                *\n");
	printf("*            ��ܰ��ʾ�� 1�� ��ʹ��Ӣ�����뷨�����ַ�~~~~                         *\n");
	printf("*                       2�� ����  #   �˳�����                                 *\n");
	printf("*                       3����ʱ��֧�ֶ�λ�������ϵļ���                          *\n");
	printf("*	                4�������õ�����������������ȡ��                          *\n");
	printf("*	                5���������뵥�����ֵĽ���ʾΪ0                           *\n");
	printf("*********************************************************************************\n");
	printf("*********************************************************************************\n");
	printf("************************          ������          *******************************\n");
	printf("������ �Ӽ��˳� ������ʽ��\n");

}

//����׺���ʽת��Ϊ��׺���ʽ
void ConvertToSuffix(LinkStack* s, char* n, char* temp)
{
	ElemType e;
	int i = 0;
	int t = 0;
	int aban;
	int bridge;//����������ӳ�ջʱ


	for (i = 0; n[i] != '\0'; i++)
	{

		if (isOp(n[i]) == 1)//��Ϊ�����
		{
			if (n[i] == '(')//�����ţ�ֱ����ջ
			{
				pushLStack(s, (int)n[i]);
				continue;
			}
			if (n[i] == ')')//�����ţ���ջ�����������ջ����ջ�ٳ�ջ��ֱ�������š����Ų������
			{
				getTopLStack(s, &e);
				while (e != '(')
				{
					popLStack(s, &bridge);
					temp[t] = bridge;
					t++;
					getTopLStack(s, &e);
				}
				popLStack(s, &aban);//�������ų�ջ
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
				pushLStack(s, (int)n[i]);// ���֣�ֱ�����.

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
	/*printf("t��ֵ��--%d", t);
	system("pause");
	temp[t] = '\0';*/

	printf("��׺���ʽΪ��");
	for (i = 0; temp[i]!='\0'; i++)
	{
		printf("%c", temp[i]);
   }
	printf("\n");
	system("pause");

	
}


//����׺���ʽ��ֵ
void getValue(LinkStack* s, char* suffix)
{
	int front = 0;//��¼��������ʱ��ջ�ĵڶ�����
	int after = 0;//��¼��������ʱ��ջ�ĵ�һ����
	int i = 0;

		for (i = 0; suffix[i] != '\0'; i++)
		{
			if (isOp(suffix[i]))//��Ϊ�����
			{
				
				popLStack(s, &after); //��ջ����ֵ����after
				if (s->count == 0)
				{
					front = 0;       //����ǰջ����Ԫ�أ���frontΪ0
				}
				else
				{
					popLStack(s, &front);//�����ջ����ֵ����front
				}
				if (Calculation(&front, suffix[i], &after)) //�Գ�ջ������������
				{
					pushLStack(s, front);//���������ٽ�ջ
				}
					
					
			}
			else
			{
				pushLStack(s, suffix[i]-'0'); //��Ϊ�����������ջ
			}
		}
		printf("���Ϊ��%d\n", front);
		system("pause");


}


