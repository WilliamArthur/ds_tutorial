#include "sqlist.cpp"   //假设线性表以顺序表表示
void main()
{
	SqList *L;
	ElemType e;
	InitList(L);
	ListInsert(L,1,'a');
	ListInsert(L,2,'c');
	ListInsert(L,3,'a');
	ListInsert(L,4,'d');
	ListInsert(L,5,'b');
	printf("ListLength(L)=%d\n",ListLength(L));
	printf("ListEmpty(L)=%d\n",ListEmpty(L));
	GetElem(L,3,e);
	printf("e=%c\n",e);
	printf("LocateElem(L,'a')=%d\n",LocateElem(L,'a'));
	ListInsert(L,4,'e');
	DispList(L);
	ListDelete(L,3,e);
	DispList(L);
	DestroyList(L);
}