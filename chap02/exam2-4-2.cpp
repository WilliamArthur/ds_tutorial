#include "sqlist.cpp"   //这里将整数用字符型表示
void move2(SqList *&L)
{
	int i=0,j=L->length-1;
	ElemType pivot=L->data[0];	//以data[0]为基准
	while (i!=j)  				//从顺序表两端交替向中间扫描,直至i=j为止
	{	
		while (j>i && L->data[j]>pivot) 
			j--;  				//从右向左扫描,找一个关键字小于pivot的data[j]
		L->data[i]=L->data[j];//找到这样的data[j],放入data[i]处
		while (i<j && L->data[i]<pivot) 
			i++;				//从左向右扫描,找一个关键字大于pivot的记录data[i]
		L->data[j]=L->data[i];//找到这样的data[i],放入data[j]处
	}
	L->data[i]=pivot;
}
void main()
{
	SqList *L;
	InitList(L);
	//构造L={'3','5','6',1','4','2','7','9','8','0'}
	ListInsert(L,1,'3');
	ListInsert(L,2,'5');
	ListInsert(L,3,'6');
	ListInsert(L,4,'1');
	ListInsert(L,5,'4');
	ListInsert(L,6,'2');
	ListInsert(L,7,'7');
	ListInsert(L,8,'9');
	ListInsert(L,9,'8');
	ListInsert(L,10,'0');
	printf("L:");DispList(L);
	printf("执行移动运算\n");
	move2(L);
	printf("L:");DispList(L);
	DestroyList(L);
}
