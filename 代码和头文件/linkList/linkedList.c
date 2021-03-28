#include "linkedList.h"
#include <stdio.h>
#include<stdlib.h>



/*LNode* createList() {
	//����ͷ���LHeadNode 
	struct LNode* LHeadNode = (LNode*)malloc(sizeof(LNode));
	//��ͷ���ָ��� 
	if (LHeadNode)
		LHeadNode->next = NULL;
	return LHeadNode;
}*/

/**
 *  @name        : LNode* createNode(ElemType e);
 *	@description : create a new node
 *	@param		 : e
 *	@return		 : LNode*
 *  @notice      : None
 */





/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {       

	
	*L= (LinkedList)malloc(sizeof(LNode)); //����ͷ���ٿռ�
	if (*L) {
		(*L)->next = NULL;
		return SUCCESS;
	}
	else
		return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {           
	
	
	LNode* posNode = *L; //�������ָ��ָ��ͷ���
	
	while (posNode)        //��posNode��Ϊ��ʱ����ѭ��
	{
		
		posNode = (*L)->next;    //posNode�ƶ���ͷ�����һ�����
		
		free(*L);               //�ͷ�ͷ���
		
		*L = posNode;         //��posNodeΪͷ���
	}

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {        

	
	if (p && q)    //��p��q ����㶼��Ϊ��ʱ
	{
		LNode* posNode = p->next;     //����ָ��ָ��p����һ�����

		p->next = q;					//pָ��q
		q->next = posNode;				//qָ��posNode

		return SUCCESS;
	}
	else
		return ERROR;


}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {  
	
	
	LNode* posNode = p;       //�������ָ��ָ��p����һ�����
	
	
	if (posNode==NULL   ) {//�ж�posNode�Ƿ�Ϊ��
		return ERROR;
	}
	else if (posNode->next==NULL)
	{
		return ERROR;
	}
	else
	{
		posNode = posNode->next;
			
		*e = posNode->data;      //��posNode��ֵ����e
			
		p->next =posNode->next;//�����pָ��posNode����һ�����
			
			free(posNode);      //�ͷ�posNode���
		return SUCCESS;
	}
		
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) { 

	if (L==NULL)
	{
		printf("�������ڣ�\n");
	}
	else
	{
		LNode* posNode = L->next;  //����ָ��ָ��ͷ������һ�����

		while (posNode)
		{
			if (posNode->next == NULL)
			{
				printf("%d", posNode->data);
			}
			else
			{
				visit(posNode->data);
			}
			posNode = posNode->next;//ָ���ƶ�����һ����㴦
		}

	}
	

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {         
	int  i = 1;
	LNode* posNode = L->next; //����ָ��ָ��ͷ���L����һ�����
	
	while (posNode) {                //��posNode��Ϊ��ʱ����ѭ��
		
		if (posNode->data == e) 
		{//���posNode�е�ֵ����e ����SUCCESS����ʾ�ҵ����

			printf("�ý��Ϊ��%d�����\n",i);
			return SUCCESS;
		}
		
		posNode = posNode->next;     //posNodeָ����һ�����
		i++;
	}
	
	return ERROR;                        //��posNodeΪ��ʱ��ʾδ�ҵ���㣬����ERROR

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {             
	
	LNode* posNode = (*L)->next;            //��������ָ��ֱ�ָ��ͷ�����������
	LNode* nextNode = posNode->next;
	LNode* markNode = nextNode;;               //��¼λ��
	
	if (*L)
	{
		posNode->next = NULL;            //����һ�����ָ���
		while (markNode)
		{
			markNode = markNode->next;      //��¼nextNode���ĺ�һ��λ��
			nextNode->next = posNode;    //����һ�����ָ��ǰһ�����
			posNode = nextNode;			//posNode����
			nextNode = markNode;		//nextNode����

		}
		(*L)->next = posNode;       //ͷ���ָ���ʱ��posNode
		return SUCCESS;
		
	}
	else
	{
		return ERROR;
	}



}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {      

	if (L) {
		LNode* fastNode = L;      //ÿ��h���������
		LNode* slowNode = L;		//ÿ�κ���һ���
		while ((fastNode!=NULL) && (slowNode!=NULL))
		{
			fastNode = fastNode->next;//fastNode�Ⱥ���һ�����
			if (fastNode == NULL)//�жϴ�ʱfastNode�Ƿ�ΪNULL����ΪNULLL���˳�ѭ��
				break;             
			else
				fastNode = fastNode->next;//��ΪNULL���ٺ���һ�����
			slowNode = slowNode->next;//slowNode����һ�����
			if (slowNode == fastNode) //��slowNode == fasNode ����ָ��ָ��ͬһ�����ʱ���ж�Ϊѭ������
			{
				printf("������Ϊѭ������\n");
				return SUCCESS;
			}
		}
		printf("��������ѭ������\n");      
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
	

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {                        

	LNode* frontNode = (*L);             //��������ָ��ֱ�ָ������ǰ�������
	LNode* posNode = frontNode->next;
	LNode* nextNode = posNode->next;
	
	while (posNode)            //��posNode��Ϊ��ʱ
	{
		if (nextNode)          
		{
			posNode->next = nextNode->next;    
			nextNode->next = posNode;
			frontNode->next = nextNode;
		}

		frontNode = posNode;
		posNode = posNode->next;
		if(posNode)
			nextNode = posNode->next;
	
	}

	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {                           


	if (*L) {
		LNode* fastNode = (*L)->next->next;  //��ָ��
		LNode* slowNode = (*L)->next;		//��ָ��

		while (fastNode) //����ָ�벻Ϊ��ʱ
		{
			fastNode = fastNode->next;  //��ָ��ÿ�κ����������
			if (fastNode)
				fastNode->next = fastNode;
			else
			{
				break;
			}
			slowNode = slowNode->next;		//��ָ�����һ�����

		}
		return slowNode;  //����ָ�뵽����ĩβʱ����ʱ��ָ��ָ�������м���
	}
	else
	{
		return *L;
	}
}

