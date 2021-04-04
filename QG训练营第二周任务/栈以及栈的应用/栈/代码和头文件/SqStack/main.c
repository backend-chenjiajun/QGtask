#include"SqStack.h"
#include<stdio.h>






//���ܲ˵�
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 ��      ��ѡ������Ҫ���еĲ���       ��                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----����ջ���˳�����                          *\n");
    printf("*                          2-----���ջ����                                *\n");
    printf("*                          3-----�ж�ջ�Ƿ�Ϊ��                            *\n");
    printf("*                          4-----�õ�ջ��Ԫ��                              *\n");
    printf("*                          5-----���ջ����                                *\n");
    printf("*                          6-----��ջ                                      *\n");
    printf("*                          7-----��ջ                                      *\n");
    printf("*                          8-----����ջ                                    *\n");
    printf("*                                                                          *\n");
    printf("*                          ������1-8���в�����                             *\n");
    printf("****************************************************************************\n");
    printf("������1-8:\n");

}


//���뺯��
int dataScan()
{
    int i = 0;
    int t = 0;
    char first; //�洢��һ��������ַ������ж��Ƿ�Ҫ���븺��
    char getdata[1024];//�洢���������
    char ch = getchar();
    first = ch;
    fflush(stdin);
    while (ch != '\n')
    {
       
        getdata[i] = ch;
        ch = getchar();
        fflush(stdin);
        i++;
        
    }
    getdata[i] = '\0';

    if (getdata[0] == '\0') //�������ĵ�һ���Ƿ�Ϊ���У���������Ϊ�ǷǷ�����
        return -2147483647;

    for (t = 0; t < i; t++)
    {
        if (t == 0 && getdata[t] == '-') //������ĵ�һ��Ϊ - ���ж��˴�����Ϊ������������һ��0-9���ж�
            continue;
        if (getdata[t] > '9' || getdata[t] < '0')
        {
            return -2147483647;                  //��������ڷ����֣����ж�Ϊ�Ƿ�����
        }
    }

    if (first == '-')
    {
        for (t = 0; t < i; t++)
        {
            getdata[t] = getdata[t + 1];       
        }
        return -(atoi(getdata)); //������ķ�����תΪ0
    }
    else
        return atoi(getdata);
}

//��ӡջ
void printStack(SqStack* s) 
{
    if (s->top == -1)
    {
        printf("��ǰջΪ�գ�\n");
    }
    else
    {
        printf("��ǰջ������Ϊ��\n");
        for (int i = 0; i <= s->top; i++)
        {
            if (i == s->top)
            {
                printf("%d \n", s->elem[i]);
                printf("ջ�������ұ�������Ϊ�� %d\n ", s->elem[i]);
            }          
            else
                printf("%d -- ", s->elem[i]);
        }
        
    }
}



int main()
{
    SqStack s;
    ElemType e ;
    ElemType data;
    int* length;
    int len;
    int n;
    int sizes;
    printf("������Ҫ����ջ�ĳ���(1-1000)��\n");
    sizes = dataScan();
    fflush(stdin);
    while (sizes <1 || sizes > 1000)
    {
        printf("�������ݴ���������1-1000��\n");
        printf("���ٴ����룺\n");
        sizes = dataScan();
        fflush(stdin);
    }
    if(initStack(&s, sizes))
    while (1)
    {
        system("cls");
        Menu();
        n = dataScan();
        fflush(stdin);
        if (n == -2147483647)
        {
            printf("�Ƿ����룡��������ȷ�����ݣ�\n");
            system("pause");
        }
        else
        {
            switch (n)
            {
            case 1:
                destroyStack(&s);
                printf("���ٳɹ��������˳�����\n");
                system("pause");
                exit(0);
                break;
            case 2:
                    clearStack(&s);
                    printf("�����ɹ���\n");
                    system("pause");
                    break;
            case 3:
                isEmptyStack(&s);
                system("pause");
                break;
            case 4:
                getTopStack(&s, &e);
                system("pause");
                break;
            case 5:
                length = &len;
                stackLength(&s, length);
                printf("ջ�ĳ���Ϊ%d\n", *length);
                system("pause");
                break;
            case 6:
                printf("��������ջ��Ԫ�أ�\n");
                data = dataScan();
                if (data == -2147483647)
                    printf("�Ƿ����룡��������ȷ�����ݣ�\n");
                else
                {
                    pushStack(&s, data);
                    printf("��ջ�ɹ���");
                }
                system("pause");
                break;
            case 7:
                popStack(&s, &data);
                    
                system("pause");
                break;
            case 8:
                printStack(&s);
                system("pause");
                break;

            default:
                printf("�������������1-8���в�����\n");
                system("pause");
                break;
            }


        }
       
    }
   
}
