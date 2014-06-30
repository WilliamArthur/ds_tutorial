#include <stdio.h>
#define MaxStud 50		//僥伏繁方恷謹葎50
#define MaxCour 300		//僥伏撹示芝村方恷謹葎50*6
struct stud1
{
	int no;			//僥催
	char name[10];	//侖兆
	int bno;		//萎催
};
struct stud2
{
	int no;			//僥催
	int cno;		//仁殻園催
	int deg;		//蛍方
};
double studavg(struct stud2 s2[],int m,int i)	//箔僥催葎i議僥伏議峠譲蛍
{
	int j,n=0;				//n葎僥催葎i議僥伏僉僥仁殻方
	double sum=0;			//僥催葎i議僥伏悳蛍
	for (j=0;j<m;j++)
		if (s2[j].no==i)	//僥催葎i扮由柴
		{
			n++;
			sum+=s2[j].deg;
		}
	return(sum/n);
}
double couravg(struct stud2 s2[],int m,int i)	//箔園催葎i議仁殻議峠譲蛍
{
	int j,n=0;				//n葎園催葎i議仁殻僉俐繁方
	double sum=0;			//園催葎i議仁殻悳蛍
	for (j=0;j<m;j++)
	{
		if (s2[j].cno==i)	//仁殻園催葎i扮由柴
		{
			n++;
			sum+=s2[j].deg;
		}
	}
	return(sum/n);
}
void allavg(struct stud1 s1[],int n,struct stud2 s2[],int m)	//箔僥伏峠譲蛍才仁殻峠譲蛍
{
	int i,j;
	printf("僥伏峠譲蛍:\n");
	printf("  僥催     侖兆 峠譲蛍\n");
	i=0;
	while (i<n)
	{
		j=s1[i].no;
		printf("%4d %10s %g\n",s1[i].no,s1[i].name,studavg(s2,m,j));
		i++;
	}
	printf("仁殻峠譲蛍:\n");
	for (i=1;i<=6;i++)
		printf(" 仁殻%d:%g\n",i,couravg(s2,m,i));
}

int main()
{
	int n=7;		//僥伏芝村繁方
	int m=21;		//僥伏撹示芝村方
	struct stud1 s1[MaxStud]={
		{1,"嫖遠",9901},
		{8,"装洗",9902},
		{34,"川哂",9901},
		{20,"蛎鯖",9902},
		{12,"藍謎",9901},
		{26,"境膿",9902},
		{5,"藍銅",9901}};
	struct stud2 s2[MaxCour]={	//号協仁殻議園催貫1欺6,揖匯僥伏撹示芝村銭偬贋慧
		{1,1,67},
		{1,2,98},
		{1,4,65},
		{8,1,98},
		{8,3,90},
		{8,6,67},
		{34,2,56},
		{34,4,65},
		{34,6,77},
		{20,1,68},
		{20,2,92},
		{20,3,64},
		{12,4,76},
		{12,5,75},
		{12,6,78},
		{26,1,67},
		{26,5,78},
		{26,6,62},
		{5,1,94},
		{5,2,92},
		{5,6,89}};
	allavg(s1,n,s2,m);
}
