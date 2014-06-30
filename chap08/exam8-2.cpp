#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF表示∞
void MatToList(MGraph g,ALGraph *&G)
//将邻接矩阵g转换成邻接表G
{
	int i,j,n=g.n;						//n为顶点数
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	for (i=0;i<n;i++)					//给邻接表中所有头结点的指针域置初值
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)					//检查邻接矩阵中每个元素
		for (j=n-1;j>=0;j--)
			if (g.edges[i][j]!=0)				//邻接矩阵的当前元素不为0
			{   
			   	p=(ArcNode *)malloc(sizeof(ArcNode));	//创建一个结点*p
				p->adjvex=j;
				p->info=g.edges[i][j];
				p->nextarc=G->adjlist[i].firstarc;		//将*p链到链表后
				G->adjlist[i].firstarc=p;
			}
	G->n=n;G->e=g.e;
}
void ListToMat(ALGraph *G,MGraph &g)
//将邻接表G转换成邻接矩阵g
{
	int i,n=G->n;
	ArcNode *p;
	for (i=0;i<n;i++) 
	{	
		p=G->adjlist[i].firstarc;
	    while (p!=NULL) 
		{	
			g.edges[i][p->adjvex]=p->info;
		    p=p->nextarc;
		}
	}
	g.n=n;g.e=G->e;
}
void DispMat(MGraph g)
//输出邻接矩阵g
{
	int i,j;
	for (i=0;i<g.n;i++)
	{
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%3s","∞");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)
//输出邻接表G
{
	int i;
	ArcNode *p;
	for (i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
/*以下主函数用作调试
void main()
{
	int i,j;
	MGraph g,g1;
	ALGraph *G;
	int A[MAXV][6]={
		{0,5,0,7,0,0},
		{0,0,4,0,0,0},
		{8,0,0,0,0,9},
		{0,0,5,0,0,6},
		{0,0,0,5,0,0},
		{3,0,0,0,1,0}};
	g.n=6;g.e=10;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	printf("\n");
	printf(" 有向图G的邻接矩阵:\n");
	DispMat(g);
	G=(ALGraph *)malloc(sizeof(ALGraph));
	printf(" 图G的邻接矩阵转换成邻接表:\n");
	MatToList(g,G);
	DispAdj(G);
	printf(" 图G的邻接表转换成邻接邻阵:\n");
	for (i=0;i<g.n;i++)
	   	for (j=0;j<g.n;j++)
			g1.edges[i][j]=0;
	ListToMat(G,g1);
	DispMat(g1);
	printf("\n");
}
*/