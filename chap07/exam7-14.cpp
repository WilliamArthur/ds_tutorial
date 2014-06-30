#include "btree.cpp"
#define MaxSize 100
typedef char Elemtype;
typedef struct
{	
	ElemType data[MaxSize];	//存放二叉树结点值,其中空结点用'#'表示
	int n;					//存放data中的元素个数
} SqBTree;
BTNode *trans(SqBTree a,int i)
{
	BTNode *b;
	if (i>a.n)
		return(NULL);
	if (a.data[i]=='#')
		return(NULL);
	b=(BTNode *)malloc(sizeof(BTNode));
	b->data=a.data[i];
	b->lchild=trans(a,2*i);
	b->rchild=trans(a,2*i+1);
	return(b);
}
void main()
{
	int i,n=10;
	BTNode *b;
	SqBTree a;
	ElemType s[]="0ABCD#EF##G";
	for (i=0;i<=n;i++)
		a.data[i]=s[i];
	a.n=n;
	b=trans(a,1);
	printf("b:");DispBTNode(b);printf("\n");
}
