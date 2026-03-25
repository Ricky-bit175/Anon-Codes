#include<stdio.h>
#define MAX 10
int rear=-1, front=-1;
int q[MAX];
void enqueue(int ele)
{
    if(rear==-1 && front==-1)
        ++front;
    else if(rear==MAX-1)
        return;
    q[++rear]=ele;
}
int dequeue()
{
    if(rear==-1 && front==-1)
        return -1;
    else if(front>rear)
    {
        rear=front=-1;
        return -1;
    }
    return q[front++];
}
void bfs(int n, int adj[][n], int sn)
{
    int visited[n],i,j;
    for(i=0;i<n;i++)
        visited[i]=0;
    enqueue(sn);
    visited[sn]=1;
    while(front<=rear)
    {
        int temp=dequeue();
        printf("%d ",temp);
        for(j=0;j<n;j++)
        {
            if(adj[temp][j]==1 && visited[j]==0)
            {
                enqueue(j);
                visited[j]=1;
            }
        }
    }
}
int main()
{
    int n,i,j,sn;
    printf("Enter the total number of vertices:");
    scanf("%d",&n);
    int adj[n][n];
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    printf("Enter the starting node:");
    scanf("%d",&sn);
    bfs(n,adj,sn);
}