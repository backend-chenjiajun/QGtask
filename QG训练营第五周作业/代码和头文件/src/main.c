#include"binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

//功能菜单
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                         【     二叉排序树      】                        *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----插入数字                                  *\n");
    printf("*                          2-----查找数字                                  *\n");
    printf("*                          3-----删除数字                                  *\n");
    printf("*                          4-----递归前序遍历                              *\n");
    printf("*                          5-----递归中序遍历                              *\n");
    printf("*                          6-----递归后序遍历                              *\n");
    printf("*                          7-----迭代前序遍历                              *\n");
    printf("*                          8-----迭代中序遍历                              *\n");
    printf("*                          9-----迭代后序遍历                              *\n");
    printf("*                          10-----层序遍历                                 *\n");
    printf("*                          11-----退出程序                                 *\n");
    printf("*                                                                          *\n");
    printf("*                          请输入1-11进行操作！                            *\n");
    printf("****************************************************************************\n");
    printf("请输入1-11:\n");

}

//输入函数（只允许输入数字）
Status dataScan(int* data)
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
        return false;

    for (t = 0; t < i; t++)
    {
        if (t == 0 && getdata[t] == '-') //若输入的第一个为 - 则判定此次输入为负数，跳过第一次0-9的判断
            continue;
        if (getdata[t] > '9' || getdata[t] < '0')
        {
            return false;                  //若输入存在非数字，则判定为非法输入
        }
    }

    if (first == '-')
    {
        for (t = 0; t < i; t++)
        {
            getdata[t] = getdata[t + 1];
        }
        *data = -(atoi(getdata));
    }
    else
        *data =  atoi(getdata);

    return true;
}

/*
* 打印函数
*/
void visit(NodePtr node)
{
    printf("%d ", node->value);
}

void main()
{
    //创建树
    BinarySortTree BST;
    BST.root = NULL;
    int chosen;
    while (1)
    {
        system("cls");
        Menu();
        int num;
        if (dataScan(&chosen))
        {
            switch (chosen)
            {
            case 1:
                printf("请输入要插入的数：\n");
                if (dataScan(&num))
                {
                    if (BST_insert(&BST, num))
                    {
                        printf("插入成功！\n");
                    }
                   
                }
                else
                {
                    printf("非法输入！\n");
                }
                system("pause");
                break;
            case 2:
                printf("请输入要查询的数：\n");
                if (dataScan(&num))
                {
                   
                    if (BST_search(&BST, num))
                    {
                        printf("该数存在！\n");
                    }
                    else
                    {
                        printf("该数不存在！\n");
                    }
                    
                }
                else
                {
                    printf("非法输入！\n");
                }
                system("pause");
                break;
            case 3:
                printf("请输入要删除的数：\n");
                if (dataScan(&num))
                {

                    if (BST_search(&BST, num))
                    {
                        if (BST_delete(&BST, num))
                        {
                            printf("删除成功！\n");
                        }
                        else
                        {
                            printf("删除失败！\n");
                        }
                      
                    }
                    else
                    {
                        printf("删除失败，该数不存在！\n");
                    }

                }
                else
                {
                    printf("非法输入！\n");
                }
                system("pause");
                break;
            case 4:
                BST_preorderR(&BST, visit);
                printf("\n");
                system("pause");
                break;
            case 5:
                BST_inorderR(&BST, visit);
                printf("\n");
                system("pause");
                break;
            case 6:
                BST_postorderR(&BST, visit);
                printf("\n");
                system("pause");
                break;
            case 7:
                BST_preorderI(&BST, visit);
                printf("\n");
                system("pause");
                break;
            case 8:
                BST_inorderI(&BST, visit);
                printf("\n");
                system("pause");
                break;
            case 9:
                BST_postorderI(&BST, visit);
                printf("\n");
                system("pause");
                break;
            case 10:
                BST_levelOrder(&BST, visit);
                printf("\n");
                system("pause");
                break;
            case 11:
                printf("正在退出···\n");
                system("pause");
                exit(0);
                break;
            default:
                printf("请输入1-11进行选择！\n");
                system("pause");
                break;
            }
        }
        else
        {
            printf("非法输入！\n");
            system("pause");
        }
    }
}