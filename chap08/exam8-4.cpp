#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF表示∞
int visited[MAXV];
void PathAll(ALGraph *G,int u,int v,int l,int path[],int d)
//d是到当前为止已走过的路径长度，调用时初值为-1
{
	int m,i;
	ArcNode *p;
	visited[u]=1;
	d++;						//路径长度增1
	path[d]=u;					//将当前顶点添加到路径中
	if (u==v && d==l)			//输出一条路径
	{	
		printf("  ");
		for (i=0;i<=d;i++)
			printf("%d ",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;  	//p指向顶点u的第一条弧的弧头结点
	while (p!=NULL)
	{	m=p->adjvex;			//m为u的邻接顶点
		if (visited[m]==0)		//若该顶点未标记访问,则递归访问之
			PathAll(G,m,v,l,path,d);
		p=p->nextarc;			//找u的下一个邻接顶点
	}
	visited[u]=0;				//恢复环境：使该顶点可重新使用
}
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
		if (p!=NULL) printf("%3d: ",i);
		while (p!=NULL)
		{
			printf("%3d",p->adjvex);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void main()
{ 
	int path[MAXV],u=1,v=4,d=3,i,j;
	MGraph g;
	ALGraph *G;
	g.n=5;g.e=6;
	int A[MAXV][MAXV]={
		{0,1,0,1,0},
		{1,0,1,0,0},
		{0,1,0,1,1},
		{1,0,1,0,1},
		{0,0,1,1,0}};	
	for (i=0;i<g.n;i++)		
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	MatToList(g,G);
	for (i=0;i<g.n;i++) 		//visited数组置初值
		visited[i]=0;
	printf("图G:\n");DispAdj(G);//输出邻接表
	printf("从%d到%d的所有长度为%d路径:\n",u,v,d);
	PathAll(G,u,v,d,path,-1);
	printf("\n");
}
