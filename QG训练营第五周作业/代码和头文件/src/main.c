#include"binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

//���ܲ˵�
void Menu()
{
    printf("****************************************************************************\n");
    printf("*                         ��     ����������      ��                        *\n");
    printf("*                                                                          *\n");
    printf("*                          1-----��������                                  *\n");
    printf("*                          2-----��������                                  *\n");
    printf("*                          3-----ɾ������                                  *\n");
    printf("*                          4-----�ݹ�ǰ�����                              *\n");
    printf("*                          5-----�ݹ��������                              *\n");
    printf("*                          6-----�ݹ�������                              *\n");
    printf("*                          7-----����ǰ�����                              *\n");
    printf("*                          8-----�����������                              *\n");
    printf("*                          9-----�����������                              *\n");
    printf("*                          10-----�������                                 *\n");
    printf("*                          11-----�˳�����                                 *\n");
    printf("*                                                                          *\n");
    printf("*                          ������1-11���в�����                            *\n");
    printf("****************************************************************************\n");
    printf("������1-11:\n");

}

//���뺯����ֻ�����������֣�
Status dataScan(int* data)
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
        return false;

    for (t = 0; t < i; t++)
    {
        if (t == 0 && getdata[t] == '-') //������ĵ�һ��Ϊ - ���ж��˴�����Ϊ������������һ��0-9���ж�
            continue;
        if (getdata[t] > '9' || getdata[t] < '0')
        {
            return false;                  //��������ڷ����֣����ж�Ϊ�Ƿ�����
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
* ��ӡ����
*/
void visit(NodePtr node)
{
    printf("%d ", node->value);
}

void main()
{
    //������
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
                printf("������Ҫ���������\n");
                if (dataScan(&num))
                {
                    if (BST_insert(&BST, num))
                    {
                        printf("����ɹ���\n");
                    }
                   
                }
                else
                {
                    printf("�Ƿ����룡\n");
                }
                system("pause");
                break;
            case 2:
                printf("������Ҫ��ѯ������\n");
                if (dataScan(&num))
                {
                   
                    if (BST_search(&BST, num))
                    {
                        printf("�������ڣ�\n");
                    }
                    else
                    {
                        printf("���������ڣ�\n");
                    }
                    
                }
                else
                {
                    printf("�Ƿ����룡\n");
                }
                system("pause");
                break;
            case 3:
                printf("������Ҫɾ��������\n");
                if (dataScan(&num))
                {

                    if (BST_search(&BST, num))
                    {
                        if (BST_delete(&BST, num))
                        {
                            printf("ɾ���ɹ���\n");
                        }
                        else
                        {
                            printf("ɾ��ʧ�ܣ�\n");
                        }
                      
                    }
                    else
                    {
                        printf("ɾ��ʧ�ܣ����������ڣ�\n");
                    }

                }
                else
                {
                    printf("�Ƿ����룡\n");
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
                printf("�����˳�������\n");
                system("pause");
                exit(0);
                break;
            default:
                printf("������1-11����ѡ��\n");
                system("pause");
                break;
            }
        }
        else
        {
            printf("�Ƿ����룡\n");
            system("pause");
        }
    }
}