#include"linkedList.h"
#include<stdio.h>
#include<stdlib.h>

LNode* createNode(ElemType e);
LNode* findNode(LinkedList L, int n);
void createList(LinkedList* L, int n);
void listPrint(LinkedList L);
void visit(ElemType e);
void Menu();
int dataScan();


int main()
{
    ElemType *e,a; 
    e = &a;
    int n=0;       //作为输入变量  
    LNode* mid;
    LinkedList L;

    printf("请输入你想要创建链表的长度(1-1000):\n");
    n = dataScan();
    fflush(stdin);
    while (n <= 0 || n>1000)
    {
        printf("输入数据错误，请输入1-1000！\n");
        printf("请再次输入：\n");
        n = dataScan();
        fflush(stdin);
    }
    createList(&L ,n);
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
               DestroyList(&L);
               printf("链表销毁成功！\n");
               printf("正在退出程序！！\n");
               system("pause");
               exit(0);
               break;
           case 2:
               printf("请输入在第几个结点后插入结点（如果输入非数字则默认输入0）：\n");
               n = dataScan();
               printf("请输入所插入结点的数据（如果输入非数字则默认输入0）：\n");
               a = dataScan();
               if (InsertList(findNode(L, n), createNode(a)))
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
               if (L->next == NULL)
               {
                   printf("链表为空，操作失败!\n");
               }
               else
               {
                   printf("请输入要删除第几个结点（如果输入非数字则默认输入0）：\n");
                   n = dataScan();
                   if (n==0)
                   {
                       printf("操作失败！\n");
                       printf("请输入大于或等于1的值！\n");
                       system("pause");
                       break;
                   }
                   if (DeleteList(findNode(L, n - 1), e))
                   {
                       printf("操作成功！\n");
                       printf("所删除结点的数据为：%d\n", *e);
                   }
                   else
                   {
                       printf("操作失败！\n");
                   }
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
                   TraverseList(L, visit);
                   printf("\n");
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
                   printf("请输入要查询的数（如果输入非数字则默认输入0）：");
                   a = dataScan();
                   if (SearchList(L, a))
                       printf("操作成功！\n");
                   else
                       printf("链表中不存在该结点\n");
               }     
               system("pause");
               break;
           case 6:
               if (L->next == NULL)
               {
                   printf("链表为空，操作失败!\n");
               }
               else if (ReverseList(&L)) 
               {
                   printf("链表反转成功\n");  
               }
               else
               {
                   printf("链表反转失败\n");
                 
               }
               system("pause");
            break;
           case 7:
               if (L->next == NULL)
               {
                   printf("链表为空，操作失败!\n");
               }
               else if (IsLoopList(L))
               {
                   printf("操作成功！\n");
               }
               else
               {
                   printf("操作失败！");
               }
               system("pause");
               break;
           case 8:
               if (L ->next== NULL) 
               {
                   printf("链表为空，操作失败!\n");
               }
               else
               {
                   L = ReverseEvenList(&L);
                   printf("操作成功\n");
               }
               system("pause");
               break;
           case 9:
               if (L ->next== NULL)
               {
                   printf("链表为空，操作失败!\n");
               }
               else
               {
                   mid = FindMidNode(&L);
                   printf("中间结点的数据是：%d\n", mid->data);
                   printf("操作成功\n");
               }
               system("pause");
               break;
           default:
                printf("请输入正确的数字1-9进行操作！\n");
                system("pause");
                break;
        }

    }
    return 0;
}


//功能菜单
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 【      请选择你想要进行的操作       】                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----销毁链表并退出程序                        *\n");
    printf("*                          2-----插入结点到链表中                          *\n");
    printf("*                          3-----删除链表中指定的结点                      *\n");
    printf("*                          4-----遍历链表                                  *\n");
    printf("*                          5-----根据输入数据查找结点                      *\n");
    printf("*                          6-----反转链表                                  *\n");
    printf("*                          7-----查询链表是否为循环链表                    *\n");
    printf("*                          8-----将偶数结点与前结点交换                    *\n");
    printf("*                          9-----找到中间结点                              *\n");
    printf("*                                                                          *\n");
    printf("*                          请输入1-9进行操作！                             *\n");
    printf("****************************************************************************\n");
    printf("请输入1-9:\n");


}


//创建长度为n的链表
void createList(LinkedList *L,int n)
{
    int count=2;
    ElemType a,*e;
    e = &a;
    //创建头结点
    InitList(L);
    printf("请输入第1个结点的数据（如果输入非数字则默认输入0）：\n");
    a = dataScan();
    fflush(stdin);
    LNode* p1 = createNode(*e);
    LNode* p2 = createNode(*e);;
    while (n>0)
    {
        if ((*L)->next==NULL)
        {
            InsertList(*L, p1);
        }
        else
        {
            InsertList(p2, p1);
        }
        p2 = p1;
        if (n != 1)
        {
            printf("请输入第%d结点的数据（如果输入非数字则默认输入0）：\n",count++);
            a = dataScan();
            fflush(stdin);
            p1 = createNode(*e);
        }
        n--;
    }
}

//创建结点
LNode* createNode(ElemType e) 
{
    //创建新结点 
     LNode* newNode = (LNode*)malloc(sizeof(LNode));
    //
    if (newNode) {
        newNode->data = e;
        newNode->next = NULL;
    }
    return newNode;
}


//打印链表
void listPrint(LinkedList L)
{
    if (L) {
        LNode* pMove = L->next;

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
    printf("%d->", e);
}



//找到链表第n个位置上的结点
LNode* findNode(LinkedList L, int n)
{
    LNode* posNode = L;
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
    int i = 0;
    int t = 0;
    char getdata[100];//存储输入的数据
    char ch = getchar();
    fflush(stdin);
    while (ch!='\n')
    {
        getdata[i] = ch;
        ch = getchar();
        fflush(stdin);
        i++;
    }
    getdata[i] = '\0';
    for ( t = 0; t < i; t++)
    {
        if (getdata[t] > '9' || getdata[t] < '0')
        {
            return 0;
        }
    }
    return atoi(getdata); //将输入的非数字转为0
}
