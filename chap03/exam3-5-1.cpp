#include "sqstack.cpp"
#include <string.h>
int Match(char exp[],int n)
{
	int i=0;
	char e;
	SqStack *st;
	InitStack(st);
	while (i<n)
	{
		if (exp[i]=='(')		//当前字符为左括号,将其进栈
			Push(st,exp[i]);
		else if (exp[i]==')')	//当前字符为右括号
		{
			if (GetTop(st,e)==1)
			{
				if (e!='(') return(0);	//括号不匹配时返回0
				else Pop(st,e);			//将栈顶元素出栈
			}
			else return(0);	//取栈元素下溢出时返回0
		}
		i++;	//继续处理其他字符
	}
	if (StackEmpty(st)==1) return(1);
	else return(0);
}
void main()
{
	char exp[]="(1+2*(5+3)/2)";
	if (Match(exp,strlen(exp))==1)
		printf("表达式%s括号配对\n",exp);
	else
		printf("表达式%s括号不配对\n",exp);
}