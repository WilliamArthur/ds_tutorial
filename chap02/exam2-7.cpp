#include "dlinklist.cpp"
void reverse(DLinkList *&L)	//双链表元素逆置
{
	DLinkList *p=L->next,*q;
	L->next=NULL;					
	while (p!=NULL)
	{
		q=p->next;			//q指向*p的后续结点
		p->next=L->next;	//采用头插法将*p结点插入到双链表中
		if (L->next!=NULL) L->next->prior=p;
		L->next=p;
		p->prior=L;
		p=q;
	}
}
void main()
{
	ElemType a[]={'1','8','0','4','9','7','5','2','3','6'};
	DLinkList *L;
	InitList(L);
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("逆置\n");
	reverse(L);
	printf("L:");DispList(L);
}
