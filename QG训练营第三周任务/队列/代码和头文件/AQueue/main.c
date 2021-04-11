#define _CRT_SECURE_NO_WARNINGS 
#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//功能菜单
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 【      请选择你想要进行的操作       】                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----销毁队列并退出程序                        *\n");
    printf("*                          2-----清空队列                                  *\n");
    printf("*                          3-----判断队列是否为空                          *\n");
    printf("*                          4-----判断队列是否为已满                        *\n");
    printf("*                          5-----得到队列头元素                            *\n");
    printf("*                          6-----检测队列长度                              *\n");
    printf("*                          7-----入队列                                    *\n");
    printf("*                          8-----出队列                                    *\n");
    printf("*                          9-----遍历队列                                  *\n");
    printf("*                                                                          *\n");
    printf("*                          请输入1-9进行操作！                             *\n");
    printf("****************************************************************************\n");
    printf("请输入1-9:\n");

}

//输入函数（只允许输入数字）
int dataScan()
{
    int i = 0;
    int t = 0;
    char first; //存储第一个输入的字符用于判断是否要输入负数
    char getdata[1024];//存储输入的数据
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

    if (getdata[0] == '\0') //检查输入的第一个是否为换行，若是则认为是非法输入
        return -2147483647;

    for (t = 0; t < i; t++)
    {
        if (t == 0 && getdata[t] == '-') //若输入的第一个为 - 则判定此次输入为负数，跳过第一次0-9的判断
            continue;
        if (getdata[t] > '9' || getdata[t] < '0')
        {
            return -2147483647;                  //若输入存在非数字，则判定为非法输入
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

//输入函数，只允许输入浮点型
Status getDoubleData(double* doubledata)
{
    int i = 0;
    int t = 0;
    int j = 0;
    int count = 0;
    double afterpoint = 0;
    char first; //存储第一个输入的字符用于判断是否要输入负数
    char getdata[100];//存储输入的数据
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

    if (getdata[0] == '\0'||i>100) //检查输入的第一个是否为换行，若是则认为是非法输入
        return FALSE;

    if (getdata[0] == '0' && getdata[1] != '.')
    {
        return FALSE;
    }

    for (t = 0; t < i; t++)
    {
        if (t == 0 && getdata[t] == '-') //若输入的第一个为 - 则判定此次输入为负数，跳过第一次0-9的判断
            continue;
        if (getdata[t] == '.')         //若输入的含有小数点，则跳过非数字的判断
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
            return FALSE;                  //若输入存在非数字，则判定为非法输入
        }
    }
    //若输入小数点长度大于6则返回FALSE
    if (j >6)
    {
        return FALSE;
    }

    for (t = j-1; t >= 0; t--)
    {
        afterpoint = (afterpoint *0.1 + (afterdata[t]-'0'));
    }
    afterpoint /= 10;


    if (first == '-') //若第一个字符为- 则表明输入为负数
    {
        for (t = 0; t < i; t++)   //将数组前进一位
        {
            getdata[t] = getdata[t + 1];
        }
        if(getdata[0] == '0') //第一个为'0' 
        {
            *doubledata = -1.0 *  afterpoint;
        }
        else//第一个字符不为'0'
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

//输入函数，只允许输入字符型数据
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
    //初始化队列
    InitAQueue(&Q);
    while (1)
    {
        system("cls");
        Menu();
        selection = dataScan();
            switch (selection)
            {
            case 1:
                //摧毁队列
                DestoryAQueue(&Q);
                printf("正在退出···\n");
                system("pause");
                exit(0);
                break;
            case 2:
                if (IsEmptyAQueue(&Q))
                {
                    printf("队列已经为空！\n");
                }
                else
                {
                    ClearAQueue(&Q);
                    printf("队列清空成功！\n");
                }
                system("pause");

                break;
            case 3:
                if (IsEmptyAQueue(&Q))
                {
                    printf("队列为空！\n");
                }
                else
                {
                    printf("队列不为空！\n");
                }
                system("pause");
                break;
            case 4:
                if (IsFullAQueue(&Q))
                {
                    printf("队列为满！\n");
                }
                else
                {
                    printf("队列不为满！\n");
                }
                system("pause");
                break;
            case 5:
                if (IsEmptyAQueue(&Q))
                {
                    printf("队列为空！\n");
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
                    printf("队列头元素为：");
                    APrint(e,datatype[Q.front]);
                    printf("\n");
                }
                system("pause");
                break;
            case 6:
                printf("队列长度为：%d\n",LengthAQueue(&Q));
                system("pause");
                break;
            case 7:
                if (IsFullAQueue(&Q))
                {
                    printf("入队列失败！队列已满！！\n");
                }
                else
                {
                    printf("请选择您要入列的类型：\n\n");
                    printf("1--整型 2--字符型 3--浮点型\n ");
                    printf("请输入1-3进行选择！\n");
                    int chosen = dataScan();
                    switch (chosen)
                    {
                    case 1:
                        printf("请输入数据：\n");
                        intdata = dataScan();
                        if (intdata != -2147483647)
                        {
                            datatype[Q.rear] = sizeof(int);
                            EnAQueue(&Q, &intdata);
                            printf("%d", intdata);
                            printf("入列成功！\n");
                        }
                        else
                        {
                            printf("非法输入！\n");
                        }

                        break;
                    case 2:
                        printf("请输入数据：\n");
                        if (getCharData(&chardata))
                        {
                            datatype[Q.rear] = sizeof(char);
                            EnAQueue(&Q, &chardata);
                            printf("%c", chardata);
                            printf("入列成功！\n");
                        }
                        else
                        {
                            printf("入列失败，输入了非字符型！\n");
                        }
                        break;
                    case 3:
                        printf("请输入数据：\n");
                        printf("请注意！如 01、007 等输入为非法输入！\n");
                        if (getDoubleData(&doubledata))
                        {
                            datatype[Q.rear] = sizeof(double);
                            EnAQueue(&Q, &doubledata);
                            printf("%lf", doubledata);
                            printf("入列成功！\n");
                        }
                        else
                        {
                            printf("输入错误！输入了非浮点型数据");
                        }

                        break;
                    default:
                        printf("输入错误，输入了非1-3的数！\n");
                        break;
                    }
                }
               
                system("pause");
                break;
            case 8:
                if (DeAQueue(&Q))
                {
                    printf("出队列成功！\n");
                }
                else
                {
                    printf("队列为空！出队列失败！\n");
                }
                system("pause");
                break;
            case 9:
                if (IsEmptyAQueue(&Q))
                {
                    printf("队列为空！\n");
                }
                else
                {
                    TraverseAQueue(&Q, APrint);
                }
                system("pause");
                break;
            default:
                printf("请输入1-9进行操作！\n");
                system("pause");
                break;
            }  
    }
}