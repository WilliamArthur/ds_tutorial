#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct qnode
{	
	ElemType data;
	struct qnode *next;
} QNode;		//链队数据结点类型定义
typedef struct
{	
	QNode *front;
	QNode *rear;
} LiQueue;			//链队类型定义
void InitQueue(LiQueue *&q)
{
	q=(LiQueue *)malloc(sizeof(LiQueue));
	q->front=q->rear=NULL;
}
void ClearQueue(LiQueue *&q)
{
	QNode *p=q->front,*r;
	if (p!=NULL)		//释放数据结点占用空间
	{
		r=p->next;
		while (r!=NULL)
		{	
			free(p);
			p=r;r=p->next;
		}
	}
	free(q);			//释放链队结点占用空间
}
int QueueEmpty(LiQueue *q)
{
	if (q->rear==NULL)
		return 1;
	else
		return 0;
}
void enQueue(LiQueue *&q,ElemType e)
{
	QNode *s;
    	s=(QNode *)malloc(sizeof(QNode));
	s->data=e;
	s->next=NULL;
    if (q->rear==NULL)		//若链队为空,则新结点是队首结点又是队尾结点
		q->front=q->rear=s;
	else
	{	q->rear->next=s;  	//将*s结点链到队尾,rear指向它
		q->rear=s;
	}
}
int deQueue(LiQueue *&q,ElemType &e)
{
	QNode *t;
	if (q->rear==NULL)		//队列为空
		return 0;
	t=q->front;				//t指向第一个数据结点
	if (q->front==q->rear)  //队列中只有一个结点时
		q->front=q->rear=NULL;
	else					//队列中有多个结点时
		q->front=q->front->next;
	e=t->data;
    	free(t);
	return 1;
}

