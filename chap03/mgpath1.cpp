#include <stdio.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2]=
{	
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
struct 
{	int i,j;			//方块的位置
	int pre;			//本路径中上一方块在Qu中的下标
} Qu[MaxSize];
int front=-1,rear=-1;	//分别为队首指针和队尾指针
void print(int front)	//从队列中输出路径
{
	int k=front,j,ns=0;
	printf("\n");
	do				//反向找到最短路径,将该路径上的方块的pre成员设置成-1
	{	j=k;
		k=Qu[k].pre;
		Qu[j].pre=-1;
	} while (k!=0);
	printf("迷宫路径如下:\n");
	k=0;
	while (k<MaxSize)  //正向搜索到pre为-1的方块,即构成正向的路径
	{	if (Qu[k].pre==-1)
		{	ns++;
			printf("\t(%d,%d)",Qu[k].i,Qu[k].j);
			if (ns%5==0) printf("\n");	//每输出每5个方块后换一行
		}
		k++;
	}
	printf("\n");
}
int mgpath(int xi,int yi,int xe,int ye)					//搜索路径为:(xi,yi)->(xe,ye)
{
	int i,j,find=0,di;
	rear++;
	Qu[rear].i=xi;Qu[rear].j=yi;	//(xi,yi)进队
	Qu[rear].pre=-1;	
	mg[1][1]=-1;					//将其赋值-1,以避免回过来重复搜索
	while (front<=rear && !find)	//队列不为空且未找到路径时循环
	{	
		front++;					//出队,由于不是环形队列，该出队元素仍在队列中
		i=Qu[front].i;j=Qu[front].j;
		if (i==xe && j==ye)			//找到了出口,输出路径
		{	
			find=1;				
			print(front);			//调用print函数输出路径
			return(1);				//找到一条路径时返回1
		}
		for (di=0;di<4;di++)		//循环扫描每个方位,把每个可走的方块插入队列中
		{	
			switch(di)
			{
			case 0:i=Qu[front].i-1;j=Qu[front].j;break;
			case 1:i=Qu[front].i;j=Qu[front].j+1;break;
			case 2:i=Qu[front].i+1;j=Qu[front].j;break;
			case 3:i=Qu[front].i,j=Qu[front].j-1;break;
			}
			if (mg[i][j]==0)
			{	rear++;				//将该相邻方块插入到队列中
				Qu[rear].i=i;Qu[rear].j=j;
				Qu[rear].pre=front; //指向路径中上一个方块的下标
				mg[i][j]=-1;		//将其赋值-1,以避免回过来重复搜索
			}
		}
     }
     return(0);						//未找到一条路径时返回1
}
void main()
{
	mgpath(1,1,M,N);
}