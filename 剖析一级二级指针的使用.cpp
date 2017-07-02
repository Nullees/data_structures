/*�������������Ϊ��ʹ�ö���ָ�����һ��ָ�������*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* ����LinkList */

//��ʼ����ͷ����һ��ָ�루�˷�ʽ��Ч��
Status InitList1(LinkList L)    //�ȼ���Node *L
{
    L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if(!L) /* �洢����ʧ�� */
            return ERROR;
    L->next=NULL; /* ָ����Ϊ�� */

    return OK;
}

//��ʼ����ͷ���ö���ָ��
Status InitList2(LinkList *L)   //�ȼ���Node **L
{
    *L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if(!(*L)) /* �洢����ʧ�� */
            return ERROR;
    (*L)->next=NULL; /* ָ����Ϊ�� */

    return OK;
}

//��ʼ����ͷ����һ��ָ������
Status InitList3(LinkList &L)   //�ȼ���Node *&L
{
    L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if(!L) /* �洢����ʧ�� */
            return ERROR;
    L->next=NULL; /* ָ����Ϊ�� */

    return OK;
}

//�������ʹ�ö���ָ��
Status ClearList1(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;           /*  pָ���һ����� */
    while(p)                /*  û����β */
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;        /* ͷ���ָ����Ϊ�� */
    return OK;
}

//�������ʹ��һ��ָ��
Status ClearList2(LinkList L)
{
    LinkList p,q;
    p=L->next;           /*  pָ���һ����� */
    while(p)                /*  û����β */
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;        /* ͷ���ָ����Ϊ�� */
    return OK;
}

//��������ʹ��һ��ָ��(�˷�ʽ��Ч)
Status DestroyList1(LinkList L)
{
    LinkList p,q;
    p=L->next;           /*  pָ���һ����� */
    while(p)                /*  û����β */
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(L);
    L=NULL;
    return OK;
}

//��������ʹ�ö���ָ��
Status DestroyList2(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;           /*  pָ���һ����� */
    while(p)                /*  û����β */
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(*L);
    *L=NULL;
    return OK;
}

//��������ʹ��һ��ָ������
Status DestroyList3(LinkList &L)
{
    LinkList p,q;
    p=L->next;           /*  pָ���һ����� */
    while(p)                /*  û����β */
    {
        q=p->next;
        free(p);
        p=q;
    }
    free(L);
    L=NULL;
    return OK;
}
/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;     /* ����һ���p */
    p = L->next;     /* ��pָ������L�ĵ�һ����� */
    j = 1;      /*  jΪ������ */
    while (p && j<i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
    {
        p = p->next;  /* ��pָ����һ����� */
        ++j;
    }
    if ( !p || j>i )
        return ERROR;  /*  ��i��Ԫ�ز����� */
    *e = p->data;   /*  ȡ��i��Ԫ�ص����� */
    return OK;
}


//���м����Ԫ�أ��ö���ָ��
Status ListInsert1(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    while (p && j < i)     /* Ѱ�ҵ�i����� */
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;   /* ��i��Ԫ�ز����� */
    s = (LinkList)malloc(sizeof(Node));  /*  �����½��(C���Ա�׼����) */
    s->data = e;
    s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
    p->next = s;          /* ��s��ֵ��p�ĺ�� */
    return OK;
}
//���м����Ԫ�أ���һ��ָ��
Status ListInsert2(LinkList L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p = L;
    j = 1;
    while (p && j < i)     /* Ѱ�ҵ�i����� */
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;   /* ��i��Ԫ�ز����� */
    s = (LinkList)malloc(sizeof(Node));  /*  �����½��(C���Ա�׼����) */
    s->data = e;
    s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
    p->next = s;          /* ��s��ֵ��p�ĺ�� */
    return OK;
}
//ɾ��һ��Ԫ�أ��ö���ָ��
Status ListDelete1(LinkList *L,int i,ElemType *e)
{
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while (p->next && j < i)  /* ����Ѱ�ҵ�i��Ԫ�� */
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR;           /* ��i��Ԫ�ز����� */
    q = p->next;
    p->next = q->next;            /* ��q�ĺ�̸�ֵ��p�ĺ�� */
    *e = q->data;               /* ��q����е����ݸ�e */
    free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
    return OK;
}
//ɾ��һ��Ԫ�أ���һ��ָ��
Status ListDelete2(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p,q;
    p = L;
    j = 1;
    while (p->next && j < i)  /* ����Ѱ�ҵ�i��Ԫ�� */
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR;           /* ��i��Ԫ�ز����� */
    q = p->next;
    p->next = q->next;            /* ��q�ĺ�̸�ֵ��p�ĺ�� */
    *e = q->data;               /* ��q����е����ݸ�e */
    free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
    return OK;
}
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    //InitList1(L);   //һ��ָ�뷽ʽ������ͷ��ʧ��
    //InitList2(&L);  //����ָ�뷽ʽ������ͷ���ɹ�
    InitList3(L);     //һ��ָ�����÷�ʽ������ͷ���ɹ�
    for(j=1;j<=7;j++)
            ListInsert2(L,1,j);
    printf("һ��ָ�뷽ʽ��L�ı�ͷ���β���1��7��");
    ListTraverse(L);

    ListInsert1(&L,3,12);
    printf("����ָ�뷽ʽ��L���м����12��");
    ListTraverse(L);

    ListInsert2(L,5,27);
    printf("һ��ָ����L���м����27��");
    ListTraverse(L);

    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);

    ListDelete1(&L,5,&e); /* ɾ����5������ */
    printf("����ָ�뷽ʽɾ����%d����Ԫ��ֵΪ��%d\n",5,e);
    printf("�������L��Ԫ�أ�");
    ListTraverse(L);

    ListDelete2(L,3,&e); /* ɾ����3������ */
    printf("һ��ָ�뷽ʽɾ����%d����Ԫ��ֵΪ��%d\n",3,e);
    printf("�������L��Ԫ�أ�");
    ListTraverse(L);

    printf("����ָ�뷽ʽ�������\n");
    ClearList1(&L);
    printf("�������L��Ԫ�أ�");
    ListTraverse(L);

    for(j=1;j<=7;j++)
            ListInsert2(L,j,j);
    printf("��L�ı�β���β���1��7��");
    ListTraverse(L);

    printf("һ��ָ�뷽ʽ�������\n");
    ClearList2(L);
    printf("�������L��Ԫ�أ�");
    ListTraverse(L);

    printf("��������\n");
    //DestroyList1(L);   //һ��ָ�뷽ʽ��������ʧ��,�ҳ�����������
    //DestroyList2(&L);  //����ָ�뷽ʽ���������ɹ�
    DestroyList3(L);     //һ��ָ�����÷�ʽ���������ɹ�

    return 0;
}
