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
int mgpath(int xi,int yi,int xe,int ye)	//求解路径为:(xi,yi)->(xe,ye)
{
	struct 
	{	
		int i;					//当前方块的行号
		int j;					//当前方块的列号
		int di;					//di是下一可走方位的方位号
	} st[MaxSize];				//定义栈
	int top=-1;					//初始化栈指针
	int i,j,k,di,find;
	top++;      				//初始方块进栈
	st[top].i=xi;st[top].j=yi;
	st[top].di=-1;mg[1][1]=-1; 
	while (top>-1)				//栈不空时循环
	{
		i=st[top].i;j=st[top].j;di=st[top].di;  //取栈顶方块
		if (i==xe && j==ye)		//找到了出口,输出路径
		{ 
			printf("迷宫路径如下:\n");
			for (k=0;k<=top;k++)
			{
				printf("\t(%d,%d)",st[k].i,st[k].j);
				if ((k+1)%5==0)	//每输出每5个方块后换一行
					printf("\n");  
			}
			printf("\n");
			return(1);		//找到一条路径后返回1
		}
		find=0;
		while (di<4 && find==0)		//找下一个可走方块
		{	
			di++;
			switch(di)
			{
			case 0:i=st[top].i-1;j=st[top].j;break;
			case 1:i=st[top].i;j=st[top].j+1;break;
			case 2:i=st[top].i+1;j=st[top].j;break;
			case 3:i=st[top].i,j=st[top].j-1;break;
			}
			if (mg[i][j]==0) find=1;//找到下一个可走相邻方块
		}
		if (find==1)				//找到了下一个可走方块
		{	
			st[top].di=di;			//修改原栈顶元素的di值
			top++;					//下一个可走方块进栈
			st[top].i=i;st[top].j=j;st[top].di=-1;
			mg[i][j]=-1;			//避免重复走到该方块
		}
		else						//没有路径可走,则退栈
		{	
			mg[st[top].i][st[top].j]=0;//让该位置变为其他路径可走方块
			top--;					//将该方块退栈
		}
	}
	return(0);	//表示没有可走路径,返回0
}
void main()
{
	mgpath(1,1,M,N);
}