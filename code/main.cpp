#include<iostream>
using namespace std;
const int length=100000;//���ֵ������ε������Ź���10000��
 
int main()
{
    int a[length];//����һ���������洢���
    for(int i=0; i<length; i++)//������������Ԫ����Ϊ0��
        a[i]=0;
    a[0] = 1;//��λ��Ϊ1��
    int n;
    cin>>n;//����Ҫ����׳˵���
    for(int i=2; i<=n; i++)
    {//��ʼ����׳�
        int jinwei = 0;
        int j =0;
        int temp;
        while(j<length)
        {//���ǽ�λ����λ�Ĵ���
            temp = jinwei;
            jinwei = (a[j]*i+jinwei)/10;
            a[j] = (a[j]*i + temp)%10;
            j++;
        }
    }
    int k=length-1;
    while(!a[k])
    {//��Ϊ0����ȫ�����������
        k--;
    }
    while(k>=0)
    {//�����ȷ�Ľ׳˽��
        cout<<a[k];
        k--;
    }
    return 0;
}
