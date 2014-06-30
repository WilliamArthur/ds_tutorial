#include "btree.cpp"
int ancestor(BTNode *b,ElemType x)
{
	if (b==NULL)
		return(0);
	if (b->data==x)
		return(1);
	if (ancestor(b->lchild,x) || ancestor(b->rchild,x))
	{
		printf("%c ",b->data);
		return(1);
	}
}
void main()
{
	BTNode *b;
	ElemType x='G';
	CreateBTNode(b,"A(B(D(,G)),C(E,F))");
	printf("b:");DispBTNode(b);printf("\n");
	printf("结点%c的所有祖先:",x);
	ancestor(b,'G');printf("\n");
}
