#include "dlinklist.cpp"
void sort(DLinkList *&L)	//双链表元素排序
{
	DLinkList *p=L->next,*q,*r;
	if (p!=NULL)					//若原双链表中有一个或以上的数据结点
	{
		r=p->next;					//r保存*p结点后继结点的指针
		p->next=NULL;				//构造只含一个数据结点的有序表
		p=r;
		while (p!=NULL)
		{	r=p->next;				//r保存*p结点后继结点的指针
			q=L;
			while (q->next!=NULL && q->next->data<p->data)	
				q=q->next;			//在有序表中找插入*p的前驱结点*q
			p->next=q->next;		//将*p插入到*q之后
			if (q->next!=NULL) q->next->prior=p;
			q->next=p;
			p->prior=q;
			p=r;
		}
	}
}
void main()
{
	ElemType a[]={'1','8','0','4','9','7','5','2','3','6'};
	DLinkList *L;
	InitList(L);
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("排序\n");
	sort(L);
	printf("L:");DispList(L);
}
