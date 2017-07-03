#include<cstdio>
#include<cstdlib>
#include<iostream>

typedef struct  LNode
{
	/* 定义结点结构体 */
	int data;
	struct LNode *next;
}LNode,*LinkList;

LinkList creatlist_tail_insert(LinkList &L)
{
	LNode *s,*r;
	int temp;

	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	r=L;
	while(scanf("%d",&temp)!=EOF)
	{
	    s=(LNode *)malloc(sizeof(LNode));
		s->data=temp;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return L;

}

LinkList creatlist_head_insert(LinkList &L)
{
	int temp;
	LNode *s;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	while(scanf("%d",&temp)!=EOF)
	{
		s->data=temp;
		s->next=L->next;
		L->next=s;
	}
	return L;
}

int printlist(LinkList &L)
{
    printf("****test****\n");
	LNode *p;
	p=L->next;
	while(p->next!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	return 1;
}

int listlength(LinkList L)
{

	LNode *p;
	int count=0;
	p=L;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

LNode *locate(LinkList L,int loc)
{
	LNode *p=L;
	while(loc>0)
	{
		p=p->next;
		loc--;
	}
	return p;
}

LinkList deletenode(LinkList L,int loc)
{
	LNode *p=locate(L,loc-1);
    LNode *temp;
    temp=p->next;
    p->next=p->next->next;
    free(temp);
	return L;
}

LinkList insertlist(LinkList L,int loc,int data)
{
	LNode *p=locate(L,loc-1);
	LNode *s;
	s=(LNode *)malloc(sizeof(LNode));
	s->data=data;
	s->next=p->next;
	p->next=s;
	return L;
}

LinkList mergelist(LinkList L1,LinkList L2)
{
    LinkList LN;
    LN=(LinkList)malloc(sizeof(LNode));
    LN->next=NULL;
    LNode *p=LN;
    LNode *s;
    LNode *p1=L1->next;
    LNode *p2=L2->next;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data <= p2->data)
        {
            s=(LNode *)malloc(sizeof(LNode));
            s->data=p1->data;
            s->next=p->next;
            p->next=s;
            p=s;
            p1=p1->next;
        }
        else
        {
            s=(LNode *)malloc(sizeof(LNode));
            s->data=p2->data;
            s->next=p->next;
            p->next=s;
            p=s;
            p2=p2->next;
        }
    }
    if(p1==NULL && p2!=NULL)
        p->next=p2;
    else if(p1!=NULL && p2==NULL)
        p->next=p1;
    else
        p->next=NULL;
    return LN;
}

int main()
{
	/* code */
	int insertloc,insertval,deleteloc;
	LinkList LL=creatlist_tail_insert(LL);
	printlist(LL);
	LinkList LL1=creatlist_tail_insert(LL1);
	printlist(LL1);
	LinkList LN=mergelist(LL,LL1);
	printf("合并以后的新链表为：\n");
	printlist(LN);
//	printf("LL链表的长度为：%d",listlength(LL));
//	printf("请输入插入的位置和数值，【注】：位置是[1，%d]区间中的数：",listlength(LL));
//	scanf("%d%d",&insertloc,&insertval);
//	insertlist(LL,insertloc,insertval);
//	printf("插入以后的新链表是：\n");
//	printlist(LL);
//	printf("请输入删除的位置，【注】：位置是[1，%d]区间中的数：",listlength(LL));
//	scanf("%d",&deleteloc);
//	deletenode(LL,deleteloc);
//	printf("删除以后的新链表是：\n");
//	printlist(LL);
	return 0;
}

