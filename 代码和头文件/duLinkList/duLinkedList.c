#include "duLinkedList.h"
#include <stdio.h>
#include<stdlib.h>


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    
    (*L) = (DuLinkedList)malloc(sizeof(DuLNode));
    if (*L)
    {
        (*L)->next = NULL;
        (*L)->prior = NULL;
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLNode* posNode = *L; //创建结点指针指向头结点

    while (posNode)        //当posNode不为空时进行循环
    {

        posNode = (*L)->next;    //posNode移动到头结点下一个结点

        free(*L);               //释放头结点

        *L = posNode;         //以posNode为头结点
    }


}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
   
    if (p && q)    //当p和q 两结点都不为空时
    {
        if (p->prior != NULL)
        {
            q->prior = p->prior;
            p->prior->next = q;
        }
        q->next = p;
        p->prior = q;
        return SUCCESS;
    }
    else
        return ERROR;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    
    if (p && q)    //当p和q 两结点都不为空时
    {
        if (p->next != NULL)  //如果p结点不为最后一个结点
        {
            q->next = p->next;         //将要插入的结点指向p的下一个结点
            p->next->prior = q;         
        }
        p->next = q;
        q->prior = p;
        return SUCCESS;
    }
    else
        return ERROR;


}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {

    DuLNode* posNode = p;       //创建结点指针指向p的下一个结点


    if (posNode == NULL) {//判断posNode是否为空
        return ERROR;
    }
    else if (posNode->next==NULL)
    {
        return ERROR;
    }
  
        posNode = posNode->next;
 
       *e = posNode->data;      //将posNode的值赋给e

       p->next = posNode->next;//将结点p指向posNode的下一个结点

        if (p->next)
            posNode->next->prior = p;

        free(posNode);      //释放posNode结点
        return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {

    if (L == NULL)
    {
        printf("链表不存在！\n");
    }
    else
    {
        DuLNode* posNode = L->next;  //创建指针指向头结点的下一个结点

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
