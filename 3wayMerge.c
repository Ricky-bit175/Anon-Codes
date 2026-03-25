/*
lb   mid1=lb+(ub-lb)/3  mid2=lb+2(ub-lb)/3  ub
*/
#include<stdio.h>
int c=0;
void merge(int lb, int mid1, int mid2, int ub, int a[])
{
    int i=lb, j=mid1+1,n=mid2+1;
    int b[100];
    int k=lb;
    //three parts left
    while(i<=mid1 && j<=mid2 && n<=ub)
    {
        if(a[i]<=a[j] && a[i]<=a[n])
            b[k++]=a[i++];
        else if(a[j]<=a[i] && a[j]<=a[n])
            b[k++]=a[j++];
        else 
            b[k++]=a[n++];
        c++;
    }
    //two parts left
    while(i<=mid1 && j<=mid2)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
        c++;
    }
    while(n<=ub && j<=mid2)
    {
        if(a[n]<=a[j])
            b[k++]=a[n++];
        else
            b[k++]=a[j++];
        c++;
    }
    while(n<=ub && i<=mid1)
    {
        if(a[n]<=a[i])
            b[k++]=a[n++];
        else
            b[k++]=a[i++];
        c++;
    }
    //one part left
    while(i<=mid1)
        b[k++]=a[i++];
    while(j<=mid2)
        b[k++]=a[j++];
    while(n<=ub)
        b[k++]=a[n++];
    //printing the elements in the original array
    for(i=lb;i<=ub;i++)
        a[i]=b[i];
}
void mergesort(int lb, int ub, int a[])
{
    
    int mid1=lb+(ub-lb)/3;
    int mid2=lb+(2*(ub-lb))/3;
    if(lb<ub)
    {
        mergesort(lb,mid1,a);
        mergesort(mid1+1,mid2,a);
        mergesort(mid2+1,ub,a);
        merge(lb,mid1,mid2,ub,a);
    }
}
int main()
{
int n,i,j;
printf("Enter the number of elements:");
scanf("%d",&n);
int a[n];
printf("Enter the elements:");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("Sorted Elements:");
mergesort(0,n-1,a);
for(i=0;i<n;i++)
    printf("%d ",a[i]);
printf("\nCount is: %d",c);
}