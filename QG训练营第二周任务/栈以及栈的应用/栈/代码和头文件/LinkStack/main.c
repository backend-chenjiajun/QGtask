#include"LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
//功能菜单
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                 【      请选择你想要进行的操作       】                  *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----销毁栈并退出程序                          *\n");
    printf("*                          2-----清空栈数据                                *\n");
    printf("*                          3-----判断栈是否为空                            *\n");
    printf("*                          4-----得到栈顶元素                              *\n");
    printf("*                          5-----检测栈长度                                *\n");
    printf("*                          6-----入栈                                      *\n");
    printf("*                          7-----出栈                                      *\n");
    printf("*                          8-----遍历栈                                    *\n");
    printf("*                                                                          *\n");
    printf("*                          请输入1-8进行操作！                             *\n");
    printf("****************************************************************************\n");
    printf("请输入1-8:\n");

}


//输入函数
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
        return -(atoi(getdata)); //将输入的非数字转为0
    }
    else
        return atoi(getdata);
}

//打印栈
void printStack(LinkStack* s)
{
    if (s->top == NULL)
    {
        printf("当前栈为空！\n");
    }
    else
    {
        LinkStackPtr p = s->top;          //创建指针指向栈顶
        printf("当前栈的内容为：\n");
        while (p)             //当p指针不指向空时
        {
            if (!p->next)
            {
                printf("%d \n", p->data);
                printf("***** 栈顶为最左边 *****\n");
            }
            else
            {
                printf("%d -- ", p->data);
            }    
            p = p->next;
       }
      
    }
}



int main()
{
    LinkStack s;
    ElemType e;
    ElemType data;
    int* length;
    int len;
    int n;
    initLStack(&s);//初始化栈
        while (1)
        {
            system("cls");
            Menu();
            n = dataScan();
            fflush(stdin);
            if (n == -2147483647)
            {
                printf("非法输入！请输入正确的数据！\n");
                system("pause");
            }
            else
            {
                switch (n)
                {
                case 1:
                    destroyLStack(&s);
                    printf("销毁成功！正在退出程序！\n");
                    system("pause");
                    exit(0);
                    break;
                case 2:
                    clearLStack(&s);
                    printf("操作成功！\n");
                    system("pause");
                    break;
                case 3:
                    isEmptyLStack(&s);
                    system("pause");
                    break;
                case 4:
                    getTopLStack(&s, &e);
                    system("pause");
                    break;
                case 5:
                    length = &len;
                    LStackLength(&s, length);
                    printf("栈的长度为%d\n", *length);
                    system("pause");
                    break;
                case 6:
                    printf("请输入入栈的元素：\n");
                    data = dataScan();
                    if (data == -2147483647)
                        printf("非法输入！请输入正确的数据！\n");
                    else
                    {
                        pushLStack(&s, data);
                        printf("入栈成功！\n");
                    }
                    system("pause");
                    break;
                case 7:
                    popLStack(&s, &data);

                    system("pause");
                    break;
                case 8:
                    printStack(&s);
                    system("pause");
                    break;

                default:
                    printf("输入错误！请输入1-8进行操作！\n");
                    system("pause");
                    break;
                }


            }

        }

}