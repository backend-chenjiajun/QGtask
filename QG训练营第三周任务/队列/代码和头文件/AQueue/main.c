#define _CRT_SECURE_NO_WARNINGS 
#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//���ܲ˵�
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 ��      ��ѡ������Ҫ���еĲ���       ��                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----���ٶ��в��˳�����                        *\n");
    printf("*                          2-----��ն���                                  *\n");
    printf("*                          3-----�ж϶����Ƿ�Ϊ��                          *\n");
    printf("*                          4-----�ж϶����Ƿ�Ϊ����                        *\n");
    printf("*                          5-----�õ�����ͷԪ��                            *\n");
    printf("*                          6-----�����г���                              *\n");
    printf("*                          7-----�����                                    *\n");
    printf("*                          8-----������                                    *\n");
    printf("*                          9-----��������                                  *\n");
    printf("*                                                                          *\n");
    printf("*                          ������1-9���в�����                             *\n");
    printf("****************************************************************************\n");
    printf("������1-9:\n");

}

//���뺯����ֻ�����������֣�
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
        return -(atoi(getdata));
    }
    else
        return atoi(getdata);
}

//���뺯����ֻ�������븡����
Status getDoubleData(double* doubledata)
{
    int i = 0;
    int t = 0;
    int j = 0;
    int count = 0;
    double afterpoint = 0;
    char first; //�洢��һ��������ַ������ж��Ƿ�Ҫ���븺��
    char getdata[100];//�洢���������
    char afterdata[7];
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

    if (getdata[0] == '\0'||i>100) //�������ĵ�һ���Ƿ�Ϊ���У���������Ϊ�ǷǷ�����
        return FALSE;

    if (getdata[0] == '0' && getdata[1] != '.')
    {
        return FALSE;
    }

    for (t = 0; t < i; t++)
    {
        if (t == 0 && getdata[t] == '-') //������ĵ�һ��Ϊ - ���ж��˴�����Ϊ������������һ��0-9���ж�
            continue;
        if (getdata[t] == '.')         //������ĺ���С���㣬�����������ֵ��ж�
        {
            count++;
            if (count > 1)
                return FALSE;
            continue;
        } 
        if (count == 1)
        {
            afterdata[j++] = getdata[t];
        }
        if (getdata[t] > '9' || getdata[t] < '0')
        {
            return FALSE;                  //��������ڷ����֣����ж�Ϊ�Ƿ�����
        }
    }
    //������С���㳤�ȴ���6�򷵻�FALSE
    if (j >6)
    {
        return FALSE;
    }

    for (t = j-1; t >= 0; t--)
    {
        afterpoint = (afterpoint *0.1 + (afterdata[t]-'0'));
    }
    afterpoint /= 10;


    if (first == '-') //����һ���ַ�Ϊ- ���������Ϊ����
    {
        for (t = 0; t < i; t++)   //������ǰ��һλ
        {
            getdata[t] = getdata[t + 1];
        }
        if(getdata[0] == '0') //��һ��Ϊ'0' 
        {
            *doubledata = -1.0 *  afterpoint;
        }
        else//��һ���ַ���Ϊ'0'
        {
            *doubledata = -1.0 * ((atoi(getdata)) + afterpoint);
        }
      
    }
    else
    {
        if (getdata[0] == '0')
        {
            *doubledata = afterpoint;
        }
        else
        {
            *doubledata = atoi(getdata) + afterpoint;
        }
      
    }
    return TRUE;
}

//���뺯����ֻ���������ַ�������
Status getCharData(char *chardata)
{
    int i = 0;
    char data[50];
    char ch = getchar();
    while (ch != '\n')
    {

        data[i] = ch;
        ch = getchar();
        fflush(stdin);
        i++;
    }
    data[i] = '\0';
    if (i > 1)
    {
        return FALSE;
    } 
    else
    {
        *chardata = data[0];
        return TRUE;
    }
   

}

void main()
{
    void* e = NULL;
    int intdata;
    char chardata;
    double doubledata;
    AQueue Q;
    int selection;
    //��ʼ������
    InitAQueue(&Q);
    while (1)
    {
        system("cls");
        Menu();
        selection = dataScan();
            switch (selection)
            {
            case 1:
                //�ݻٶ���
                DestoryAQueue(&Q);
                printf("�����˳�������\n");
                system("pause");
                exit(0);
                break;
            case 2:
                if (IsEmptyAQueue(&Q))
                {
                    printf("�����Ѿ�Ϊ�գ�\n");
                }
                else
                {
                    ClearAQueue(&Q);
                    printf("������ճɹ���\n");
                }
                system("pause");

                break;
            case 3:
                if (IsEmptyAQueue(&Q))
                {
                    printf("����Ϊ�գ�\n");
                }
                else
                {
                    printf("���в�Ϊ�գ�\n");
                }
                system("pause");
                break;
            case 4:
                if (IsFullAQueue(&Q))
                {
                    printf("����Ϊ����\n");
                }
                else
                {
                    printf("���в�Ϊ����\n");
                }
                system("pause");
                break;
            case 5:
                if (IsEmptyAQueue(&Q))
                {
                    printf("����Ϊ�գ�\n");
                }
                else
                {
                   if (datatype[Q.front] == sizeof(int))
                    {
                       e = &intdata;
                    }
                    if (datatype[Q.front] == sizeof(char))
                    {
                        e = &chardata;
                    }
                    if (datatype[Q.front] == sizeof(double))
                    {
                        e = &doubledata;
                    }
                    printf("%d", sizeof(char));
                    GetHeadAQueue(&Q,e);
                    printf("����ͷԪ��Ϊ��");
                    APrint(e,datatype[Q.front]);
                    printf("\n");
                }
                system("pause");
                break;
            case 6:
                printf("���г���Ϊ��%d\n",LengthAQueue(&Q));
                system("pause");
                break;
            case 7:
                if (IsFullAQueue(&Q))
                {
                    printf("�����ʧ�ܣ�������������\n");
                }
                else
                {
                    printf("��ѡ����Ҫ���е����ͣ�\n\n");
                    printf("1--���� 2--�ַ��� 3--������\n ");
                    printf("������1-3����ѡ��\n");
                    int chosen = dataScan();
                    switch (chosen)
                    {
                    case 1:
                        printf("���������ݣ�\n");
                        intdata = dataScan();
                        if (intdata != -2147483647)
                        {
                            datatype[Q.rear] = sizeof(int);
                            EnAQueue(&Q, &intdata);
                            printf("%d", intdata);
                            printf("���гɹ���\n");
                        }
                        else
                        {
                            printf("�Ƿ����룡\n");
                        }

                        break;
                    case 2:
                        printf("���������ݣ�\n");
                        if (getCharData(&chardata))
                        {
                            datatype[Q.rear] = sizeof(char);
                            EnAQueue(&Q, &chardata);
                            printf("%c", chardata);
                            printf("���гɹ���\n");
                        }
                        else
                        {
                            printf("����ʧ�ܣ������˷��ַ��ͣ�\n");
                        }
                        break;
                    case 3:
                        printf("���������ݣ�\n");
                        printf("��ע�⣡�� 01��007 ������Ϊ�Ƿ����룡\n");
                        if (getDoubleData(&doubledata))
                        {
                            datatype[Q.rear] = sizeof(double);
                            EnAQueue(&Q, &doubledata);
                            printf("%lf", doubledata);
                            printf("���гɹ���\n");
                        }
                        else
                        {
                            printf("������������˷Ǹ���������");
                        }

                        break;
                    default:
                        printf("������������˷�1-3������\n");
                        break;
                    }
                }
               
                system("pause");
                break;
            case 8:
                if (DeAQueue(&Q))
                {
                    printf("�����гɹ���\n");
                }
                else
                {
                    printf("����Ϊ�գ�������ʧ�ܣ�\n");
                }
                system("pause");
                break;
            case 9:
                if (IsEmptyAQueue(&Q))
                {
                    printf("����Ϊ�գ�\n");
                }
                else
                {
                    TraverseAQueue(&Q, APrint);
                }
                system("pause");
                break;
            default:
                printf("������1-9���в�����\n");
                system("pause");
                break;
            }  
    }
}