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
    printf("����������Ҫ��������ĳ���(1-1000):\n");
    n = dataScan();
    fflush(stdin);
    while (n <= 0 || n > 1000)
    {
        printf("�������ݴ���������1-1000��\n");
        printf("���ٴ����룺");
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
            printf("�������ٳɹ���\n");
            printf("�����˳����򣡣�\n");
            system("pause");
            exit(0);
            break;
        case 2:
            printf("�������ڵڼ������ǰ�����㣨��������������Ĭ������0����\n");
            n = dataScan();
            printf("������������������ݣ���������������Ĭ������0����\n");
            num = dataScan();
            if (InsertBeforeList_DuL(findNode(L, n), createNode(num)))
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
            printf("�������ڵڼ�����������㣨��������������Ĭ������0����\n");
            n = dataScan();
            printf("������������������ݣ���������������Ĭ������0����\n");
            num = dataScan();
            if (InsertAfterList_DuL(findNode(L, n), createNode(num)))
            {
                printf("����ɹ���\n");
            }
            else
            {
                printf("����ʧ�ܣ�\n");
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
                printf("������Ҫɾ���ڼ�����㣨��������������Ĭ������0����\n");
                n = dataScan();
                if (DeleteList_DuL(findNode(L, n - 1), e))
                {
                    printf("�����ɹ���\n");
                    printf("��ɾ����������Ϊ��%d", *e);
                }
                else
                {
                    printf("����ʧ�ܣ�\n");
                }
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
                TraverseList_DuL(L, visit);
                printf("\n");
            }
            system("pause");
            break;
        default:
            printf("��������ȷ������1-5���в�����\n");
            system("pause");
            break;
        }
    }


}

void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 ��      ��ѡ������Ҫ���еĲ���       ��                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----���������˳�����                        *\n");
    printf("*                          2-----�����㵽ָ�����ǰ                      *\n");
    printf("*                          3-----�����㵽ָ������                      *\n");
    printf("*                          4-----ɾ��������ָ���Ľ��                      *\n");
    printf("*                          5-----��������                                  *\n");
    printf("*                                                                          *\n");
    printf("*                          ������1-5���в�����                             *\n");
    printf("****************************************************************************\n");
    printf("������1-5:\n");


}

//��������Ϊn������
void createList(DuLinkedList* L, int n)
{
    int count = 2;
    ElemType a, * e;
    e = &a;
    //����ͷ���
    InitList_DuL(L);
    printf("�������1���������ݣ���������������Ĭ������0����\n");
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
            printf("�������%d�������ݣ���������������Ĭ������0����\n", count++);
            a = dataScan();
            fflush(stdin);
            p1 = createNode(*e);
        }
        n--;
    }
}


//�������
DuLNode* createNode(ElemType e)
{
    //�����½�� 
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

//��ӡ����
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

//��ӡ�������
void visit(ElemType e)
{
    printf("%d--", e);
}

//�ҵ������n��λ���ϵĽ��
DuLNode* findNode(DuLinkedList L, int n)
{
    DuLNode* posNode = L;
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