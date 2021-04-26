#include"binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>


//��ջ�ṹ
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

//��ʽ���нṹ
typedef struct Qnode
{
	NodePtr node;            //������ָ��
	struct Qnode* next;       //ָ��ǰ������һ���
} QNode;

typedef struct Lqueue
{
	QNode* front;                   //��ͷ
	QNode* rear;                    //��β
	size_t length;            //���г���

} LQueue;


//��ջ����ز���

//��ʼ��ջ
Status initLStack(LinkStack* s)
{

	if (s)
	{
		s->top = NULL; //��topָ��ָ���
		s->count = 0;//coount��ʼ��Ϊ0
		return succeed;
	}
	return failed;

}

//�ж�ջ�Ƿ�Ϊ��
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
//�õ�ջ��Ԫ��
NodePtr getTopLStack(LinkStack* s)
{
	if (s)
	{
		if (!isEmptyLStack(s))
		{
			
			return s->top->node;     

		}
		else
			printf("ջΪ�գ�\n");
		return NULL;
	}
	else
		return NULL;


}
//���ջ
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
		return succeed;
	}
	else
	{
		return failed;
	}
}
//��ջ
Status pushLStack(LinkStack* s, NodePtr node)
{

	if (s)
	{
		LinkStackPtr p = (StackNode*)malloc(sizeof(StackNode)); //�����½��
		if (p)
		{
			p->node = node;
			p->next = s->top;//pָ��top�Ľ��
			s->top = p;
			s->count++;   //count��һ

		}
		else
		{
			printf("��ջʧ�ܣ�\n");
		}
		return succeed;

	}
	else
	{
		return failed;
	}



}
//��ջ
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
			printf("ջΪ�գ���ջʧ�ܣ�\n");
		}
		return succeed;
	}
	return failed;
}

//���е���ز���

//��ʼ������
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
//�ж϶����Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length == 0)
		return succeed;
	return failed;
}
//���
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
//����
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
//��ն���
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
//�ݻٶ���
void DestoryLQueue(LQueue* Q)
{
	ClearLQueue(Q);
	free(Q->front);
}
//�õ�����ͷԪ��
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
	//�����Ϊ��
	if (BST->root == NULL)
	{
		//�ȳ�ʼ��
		BST_init(BST);
		//��e��ֵ��value
		if (BST->root)
		{
			BST->root->value = e;
			return true;
		}
		return false;
	}
	//����e�������Ƿ����
	else 
	{
		if (BST_search(BST,e)) 
		{
			printf("����ʧ�ܣ���ֵ�������Ѿ����ڣ�");
			return false;
		}

		//��ʼ�����
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
		//�ҳ�Ҫ����Ľ��ĸ��ڵ�
		NodePtr p = BST->root;
		while (1)
		{

			//���eֵС�ڵ�ǰ���
			if (p->value > e)
			{
				if (p->left)
				{
					p = p->left;
				}
				else
				{
					printf("����Ϊ���ڵ�Ϊ %d ������\n ", p->value);
					p->left = newNode;
					break;
				}
				
				
			}
			//eֵ���ڵ�ǰ���
			else
			{
				if (p->right)
				{
					p = p->right;
				}
				else
				{
					printf("����Ϊ���ڵ�Ϊ %d ���Һ���\n ", p->value);
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
				printf("ɾ��ʧ�ܣ���ֵ�����ڣ�\n");
			}

		}
		else
		{
			if (BST_search(BST, e))
			{
				NodePtr p = BST->root;
				NodePtr pFront = p;
				//�ҳ�e���ڵĽ��
				while (p->value != e)
				{
					pFront = p;
					//��value����eʱ��pָ��p������
					if (p->value > e)
					{
						p = p->left;
					}
					//��valueС��eʱ��pָ��p���Һ���
					else if (p->value < e)
					{
						p = p->right;
					}
				}


				//����ýڵ�û�к���
				if (!p->right && !p->left)
				{
					//���p��pFront������
					if (p == pFront->left)
					{
						pFront->left = NULL;
					}
					//p��pFront���Һ���
					else
					{
						pFront->right = NULL;
					}
				}
				//�ý���к���
				else
				{
					//�ýڵ����Һ��Ӷ�����
					if (p->right && p->left)
					{
						//�ҵ�����������ҽ��
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
							//������������ҽ�㸳ֵ��p��value
							p->value = mostRight->value;
							//�����������ҽ��ɾ��
							mostRightFront->right = NULL;
						
						}
						free(mostRight);
						return true;
					
					}
					//���pֻ��һ������
					else if (p->left || p->right)
					{
						//���pֻ������
						if (p->left)
						{
							//���ɾ���Ľ����ͷ���
							if (p == BST->root)
							{
								p = p->left;
								BST->root->value = p->value;
								BST->root->left = NULL;
							}
							else
							{
								//���p��pFront������
								if (p == pFront->left)
								{
									pFront->left = p->left;

								}
								//p��pFront���Һ���
								else
								{
									pFront->right = p->left;
								}
							}
						
						}
						//���pֻ���Һ���
						else
						{
							//���ɾ���Ľ����ͷ���
							if (p == BST->root)
							{
								p = p->right;
								BST->root->value = p->value;
								BST->root->right = NULL;
							}
							else
							{
								//���p��pFront������
								if (p == pFront->left)
								{
									pFront->left = p->right;

								}
								//p��pFront���Һ���
								else
								{
									pFront->right = p->right;
								}
							}
						
						}
					}
				}
				//�ͷ�p���
				free(p);
				return true;
			}
			else
			{
				printf("ɾ��ʧ�ܣ���ֵ�����ڣ�\n");
			}
		}
	}
	else
	{
		printf("��Ϊ�գ�\n");
	}
	return false;
}

BST_Status BST_search(BinarySortTreePtr BST, ElemType e)
{
	NodePtr p = BST->root;
		//��pΪ��ʱֹͣѭ��
		while (p)
		{
			//��value����eʱ������true��ʾ�ҵ�e
			if (p->value == e)
			{
				return true;
			}
			//��value����eʱ��pָ��p������
			if (p->value > e)
			{
				p = p->left;
			}
			//��valueС��eʱ��pָ��p���Һ���
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
		//������ջ����ʼ��
		LinkStack s;
		initLStack(&s);
		NodePtr node = BST->root;
		//��ջ��Ϊ��ʱ����ѭ��
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
		printf("��Ϊ�գ�\n");
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
		printf("��Ϊ�գ�\n");
		return false;
	}
}


BST_Status BST_inorderI(BinarySortTreePtr BST, void(*visit)(NodePtr))
{
	if (BST->root)
	{
		//������ջ����ʼ��
		LinkStack s;
		initLStack(&s);

		NodePtr node = BST->root;
		//��ջ��Ϊ��ʱ����ѭ��
		while (!isEmptyLStack(&s)||node)
		{
			//��node��Ϊ��ʱ
			if (node)
			{
				//��ջ
				pushLStack(&s, node);
				node = node->left;
			}
			else
			{
				//��õ�ǰջ��
				node = getTopLStack(&s);
				visit(node);
				//�����Һ���
				node = node->right;
				//��ջ
				popLStack(&s);

				
			}


		}

		return true;
	}
	else
	{
		printf("��Ϊ�գ�\n");
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
		printf("��Ϊ�գ�\n");
		return false;
	}
}


BST_Status BST_postorderI(BinarySortTreePtr BST, void(*visit)(NodePtr ))
{
	if (BST->root)
	{
		//������ջ����ʼ��
		LinkStack s;
		initLStack(&s);

		//����ָ��
		NodePtr node = NULL;
		//��¼�Ѿ��������Ľ��
		NodePtr flag = BST->root;

		//��ͷ�����ջ
		pushLStack(&s, BST->root);
		while (!isEmptyLStack(&s))
		{
			//�õ�ջ��
			 node = getTopLStack(&s);
		
			 if (node)
			 {
				 //��ǰ�����Ӻ��Һ��Ӷ�Ϊ�ջ�flag��¼����node�����ӻ��Һ���ʱ
				 if ((node->left==NULL && node->right==NULL) || (flag == node->left || flag == node->right))
				 {
					 //��ӡ
					 visit(node);
					 //��ջ
					 popLStack(&s);
					 //��¼
					 flag = node;
				 }
				 else
				 {
					 //���node�Һ��Ӳ�Ϊ��
					 if (node->right)
					 {
						 //��ջ
						 pushLStack(&s, node->right);
					 }
					 //������Ӳ�Ϊ��
					 if (node->left)
					 {
						 //��ջ
						 pushLStack(&s, node->left);
					 }
				 }
			 }
			
		}

		return true;
	}
	else
	{
		printf("��Ϊ�գ�\n");
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
		printf("��Ϊ�գ�\n");
		return false;
	}
	
}

//
BST_Status BST_levelOrder(BinarySortTreePtr BST, void(*visit)(NodePtr))
{
	if (BST->root)
	{
		//��ʼ������
		LQueue Q;
		InitLQueue(&Q);
		//ͷ�������
		EnLQueue(&Q, BST->root);
		//����ָ��
		NodePtr node = NULL;
		while (!IsEmptyLQueue(&Q))
		{
			//�õ�����ͷԪ��
			 GetHeadLQueue(&Q,&node);

			 if (node)
			 {
				 visit(node);
				 //ͷ������
				 DeLQueue(&Q);
				 //���node�����ӣ���������
				 if (node->left)
				 {
					 EnLQueue(&Q, node->left);
				 }
				 //���node���Һ��ӣ��Һ�������
				 if (node->right)
				 {
					 EnLQueue(&Q, node->right);
				 }
			 }
			
		}

		//�ݻٶ���
		DestoryLQueue(&Q);
		return true;
	}
	else
	{
		printf("��Ϊ�գ�\n");
		return false;
	}
}



