#include "linkedList.h"
#include <stdio.h>
#include<stdlib.h>



/*LNode* createList() {
	//创建头结点LHeadNode 
	struct LNode* LHeadNode = (LNode*)malloc(sizeof(LNode));
	//将头结点指向空 
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

	
	*L= (LinkedList)malloc(sizeof(LNode)); //给表头开辟空间
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
	
	
	LNode* posNode = *L; //创建结点指针指向头结点
	
	while (posNode)        //当posNode不为空时进行循环
	{
		
		posNode = (*L)->next;    //posNode移动到头结点下一个结点
		
		free(*L);               //释放头结点
		
		*L = posNode;         //以posNode为头结点
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

	
	if (p && q)    //当p和q 两结点都不为空时
	{
		LNode* posNode = p->next;     //创建指针指向p的下一个结点

		p->next = q;					//p指向q
		q->next = posNode;				//q指向posNode

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
	
	
	LNode* posNode = p;       //创建结点指针指向p的下一个结点
	
	
	if (posNode==NULL   ) {//判断posNode是否为空
		return ERROR;
	}
	else if (posNode->next==NULL)
	{
		return ERROR;
	}
	else
	{
		posNode = posNode->next;
			
		*e = posNode->data;      //将posNode的值赋给e
			
		p->next =posNode->next;//将结点p指向posNode的下一个结点
			
			free(posNode);      //释放posNode结点
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
		printf("链表不存在！\n");
	}
	else
	{
		LNode* posNode = L->next;  //创建指针指向头结点的下一个结点

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
			posNode = posNode->next;//指针移动至下一个结点处
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
	LNode* posNode = L->next; //创建指针指向头结点L的下一个结点
	
	while (posNode) {                //当posNode不为空时进行循环
		
		if (posNode->data == e) 
		{//如果posNode中的值等于e 返回SUCCESS，表示找到结点

			printf("该结点为第%d个结点\n",i);
			return SUCCESS;
		}
		
		posNode = posNode->next;     //posNode指向下一个结点
		i++;
	}
	
	return ERROR;                        //当posNode为空时表示未找到结点，返回ERROR

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {             
	
	LNode* posNode = (*L)->next;            //创建两个指针分别指向头结点后两个结点
	LNode* nextNode = posNode->next;
	LNode* markNode = nextNode;;               //记录位置
	
	if (*L)
	{
		posNode->next = NULL;            //将第一个结点指向空
		while (markNode)
		{
			markNode = markNode->next;      //记录nextNode结点的后一个位置
			nextNode->next = posNode;    //将后一个结点指向前一个结点
			posNode = nextNode;			//posNode后移
			nextNode = markNode;		//nextNode后移

		}
		(*L)->next = posNode;       //头结点指向此时的posNode
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
		LNode* fastNode = L;      //每次h后移两结点
		LNode* slowNode = L;		//每次后移一结点
		while ((fastNode!=NULL) && (slowNode!=NULL))
		{
			fastNode = fastNode->next;//fastNode先后移一个结点
			if (fastNode == NULL)//判断此时fastNode是否为NULL，若为NULLL则退出循环
				break;             
			else
				fastNode = fastNode->next;//不为NULL则再后移一个结点
			slowNode = slowNode->next;//slowNode后移一个结点
			if (slowNode == fastNode) //当slowNode == fasNode 即两指针指向同一个结点时则判断为循环链表
			{
				printf("该链表为循环链表！\n");
				return SUCCESS;
			}
		}
		printf("该链表不是循环链表！\n");      
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

	LNode* frontNode = (*L);             //创建三个指针分别指向链表前三个结点
	LNode* posNode = frontNode->next;
	LNode* nextNode = posNode->next;
	
	while (posNode)            //当posNode不为空时
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
		LNode* fastNode = (*L)->next->next;  //快指针
		LNode* slowNode = (*L)->next;		//慢指针

		while (fastNode) //当快指针不为空时
		{
			fastNode = fastNode->next;  //快指针每次后移两个结点
			if (fastNode)
				fastNode->next = fastNode;
			else
			{
				break;
			}
			slowNode = slowNode->next;		//慢指针后移一个结点

		}
		return slowNode;  //当快指针到链表末尾时，此时慢指针指向链表中间结点
	}
	else
	{
		return *L;
	}
}

