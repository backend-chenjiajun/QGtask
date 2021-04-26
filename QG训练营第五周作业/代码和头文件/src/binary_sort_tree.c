#include"binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>


//链栈结构
typedef  struct StackNode
{
	NodePtr node;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//链式队列结构
typedef struct Qnode
{
	NodePtr node;            //数据域指针
	struct Qnode* next;       //指向当前结点的下一结点
} QNode;

typedef struct Lqueue
{
	QNode* front;                   //队头
	QNode* rear;                    //队尾
	size_t length;            //队列长度

} LQueue;


//链栈的相关操作

//初始化栈
Status initLStack(LinkStack* s)
{

	if (s)
	{
		s->top = NULL; //将top指针指向空
		s->count = 0;//coount初始化为0
		return succeed;
	}
	return failed;

}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s)
{
	if (s)
	{
		if (s->count == 0)
		{
			return succeed;
		}
		
	}
		return failed;

}
//得到栈顶元素
NodePtr getTopLStack(LinkStack* s)
{
	if (s)
	{
		if (!isEmptyLStack(s))
		{
			
			return s->top->node;     

		}
		else
			printf("栈为空！\n");
		return NULL;
	}
	else
		return NULL;


}
//清空栈
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
		return succeed;
	}
	else
	{
		return failed;
	}
}
//入栈
Status pushLStack(LinkStack* s, NodePtr node)
{

	if (s)
	{
		LinkStackPtr p = (StackNode*)malloc(sizeof(StackNode)); //创建新结点
		if (p)
		{
			p->node = node;
			p->next = s->top;//p指向top的结点
			s->top = p;
			s->count++;   //count加一

		}
		else
		{
			printf("入栈失败！\n");
		}
		return succeed;

	}
	else
	{
		return failed;
	}



}
//出栈
Status popLStack(LinkStack* s)
{
	if (s)
	{
		if (s->top)
		{
			LinkStackPtr p = s->top;
			s->top = s->top->next;
			s->count--;
			free(p);
		}
		else
		{
			printf("栈为空！出栈失败！\n");
		}
		return succeed;
	}
	return failed;
}

//队列的相关操作

//初始化队列
void InitLQueue(LQueue* Q)
{
	QNode* head = (QNode*)malloc(sizeof(QNode));
	if (head)
	{
		head->next = NULL;
		Q->front = Q->rear = head;
		Q->front->node = Q->rear->node = NULL;
		Q->length = 0;
	}
}
//判断队列是否为空
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length == 0)
		return succeed;
	return failed;
}
//入队
Status EnLQueue(LQueue* Q, NodePtr node)
{
	QNode* pMove = (QNode*)malloc(sizeof(QNode));
	if (!pMove)
		return failed;
	else
	{

		pMove->next = NULL;
		pMove->node = node;
		Q->rear->next = pMove;
		Q->rear = pMove;
		Q->length++;
		return succeed;
	}


}
//出队
Status DeLQueue(LQueue* Q)
{
	if (!IsEmptyLQueue(Q))
	{
		QNode* pMove = (QNode*)malloc(sizeof(QNode));
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
		return succeed;
	}
	return failed;
}
//清空队列
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
//摧毁队列
void DestoryLQueue(LQueue* Q)
{
	ClearLQueue(Q);
	free(Q->front);
}
//得到队列头元素
Status GetHeadLQueue(LQueue* Q,NodePtr* node)
{
	if (IsEmptyLQueue(Q))
	{
		return false;
	}
	else
	{
		*node = Q->front->next->node;
		return true;
	}

}




BST_Status BST_init(BinarySortTreePtr BST)
{
	BST->root= (Node *)malloc(sizeof(Node));
	if (BST->root)
	{
		BST->root->left = NULL;
		BST->root->right = NULL;
		return succeed;
	}

	return failed;

}

BST_Status BST_insert(BinarySortTreePtr BST, ElemType e)
{
	//如果树为空
	if (BST->root == NULL)
	{
		//先初始化
		BST_init(BST);
		//将e赋值给value
		if (BST->root)
		{
			BST->root->value = e;
			return true;
		}
		return false;
	}
	//查找e在树中是否存在
	else 
	{
		if (BST_search(BST,e)) 
		{
			printf("插入失败，该值在树中已经存在！");
			return false;
		}

		//初始化结点
		NodePtr newNode = (NodePtr)malloc(sizeof(Node));
		if (newNode)
		{
			newNode->left = newNode->right = NULL;
			newNode->value = e;
		}
		else
		{
			return false;
		}
		//找出要插入的结点的父节点
		NodePtr p = BST->root;
		while (1)
		{

			//如果e值小于当前结点
			if (p->value > e)
			{
				if (p->left)
				{
					p = p->left;
				}
				else
				{
					printf("插入为父节点为 %d 的左孩子\n ", p->value);
					p->left = newNode;
					break;
				}
				
				
			}
			//e值大于当前结点
			else
			{
				if (p->right)
				{
					p = p->right;
				}
				else
				{
					printf("插入为父节点为 %d 的右孩子\n ", p->value);
					p->right = newNode;
					break;
				}
				
			}
		}

	}

	return true;
}

BST_Status BST_delete(BinarySortTreePtr BST, ElemType e)
{

	if (BST->root)
	{
		if (BST->root->left == NULL && BST->root->right == NULL)
		{
			if (BST->root->value == e)
			{
				free(BST->root);
				BST->root = NULL;
				return true;
			}
			else
			{
				printf("删除失败，该值不存在！\n");
			}

		}
		else
		{
			if (BST_search(BST, e))
			{
				NodePtr p = BST->root;
				NodePtr pFront = p;
				//找出e所在的结点
				while (p->value != e)
				{
					pFront = p;
					//当value大于e时，p指向p的左孩子
					if (p->value > e)
					{
						p = p->left;
					}
					//当value小于e时，p指向p的右孩子
					else if (p->value < e)
					{
						p = p->right;
					}
				}


				//如果该节点没有孩子
				if (!p->right && !p->left)
				{
					//如果p是pFront的左孩子
					if (p == pFront->left)
					{
						pFront->left = NULL;
					}
					//p是pFront的右孩子
					else
					{
						pFront->right = NULL;
					}
				}
				//该结点有孩子
				else
				{
					//该节点左右孩子都存在
					if (p->right && p->left)
					{
						//找到左孩子族的最右结点
						NodePtr mostRight = p->left;
						NodePtr mostRightFront = mostRight;
						while (mostRight->right)
						{
							mostRightFront = mostRight;
							mostRight = mostRight->right;
						}
						if (mostRight == p->left)
						{
							p->value = mostRight->value;
							p->left = mostRight->left;

						}
						else
						{
							//将左孩子族的最右结点赋值给p的value
							p->value = mostRight->value;
							//将左孩子族最右结点删除
							mostRightFront->right = NULL;
						
						}
						free(mostRight);
						return true;
					
					}
					//如果p只有一个孩子
					else if (p->left || p->right)
					{
						//如果p只有左孩子
						if (p->left)
						{
							//如果删除的结点是头结点
							if (p == BST->root)
							{
								p = p->left;
								BST->root->value = p->value;
								BST->root->left = NULL;
							}
							else
							{
								//如果p是pFront的左孩子
								if (p == pFront->left)
								{
									pFront->left = p->left;

								}
								//p是pFront的右孩子
								else
								{
									pFront->right = p->left;
								}
							}
						
						}
						//如果p只有右孩子
						else
						{
							//如果删除的结点是头结点
							if (p == BST->root)
							{
								p = p->right;
								BST->root->value = p->value;
								BST->root->right = NULL;
							}
							else
							{
								//如果p是pFront的左孩子
								if (p == pFront->left)
								{
									pFront->left = p->right;

								}
								//p是pFront的右孩子
								else
								{
									pFront->right = p->right;
								}
							}
						
						}
					}
				}
				//释放p结点
				free(p);
				return true;
			}
			else
			{
				printf("删除失败，该值不存在！\n");
			}
		}
	}
	else
	{
		printf("树为空！\n");
	}
	return false;
}

BST_Status BST_search(BinarySortTreePtr BST, ElemType e)
{
	NodePtr p = BST->root;
		//当p为空时停止循环
		while (p)
		{
			//当value等于e时，返回true表示找到e
			if (p->value == e)
			{
				return true;
			}
			//当value大于e时，p指向p的左孩子
			if (p->value > e)
			{
				p = p->left;
			}
			//当value小于e时，p指向p的右孩子
			else
			{
				p = p->right;
			}
		}
	
	return false;
}


BST_Status BST_preorderI(BinarySortTreePtr BST, void(*visit)(NodePtr))
{
	if (BST->root)
	{
		//创建链栈并初始化
		LinkStack s;
		initLStack(&s);
		NodePtr node = BST->root;
		//当栈不为空时进行循环
		while (!isEmptyLStack(&s)||node)
		{
			if (node)
			{
				pushLStack(&s,node);
				visit(node);
				node = node->left;
			}
			else
			{
			   node = getTopLStack(&s);
				if (node)
				{
					node = node->right;
				}
				popLStack(&s);
			
			}
		}

		return true;
	}
	else
	{
		printf("树为空！\n");
		return false;
	}
}
void preorderR(NodePtr node, void(*visit)(NodePtr))
{
	if (node)
	{
		visit(node);
		preorderR(node->left, visit);
		preorderR(node->right, visit);
	}
	else
	{
		return;
	}

}
BST_Status BST_preorderR(BinarySortTreePtr BST, void(*visit)(NodePtr ))
{
	if (BST->root)
	{
		preorderR(BST->root, visit);
		return true;
	}
	else
	{
		printf("树为空！\n");
		return false;
	}
}


BST_Status BST_inorderI(BinarySortTreePtr BST, void(*visit)(NodePtr))
{
	if (BST->root)
	{
		//创建链栈并初始化
		LinkStack s;
		initLStack(&s);

		NodePtr node = BST->root;
		//当栈不为空时进行循环
		while (!isEmptyLStack(&s)||node)
		{
			//当node不为空时
			if (node)
			{
				//入栈
				pushLStack(&s, node);
				node = node->left;
			}
			else
			{
				//获得当前栈顶
				node = getTopLStack(&s);
				visit(node);
				//访问右孩子
				node = node->right;
				//退栈
				popLStack(&s);

				
			}


		}

		return true;
	}
	else
	{
		printf("树为空！\n");
		return false;
	}
}
void inorderR(NodePtr node, void(*visit)(NodePtr))
{
	if (node)
	{
		inorderR(node->left, visit);
		visit(node);
		inorderR(node->right, visit);
	}
	else
	{
		return;
	}
}
BST_Status BST_inorderR(BinarySortTreePtr BST, void(*visit)(NodePtr ))
{
	if (BST->root)
	{
		inorderR(BST->root, visit);
		return true;
	}
	else
	{
		printf("树为空！\n");
		return false;
	}
}


BST_Status BST_postorderI(BinarySortTreePtr BST, void(*visit)(NodePtr ))
{
	if (BST->root)
	{
		//创建链栈并初始化
		LinkStack s;
		initLStack(&s);

		//遍历指针
		NodePtr node = NULL;
		//记录已经遍历过的结点
		NodePtr flag = BST->root;

		//将头结点入栈
		pushLStack(&s, BST->root);
		while (!isEmptyLStack(&s))
		{
			//得到栈顶
			 node = getTopLStack(&s);
		
			 if (node)
			 {
				 //当前点左孩子和右孩子都为空或flag记录的是node的左孩子或右孩子时
				 if ((node->left==NULL && node->right==NULL) || (flag == node->left || flag == node->right))
				 {
					 //打印
					 visit(node);
					 //出栈
					 popLStack(&s);
					 //记录
					 flag = node;
				 }
				 else
				 {
					 //如果node右孩子不为空
					 if (node->right)
					 {
						 //入栈
						 pushLStack(&s, node->right);
					 }
					 //如果左孩子不为空
					 if (node->left)
					 {
						 //入栈
						 pushLStack(&s, node->left);
					 }
				 }
			 }
			
		}

		return true;
	}
	else
	{
		printf("树为空！\n");
		return false;
	}
}
void postorderR(NodePtr node, void(*visit)(NodePtr))
{
	if (node)
	{
		postorderR(node->left, visit);
		postorderR(node->right, visit);
		visit(node);
	}
	else
	{
		return;
	}


}
BST_Status BST_postorderR(BinarySortTreePtr BST, void(*visit)(NodePtr ))
{
	if (BST->root)
	{
		postorderR(BST->root, visit);
		return true;
	}
	else
	{
		printf("树为空！\n");
		return false;
	}
	
}

//
BST_Status BST_levelOrder(BinarySortTreePtr BST, void(*visit)(NodePtr))
{
	if (BST->root)
	{
		//初始化队列
		LQueue Q;
		InitLQueue(&Q);
		//头结点入列
		EnLQueue(&Q, BST->root);
		//遍历指针
		NodePtr node = NULL;
		while (!IsEmptyLQueue(&Q))
		{
			//得到队列头元素
			 GetHeadLQueue(&Q,&node);

			 if (node)
			 {
				 visit(node);
				 //头结点出列
				 DeLQueue(&Q);
				 //如果node有左孩子，左孩子入列
				 if (node->left)
				 {
					 EnLQueue(&Q, node->left);
				 }
				 //如果node有右孩子，右孩子入列
				 if (node->right)
				 {
					 EnLQueue(&Q, node->right);
				 }
			 }
			
		}

		//摧毁队列
		DestoryLQueue(&Q);
		return true;
	}
	else
	{
		printf("树为空！\n");
		return false;
	}
}



