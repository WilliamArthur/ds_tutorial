int f(BTNode *b)
{
	if (b==NULL) 
		return(0);	//空二叉树的结点个数为0
	else
		return(f(b->lchild)+f(b->rchild)+1);
}
