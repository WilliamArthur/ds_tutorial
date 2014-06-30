#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct DNode  	//定义双链表结点类型
{
	ElemType data;
	struct DNode *prior;	//指向前驱结点
	struct DNode *next;		//指向后继结点
} DLinkList;
void InitQueue(DLinkList *&q)
{
	q=(DLinkList *)malloc(sizeof(DLinkList));
	q->prior=q;
	q->next=q;
}
int QueueEmpty(DLinkList *q)
{
	return(q->prior==q);
}
void enQueue(DLinkList *&q,ElemType e)
{
	DLinkList *p;
	p=(DLinkList *)malloc(sizeof(DLinkList *));
	p->data=e;
	q->prior->next=p;	//q->prior指向原来的尾结点
	p->prior=q->prior;
	p->next=q;
	q->prior=p;
}
int deQueue(DLinkList *&q,ElemType &e)
{
	DLinkList *p;
	if (q->prior==q)	//原队为空
		return(0);
	p=q->next;
	q->next=p->next;
	p->next->prior=q;
	e=p->data;
	free(p);
	return(1);
}
void main()
{
	ElemType e;
	DLinkList *q;
	InitQueue(q);
	printf("队空否:%d\n",QueueEmpty(q));
	printf("进队a,b,c,d,e\n");
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	enQueue(q,'d');
	enQueue(q,'e');
	printf("队空否:%d\n",QueueEmpty(q));
	printf("出队序列:");
	while (!QueueEmpty(q))
	{
	   deQueue(q,e);
	   printf("%c ",e);
	}
	printf("\n");
}


