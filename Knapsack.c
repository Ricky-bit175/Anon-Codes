#include<stdio.h>
struct items
{
    int p, w;
    float r;
    int num;
};

void print(struct items arr[], int n, int m)
{
    int i,u=m;
    float profit=0.0;
    for(i=0;i<n;i++)
    {
        if(u>0 && arr[i].w<=u)
        {
            u=u-arr[i].w;
            profit=profit+arr[i].p;
            printf("x%d: 1 unit\n",arr[i].num+1);
        }
        else if(u>0)
        {
            profit=profit+(u/(float)arr[i].w)*arr[i].p;
            printf("x%d: %d/%d unit\n",arr[i].num+1,u,arr[i].w);
            u=0;
        }
        else
            break;
    }
    printf("Profit: %.2f\n",profit);
}
int main()
{
    int n,i,m,j;
    printf("Enter the total number of items: ");
    scanf("%d",&n);
    struct items arr[n];
    printf("Enter the weight and profit of items repectively: ");
    for ( i = 0; i < n ; i++)
    {
        printf("Item %d:",i+1);
        scanf("%d",&arr[i].w);
        scanf("%d",&arr[i].p);
        arr[i].r=arr[i].p/(float)arr[i].w;
        arr[i].num=i;
    }
    printf("Enter the total capacity of the knapsack: ");
        scanf("%d",&m);
    //MAX PROFIT
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].p<arr[j+1].p)
            {
                struct items temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Acocrding to Max Profit:\n");
    print(arr,n,m);
    //MIN W RATIO
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].w>arr[j+1].w)
            {
                struct items temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
     printf("Acocrding to Min Weight:\n");
    print(arr,n,m);
    //MAX P/W RATIO
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].r<arr[j+1].r)
            {
                struct items temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
     printf("Acocrding to Max Profit/Weight Ratio:\n");
    print(arr,n,m);
}