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
    int n=0;       //��Ϊ�������  
    LNode* mid;
    LinkedList L;

    printf("����������Ҫ��������ĳ���(1-1000):\n");
    n = dataScan();
    fflush(stdin);
    while (n <= 0 || n>1000)
    {
        printf("�������ݴ���������1-1000��\n");
        printf("���ٴ����룺\n");
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
               printf("�������ٳɹ���\n");
               printf("�����˳����򣡣�\n");
               system("pause");
               exit(0);
               break;
           case 2:
               printf("�������ڵڼ�����������㣨��������������Ĭ������0����\n");
               n = dataScan();
               printf("������������������ݣ���������������Ĭ������0����\n");
               a = dataScan();
               if (InsertList(findNode(L, n), createNode(a)))
               {
                   printf("����ɹ���\n");
               }      
               else
               {
                   printf("����ʧ�ܣ�\n");
               }
               system("pause");
            break;
           case 3:
               if (L->next == NULL)
               {
                   printf("����Ϊ�գ�����ʧ��!\n");
               }
               else
               {
                   printf("������Ҫɾ���ڼ�����㣨��������������Ĭ������0����\n");
                   n = dataScan();
                   if (n==0)
                   {
                       printf("����ʧ�ܣ�\n");
                       printf("��������ڻ����1��ֵ��\n");
                       system("pause");
                       break;
                   }
                   if (DeleteList(findNode(L, n - 1), e))
                   {
                       printf("�����ɹ���\n");
                       printf("��ɾ����������Ϊ��%d\n", *e);
                   }
                   else
                   {
                       printf("����ʧ�ܣ�\n");
                   }
               }  
               system("pause");
               break;
           case 4:
               if (L->next == NULL)
               {
                   printf("����Ϊ�գ�����ʧ��!\n");
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
                   printf("����Ϊ�գ�����ʧ��!\n");
               }
               else
               {
                   printf("������Ҫ��ѯ��������������������Ĭ������0����");
                   a = dataScan();
                   if (SearchList(L, a))
                       printf("�����ɹ���\n");
                   else
                       printf("�����в����ڸý��\n");
               }     
               system("pause");
               break;
           case 6:
               if (L->next == NULL)
               {
                   printf("����Ϊ�գ�����ʧ��!\n");
               }
               else if (ReverseList(&L)) 
               {
                   printf("����ת�ɹ�\n");  
               }
               else
               {
                   printf("����תʧ��\n");
                 
               }
               system("pause");
            break;
           case 7:
               if (L->next == NULL)
               {
                   printf("����Ϊ�գ�����ʧ��!\n");
               }
               else if (IsLoopList(L))
               {
                   printf("�����ɹ���\n");
               }
               else
               {
                   printf("����ʧ�ܣ�");
               }
               system("pause");
               break;
           case 8:
               if (L ->next== NULL) 
               {
                   printf("����Ϊ�գ�����ʧ��!\n");
               }
               else
               {
                   L = ReverseEvenList(&L);
                   printf("�����ɹ�\n");
               }
               system("pause");
               break;
           case 9:
               if (L ->next== NULL)
               {
                   printf("����Ϊ�գ�����ʧ��!\n");
               }
               else
               {
                   mid = FindMidNode(&L);
                   printf("�м���������ǣ�%d\n", mid->data);
                   printf("�����ɹ�\n");
               }
               system("pause");
               break;
           default:
                printf("��������ȷ������1-9���в�����\n");
                system("pause");
                break;
        }

    }
    return 0;
}


//���ܲ˵�
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 ��      ��ѡ������Ҫ���еĲ���       ��                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----���������˳�����                        *\n");
    printf("*                          2-----�����㵽������                          *\n");
    printf("*                          3-----ɾ��������ָ���Ľ��                      *\n");
    printf("*                          4-----��������                                  *\n");
    printf("*                          5-----�����������ݲ��ҽ��                      *\n");
    printf("*                          6-----��ת����                                  *\n");
    printf("*                          7-----��ѯ�����Ƿ�Ϊѭ������                    *\n");
    printf("*                          8-----��ż�������ǰ��㽻��                    *\n");
    printf("*                          9-----�ҵ��м���                              *\n");
    printf("*                                                                          *\n");
    printf("*                          ������1-9���в�����                             *\n");
    printf("****************************************************************************\n");
    printf("������1-9:\n");


}


//��������Ϊn������
void createList(LinkedList *L,int n)
{
    int count=2;
    ElemType a,*e;
    e = &a;
    //����ͷ���
    InitList(L);
    printf("�������1���������ݣ���������������Ĭ������0����\n");
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
            printf("�������%d�������ݣ���������������Ĭ������0����\n",count++);
            a = dataScan();
            fflush(stdin);
            p1 = createNode(*e);
        }
        n--;
    }
}

//�������
LNode* createNode(ElemType e) 
{
    //�����½�� 
     LNode* newNode = (LNode*)malloc(sizeof(LNode));
    //
    if (newNode) {
        newNode->data = e;
        newNode->next = NULL;
    }
    return newNode;
}


//��ӡ����
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


//��ӡ�������
void visit(ElemType e)
{
    printf("%d->", e);
}



//�ҵ������n��λ���ϵĽ��
LNode* findNode(LinkedList L, int n)
{
    LNode* posNode = L;
    if (n < 0)
    {
        printf("�������ݴ���n��ֵҪ���ڻ����1��\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (posNode == NULL)
            {
                printf("������������Ҫ�ҵĽ�㣡\n");
                return NULL;
            }
            posNode = posNode->next;
        }
    }

    return posNode;
}

//���뺯��
int dataScan()
{
    int i = 0;
    int t = 0;
    char getdata[100];//�洢���������
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
    return atoi(getdata); //������ķ�����תΪ0
}
