#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct linknode
{	
	ElemType data;				//数据域
	struct linknode *next;		//指针域
} LiStack;						//链栈类型定义
void InitStack(LiStack *&s)
{
	s=(LiStack *)malloc(sizeof(LiStack));
	s->next=NULL;
}
void ClearStack(LiStack *&s)
{
	LiStack *p=s->next;
	while (p!=NULL)
	{	
		free(s);
		s=p;
		p=p->next;
	}
	free(s);	//s指向尾结点,释放其空间
}
int StackLength(LiStack *s)
{
	int i=0;
	LiStack *p;
	p=s->next;
	while (p!=NULL)
	{	
		i++;
		p=p->next;
	}
	return(i);
}
int StackEmpty(LiStack *s)
{
	return(s->next==NULL);
}
void Push(LiStack *&s,ElemType e)
{
	LiStack *p;
	p=(LiStack *)malloc(sizeof(LiStack));
	p->data=e;
	p->next=s->next;		//插入*p结点作为第一个数据结点
	s->next=p;
}
int Pop(LiStack *&s,ElemType &e)
{
	LiStack *p;
	if (s->next==NULL)		//栈空的情况
		return 0;
	p=s->next;				//p指向第一个数据结点
	e=p->data;
	s->next=p->next;
	free(p);
	return 1;
}
int GetTop(LiStack *s,ElemType &e)
{
	if (s->next==NULL)		//栈空的情况
		return 0;
	e=s->next->data;
	return 1;
}
void DispStack(LiStack *s)
{
	LiStack *p=s->next;
	while (p!=NULL)
	{	
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}
