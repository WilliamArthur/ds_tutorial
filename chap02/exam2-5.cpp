#include "linklist.cpp"
void split(LinkList *&L,LinkList *&L1,LinkList *&L2)
{
	LinkList *p=L->next,*q,*r1;
	L1=L;					//L1利用原来L的头结点
	L=NULL;					//L置为空
	r1=L1;					//r1始终指向L1的尾结点
	L2=(LinkList *)malloc(sizeof(LinkList)); //创建L2的头结点
	L2->next=NULL;
	while (p!=NULL)
	{
		q=p->next;			//q指向*p的后续结点
		r1->next=p;
		r1=p;				//采用尾插法将*p插入L1中
		p=q->next;
		q->next=L2->next;	
		L2->next=q;			//采用头插法将*p插入L2中
	}
	r1->next=NULL;			//尾结点next置空
}
void main()
{
	LinkList *L,*L1,*L2;
	int n=10;
	char a[]={'a','b','c','d','e','f','g','h','i','j'};
	InitList(L);
	InitList(L1);
	InitList(L2);
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("L->L1,L2\n");
	split(L,L1,L2);
	printf("L1:");DispList(L1);
	printf("L2:");DispList(L2);
	DestroyList(L1);
	DestroyList(L2);
}
