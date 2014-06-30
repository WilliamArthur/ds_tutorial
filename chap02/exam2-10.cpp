#include "cdlinklist.cpp"
int delelem(DLinkList *&L,ElemType x)
{
	DLinkList *p=L->next; 
	while (p!=L && p->data!=x)
		p=p->next;
	if (p!=L)	//找到第一个元素值为x的结点
	{
		p->next->prior=p->prior;	//删除结点*p
		p->prior->next=p->next;
		free(p);
		return(1);
	}
	else return(0);
}
int delelem1(DLinkList *&L,ElemType x) //第2种方法
{
	DLinkList *pre=L,*p=pre->next; 
	while (p!=L && p->data!=x)
	{
		pre=p;
		p=p->next;
	}
	if (p!=L)	//找到第一个元素值为x的结点
	{
		p->next->prior=pre;	//删除结点*p
		pre->next=p->next;
		free(p);
		return(1);
	}
	else return(0);
}
void main()
{
	ElemType a[]={'1','2','2','4','2','3','5','2','1','4'};
	ElemType x='1';
	DLinkList *L;
	InitList(L);
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	printf("删除第一个结点值为%c的结点\n",x);
	if (delelem(L,x))
	{
		printf("L:");DispList(L);
	}
	else
		printf("循环双链表L中不存在元素值为%c的结点\n",x);
}
