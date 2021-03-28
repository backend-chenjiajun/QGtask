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
    DuLNode* posNode = *L; //�������ָ��ָ��ͷ���

    while (posNode)        //��posNode��Ϊ��ʱ����ѭ��
    {

        posNode = (*L)->next;    //posNode�ƶ���ͷ�����һ�����

        free(*L);               //�ͷ�ͷ���

        *L = posNode;         //��posNodeΪͷ���
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
   
    if (p && q)    //��p��q ����㶼��Ϊ��ʱ
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
    
    if (p && q)    //��p��q ����㶼��Ϊ��ʱ
    {
        if (p->next != NULL)  //���p��㲻Ϊ���һ�����
        {
            q->next = p->next;         //��Ҫ����Ľ��ָ��p����һ�����
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

    DuLNode* posNode = p;       //�������ָ��ָ��p����һ�����


    if (posNode == NULL) {//�ж�posNode�Ƿ�Ϊ��
        return ERROR;
    }
    else if (posNode->next==NULL)
    {
        return ERROR;
    }
  
        posNode = posNode->next;
 
       *e = posNode->data;      //��posNode��ֵ����e

       p->next = posNode->next;//�����pָ��posNode����һ�����

        if (p->next)
            posNode->next->prior = p;

        free(posNode);      //�ͷ�posNode���
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
        printf("�������ڣ�\n");
    }
    else
    {
        DuLNode* posNode = L->next;  //����ָ��ָ��ͷ������һ�����

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
