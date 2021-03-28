#include"DulinkedList.h"
#include<stdio.h>
#include<stdlib.h>

void Menu();
void createList(DuLinkedList* L, int n);
DuLNode* createNode(ElemType e);
void listPrint(DuLinkedList L);
void visit(ElemType e);
DuLNode* findNode(DuLinkedList L, int n);
int dataScan();



int main() 
{
    ElemType* e, a;
    e = &a;
    int n = 0;
    int num = 0;
    DuLinkedList L;
    printf("请输入你想要创建链表的长度(1-1000):\n");
    n = dataScan();
    fflush(stdin);
    while (n <= 0 || n > 1000)
    {
        printf("输入数据错误，请输入1-1000！\n");
        printf("请再次输入：");
        n = dataScan();
        fflush(stdin);
    }
    createList(&L, n);
    while (1)
    {
        system("cls");
        Menu();
        fflush(stdin);
        n = dataScan();
        fflush(stdin);
        switch (n)
        {
        case 1:
            DestroyList_DuL(&L);
            printf("链表销毁成功！\n");
            printf("正在退出程序！！\n");
            system("pause");
            exit(0);
            break;
        case 2:
            printf("请输入在第几个结点前插入结点（如果输入非数字则默认输入0）：\n");
            n = dataScan();
            printf("请输入所插入结点的数据（如果输入非数字则默认输入0）：\n");
            num = dataScan();
            if (InsertBeforeList_DuL(findNode(L, n), createNode(num)))
            {
                printf("插入成功！\n");
            }
            else
            {
                printf("插入失败！\n");
            }
            system("pause");
            break;
        case 3:
            printf("请输入在第几个结点后插入结点（如果输入非数字则默认输入0）：\n");
            n = dataScan();
            printf("请输入所插入结点的数据（如果输入非数字则默认输入0）：\n");
            num = dataScan();
            if (InsertAfterList_DuL(findNode(L, n), createNode(num)))
            {
                printf("插入成功！\n");
            }
            else
            {
                printf("插入失败！\n");
            }
            system("pause");
            break;
        case 4:
            if (L->next == NULL)
            {
                printf("链表为空，操作失败!\n");
            }
            else
            {
                printf("请输入要删除第几个结点（如果输入非数字则默认输入0）：\n");
                n = dataScan();
                if (DeleteList_DuL(findNode(L, n - 1), e))
                {
                    printf("操作成功！\n");
                    printf("所删除结点的数据为：%d", *e);
                }
                else
                {
                    printf("操作失败！\n");
                }
            }
            system("pause");
            break;
        case 5:
            if (L->next == NULL)
            {
                printf("链表为空，操作失败!\n");
            }
            else
            {
                TraverseList_DuL(L, visit);
                printf("\n");
            }
            system("pause");
            break;
        default:
            printf("请输入正确的数字1-5进行操作！\n");
            system("pause");
            break;
        }
    }


}

void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 【      请选择你想要进行的操作       】                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----销毁链表并退出程序                        *\n");
    printf("*                          2-----插入结点到指定结点前                      *\n");
    printf("*                          3-----插入结点到指定结点后                      *\n");
    printf("*                          4-----删除链表中指定的结点                      *\n");
    printf("*                          5-----遍历链表                                  *\n");
    printf("*                                                                          *\n");
    printf("*                          请输入1-5进行操作！                             *\n");
    printf("****************************************************************************\n");
    printf("请输入1-5:\n");


}

//创建长度为n的链表
void createList(DuLinkedList* L, int n)
{
    int count = 2;
    ElemType a, * e;
    e = &a;
    //创建头结点
    InitList_DuL(L);
    printf("请输入第1个结点的数据（如果输入非数字则默认输入0）：\n");
    a = dataScan();
    fflush(stdin);
    DuLNode* p1 = createNode(*e);
    DuLNode* p2 = createNode(*e);;
    while (n > 0)
    {
        if ((*L)->next == NULL)
        {
            InsertAfterList_DuL(*L, p1);
        }
        else
        {
            InsertAfterList_DuL(p2, p1);
        }
        p2 = p1;
        if (n != 1)
        {
            printf("请输入第%d结点的数据（如果输入非数字则默认输入0）：\n", count++);
            a = dataScan();
            fflush(stdin);
            p1 = createNode(*e);
        }
        n--;
    }
}


//创建结点
DuLNode* createNode(ElemType e)
{
    //创建新结点 
     DuLNode* newNode = (DuLNode*)malloc(sizeof(DuLNode));
    //
    if (newNode) 
    {
        newNode->data = e;
        newNode->next = NULL;
        newNode->prior = NULL;
    }
    return newNode;
}

//打印链表
void listPrint(DuLinkedList L)
{
    if (L) {
        DuLNode* pMove = L->next;

        while (pMove)
        {

            if (pMove->next == NULL)
                printf("%d", pMove->data);
            else
                printf("%d->", pMove->data);
            pMove = pMove->next;
        }
    }
}

//打印结点数据
void visit(ElemType e)
{
    printf("%d--", e);
}

//找到链表第n个位置上的结点
DuLNode* findNode(DuLinkedList L, int n)
{
    DuLNode* posNode = L;
    if (n < 0)
    {
        printf("输入数据错误，n的值要大于或等于1！\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (posNode == NULL)
            {
                printf("该链表不存在所要找的结点！\n");
                return NULL;
            }
            posNode = posNode->next;
        }
    }

    return posNode;
}

//输入函数
int dataScan()
{
    int t = 0;
    int i = 0;
    char getdata[100];
    char ch = getchar();
    fflush(stdin);
    while (ch != '\n')
    {
        getdata[i] = ch;
        ch = getchar();
        fflush(stdin);
        i++;
    }
    getdata[i] = '\0';
    for (t = 0; t < i; t++)
    {
        if (getdata[t] > '9' || getdata[t] < '0')
        {
            return 0;
        }
    }
    return atoi(getdata);
}