#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 1000000
//a[0] 个位 
void mult(int a[], int b[], int res[])
{
	for(int i = 0; a[i]; i ++)
		for(int j = 0; b[j]; j++)
			{
				res[i + j] += a[i] * b[j];
			}
	int carry = 0;
	for(int i = 0; res[i]; i++) printf("%d ", res[i]);
	int i;
	for(i = 0; res[i]; i++)
	{
		int tmp = res[i];
		res[i] = (carry + res[i])%10;
		carry = (carry + tmp)/10;
	}
	if(carry) res[i] = carry;
}
int res[20000];
int main()
{
	//int a[10] = {9,8,7};//0 低位， 2高位 
	//int b[10] = {9,9,9};
	//int res[20] = {0};
	//mult(a, b, res); 然鹅并没有必要乘法也高精度， 毕竟不会输入20位以上的数字 
	int n;
	res[0] = 1;
	int high = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= high; j++){
			res[j] = i*res[j];
		}
		int carry = 0;
		int j = 0;
		for(j = 0; j <= high; j++){
			int tmp = res[j];
			res[j] = (carry + res[j])%SIZE;
			carry = (tmp + carry)/SIZE;
		}
		while(carry) 
		{
			res[j++] = carry%SIZE;
			carry /= SIZE;
			high++;
		}
	}
	printf("%d", res[high]);
	for(int i = high-1; i >= 0; i--)
	{
		
		if(res[i] < 10) printf("00000");
		else if(res[i] < 100) printf("0000");
		else if(res[i] < 1000) printf("000");
		else if(res[i] < 10000) printf("00");
		else if(res[i] < 100000) printf("0");
		printf("%d",res[i]);
	}
		
	printf("\n");
	return 0;
}

