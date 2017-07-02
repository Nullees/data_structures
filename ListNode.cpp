#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

typedef struct LNode{
int data;
struct LNode *next;
}LNode, *LinkedList;

LinkedList creatlist_tail_insert()
{
    int temp_receive;
    LinkedList L;
    L=(LinkedList)malloc(sizeof(LNode));
    L->next=NULL;
    LNode *s,*r;
    r=L;
    while(scanf("%d",&temp_receive)!=EOF)
    {
        s=(LinkedList)malloc(sizeof(LNode));
        s->data=temp_receive;
        r->next=s;
        r=s;
    }
    r->next = NULL;
    return L;
}

LinkedList creatlist_head_insert(LinkedList &L)
{
    int temp_receive;
    L=(LinkedList)malloc(sizeof(LNode));
    LNode *s;
    L->next=NULL;
    while(scanf("%d",&temp_receive)!=EOF)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=temp_receive;
        s->next=L->next;
        L->next=s;
    }

    return L;
}

int print_list(LinkedList &L)
{
    LNode *p;
    p=L->next;
    while(p->next!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
//    LNode *p = L->next;
//    while(p != NULL) {
//        cout << p->data;
//        p=p->next;
//    }
//    cout<<endl;
    return 1;
}

//LinkedList insert(LinkedList &L,)
//{
//
//}

int main()
{
    LinkedList lb=creatlist_tail_insert();;
//    creatlist_tail_insert(la);

    print_list(lb);

    return 0;
}

