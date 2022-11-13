#include<stdio.h>
 int a[11];
void qsort(int l,int r)
{
    int i=l;
    int j=r;
    int mid=a[(l+r)/2];
    int temp;
    while (i<j)
    {
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}

int main()
{
    int n;
    scanf("%d",&n);
   
    int i;
    for (i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    qsort(1,n);
    for (i=1;i<=n;i++) {
        printf("%d |",a[i]);
    }
    return 0;
}
