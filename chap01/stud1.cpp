#include <stdio.h>
#define MaxStud 50	//僥伏繁方恷謹葎50
struct stud
{
	int no;			//僥催
	char name[10];	//侖兆
	int bno;		//萎催
	int deg1;		//仁殻1蛍方
	int deg2;		//仁殻2蛍方
	int deg3;		//仁殻3蛍方
	int deg4;		//仁殻4蛍方
	int deg5;		//仁殻5蛍方
	int deg6;		//仁殻6蛍方
};
double studavg(struct stud s[],int i)	//箔s[i]僥伏議峠譲蛍
{
	int m=0;			//s[i]僥伏僉僥仁殻方
	double sum=0;		//s[i]僥伏悳蛍
	if (s[i].deg1!=-1)
	{
		m++;
		sum+=s[i].deg1;
	}
	if (s[i].deg2!=-1)
	{
		m++;
		sum+=s[i].deg2;
	}
	if (s[i].deg3!=-1)
	{
		m++;
		sum+=s[i].deg3;
	}
	if (s[i].deg4!=-1)
	{
		m++;
		sum+=s[i].deg4;
	}
	if (s[i].deg5!=-1)
	{
		m++;
		sum+=s[i].deg5;
	}
	if (s[i].deg6!=-1)
	{
		m++;
		sum+=s[i].deg6;
	}
	return(sum/m);
}
double couravg(struct stud s[],int n,int i)	//箔及i壇仁殻議峠譲蛍
{
	int j,m=0;				//m葎及i壇仁殻僉俐繁方
	double sum=0;			//及i壇仁殻悳蛍
	switch(i)
	{
	case 1:for (j=0;j<n;j++)
			   if (s[j].deg1!=-1)
			   {
				   m++;
				   sum+=s[j].deg1;
			   }
			   break;
	case 2:for (j=0;j<n;j++)
			   if (s[j].deg2!=-1)
			   {
				   m++;
				   sum+=s[j].deg2;
			   }
			   break;
	case 3:for (j=0;j<n;j++)
			   if (s[j].deg3!=-1)
			   {
				   m++;
				   sum+=s[j].deg3;
			   }
			   break;
	case 4:for (j=0;j<n;j++)
			   if (s[j].deg4!=-1)
			   {
				   m++;
				   sum+=s[j].deg4;
			   }
			   break;
	case 5:for (j=0;j<n;j++)
			   if (s[j].deg5!=-1)
			   {
				   m++;
				   sum+=s[j].deg5;
			   }
			   break;
	case 6:for (j=0;j<n;j++)
			   if (s[j].deg6!=-1)
			   {
				   m++;
				   sum+=s[j].deg6;
			   }
			   break;
	}
	return(sum/m);
}
void allavg(struct stud s[],int n)	//箔僥伏峠譲蛍才仁殻峠譲蛍
{
	int i;
	printf("僥伏峠譲蛍:\n");
	printf("  僥催     侖兆 峠譲蛍\n");
	for (i=0;i<n;i++)
	{
		printf("%4d %10s %g\n",s[i].no,s[i].name,studavg(s,i));
	}
	printf("仁殻峠譲蛍:\n");
	for (i=1;i<=6;i++)
		printf(" 仁殻%d:%g\n",i,couravg(s,n,i));
}
int main()
{
	int n=7;		//僥伏芝村倖方
	struct stud s[MaxStud]={
		{1,"嫖遠",9901,67,98,-1,65,-1,-1},
		{8,"装洗",9902,98,-1,90,-1,67},
		{34,"川哂",9901,-1,56,-1,65,-1,77},
		{20,"蛎鯖",9902,68,92,64,-1,-1,-1},
		{12,"藍謎",9901,-1,-1,-1,76,75,78},
		{26,"境膿",9902,67,-1,-1,-1,78,62},
		{5,"藍銅",9901,94,92,-1,-1,-1,89}};
	allavg(s,n);

}
