#include<iostream>
using namespace std;
const int length=100000;//这个值经过多次调整，才过了10000！
 
int main()
{
    int a[length];//定义一个数组来存储结果
    for(int i=0; i<length; i++)//将数组中所有元素置为0；
        a[i]=0;
    a[0] = 1;//首位置为1；
    int n;
    cin>>n;//输入要计算阶乘的数
    for(int i=2; i<=n; i++)
    {//开始计算阶乘
        int jinwei = 0;
        int j =0;
        int temp;
        while(j<length)
        {//考虑进位及进位的处理
            temp = jinwei;
            jinwei = (a[j]*i+jinwei)/10;
            a[j] = (a[j]*i + temp)%10;
            j++;
        }
    }
    int k=length-1;
    while(!a[k])
    {//将为0的数全跳过，不输出
        k--;
    }
    while(k>=0)
    {//输出正确的阶乘结果
        cout<<a[k];
        k--;
    }
    return 0;
}
