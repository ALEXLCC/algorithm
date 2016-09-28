#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int num;
        int key;
        struct node *next;
}LNode;

void Joseph(int, int, int*);
LNode *CreateList(int);

void main()
{
        int m, n, a[10];
        //m是报数范围，n是人数，a[10]存储每个人所拥有的密码

        scanf("%d %d", &n, &m);
        Joseph(n, m, a);
}

void Joseph(int n, int m, int *a)
{
        LNode *head = NULL;
        LNode *p = NULL;
        LNode *temp = NULL;
        LNode *last = NULL;

        int i;
        int count = 1;

        head = CreateList(n);
        p = head;

        while(p != p->next){
                for(i=1; i<m; i++){
                        last = p;
                        p = p->next;
                }

                printf("%5d", p->num);
                m = p->key;
                temp = p;
                last->next = p->next;
                p = p->next;
                free(temp);
        }

        printf("%5d\n", p->num);
        free(p);
}

//单循环链表的创建
LNode *CreateList(int n)
{
        LNode *p, *r, *list = NULL;
        int value;
        int i = 1;

        while(i<=n){
                scanf("%d", &value);
                p = (LNode *)malloc(sizeof(LNode));
                p->num = i++;
                p->key = value;
                p->next = NULL;

                if(!list)
                        list = p;
                else
                        r->next = p;
                r = p;
        }

        r->next = list;

        return list;
}
