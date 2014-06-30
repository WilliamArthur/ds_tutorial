#include <stdio.h>
#include <math.h>
const int N=20;		//最多皇后个数
int q[N];			//存放皇后各皇后所在的行号
int cont=0;			//存放解个数
void print(int n)	//输出一个解
{
	int i;
	cont++;
	printf("  第%d个解:",cont);
	for (i=1;i<=n;i++)
		printf("%d ",q[i]);
	printf("\n");
}
int find(int i,int k)  //测试第k列的i行上能否摆放皇后
{
	int j;
	j=1;
	while (j<k)			//j=1到k-1是已放置了皇后的列
	{	
		if ((q[j]==i)  	//第j列皇后是否在i行上
			|| (abs(q[j]-i)==abs(j-k)))	//位置(q[j],j)与(i,k)是否同对角线
			return 0;
		j++;
	}
	return 1;
}
void place(int k,int n)			//第k个皇后放到第k列上
{
	if (k>n) 					//所有皇后放置结束
		print(n);
	else
		for (int i=1;i<=n;i++)	//在第k列上穷举每一个位置
			if (find(i,k))  
			{
				q[k]=i;place(k+1,n);
			}
}
void main()
{
	place(1,4);	//求解4皇后问题
}