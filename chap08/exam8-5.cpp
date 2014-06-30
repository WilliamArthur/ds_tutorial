#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define INF 32767       //INF表示∞
int visited[MAXV],path[MAXV];  //path[]用于存放回路路径,均为全局变量
void DFSPath(ALGraph *g ,int i,int j,int d)
{
	int v,k;
	ArcNode *p;
	visited[i]=1;
	d++;path[d]=i;
	if (i==j && d>2)         	//找到一条回路,则输出
	{	
		printf("  ");
		for (k=1;k<=d;k++)
			printf("%d ",path[k]);
		printf("\n");
	}
	p=g->adjlist[i].firstarc;  //找顶点i的第一个邻接顶点
	while (p!=NULL) 
	{	
		v=p->adjvex;          	//v为顶点i的邻接顶点
		if (visited[v]==0 || v==j) 
			DFSPath(g,v,j,d); 	//若该顶点未标记访问,或为vj,则递归访问之
		p=p->nextarc;           //找顶点i的下一个邻接顶点
	}
	visited[i]=0;              //取消访问标记,以使该顶点可重新使用
}
void FindCyclePath(ALGraph *G,int k)	//输出经过顶点k的所有回路
{
	printf("经过顶点%d的所有回路\n",k);
    DFSPath(G,k,k,0);
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
	int i,j;
	MGraph g;
	ALGraph *G;
	g.n=5;g.e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0}};	
	for (i=0;i<g.n;i++)	
		for (j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
	MatToList(g,G);
	for (i=0;i<g.n;i++) 		//visited数组置初值
		visited[i]=0;
	printf("图G:\n");DispAdj(G);//输出邻接表
	FindCyclePath(G,0);
	printf("\n");
}
