#include "linklist.cpp"
void sort(LinkList *&L)
{
	LinkList *p=L->next,*q,*r;
	if (p!=NULL)				//若原单链表中有一个或以上的数据结点
	{	r=p->next;				//r保存*p结点后继结点的指针
		p->next=NULL;			//构造只含一个数据结点的有序表
		p=r;
		while (p!=NULL)
		{	r=p->next;			//r保存*p结点后继结点的指针
			q=L;
			while (q->next!=NULL && q->next->data<p->data)	
				q=q->next;		//在有序表中找插入*p的前驱结点*q
			p->next=q->next;	//将*p插入到*q之后
			q->next=p;
			p=r;				//扫描原单链表余下的结点
		}
	}
}
void main()
{
	LinkList *L;
	int n=10;
	char a[]={'1','3','2','9','0','4','7','6','5','8'};
	InitList(L);
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("排序\n");
	sort(L);
	printf("L:");DispList(L);
	DestroyList(L);
}

