#include <stdio.h>
#define LEN 100000
void factorial(int* p,int x);
int main(int argc,char* argv[])
{
	int num[LEN]={0};
	int x,i,j;
	int* p=num;
	
	scanf("%d",&x);
	factorial(p,x);
	
	for(j=LEN-1;j>=0;j--)
    if(*(p+j)>0) break;
    for(i=j;i>=0;i--)
    printf("%d",*(p+i));
}
void factorial(int* p,int x)//计算x的阶乘，存入数组num
{
	int sum,i,j,c;
	*p=1;
	for(i=2;i<=x;i++)
	{
		c=0;//c表示进位
		for(j=0;j<LEN;j++)
		{
			sum=*(p+j)*i+c;
           	*(p+j)=sum%10;
           	c=sum/10;
		}
	}
}

