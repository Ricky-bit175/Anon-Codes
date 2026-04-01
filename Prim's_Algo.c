#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

int minweight(bool visited[], int weight[],int V)
{
    int i, mw=INT_MAX, mindex=-1;
    for(i=0;i<V;i++)
    {
        if(visited[i]==false && mw>weight[i])
        {
            mw=weight[i];
            mindex=i;
        }
    }
    return mindex;
}

void prim(int V, int adj[][V], char ch)
{
    bool visited[V];
    int weight[V], parent[V], order[V],ord=0, start, i,j,u, tweight=0;
    for(i=0;i<V;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    start=ch-'A';
    weight[start]=0;
    parent[start]=-1;
    for(i=0;i<V;i++)
    {
        u=minweight(visited,weight,V);
        visited[u]=true;
        if(parent[u]!=-1)
            order[ord++]=u;
        for(j=0;j<V;j++)
        {
            if(adj[u][j] && visited[j]==false && adj[u][j]<weight[j])
            {
                weight[j]=adj[u][j];
                parent[j]=u;
            }
        }
    }
    printf("Edge\tWeight\n");
    for(i=0;i<ord;i++)
    {
        int child=order[i];
        int pa=parent[child];
        char c='A'+child;
        char p='A'+pa;
        printf("%c-%c\t%d\n",p,c,adj[child][pa]);
        tweight+=adj[child][pa];
    }
    printf("Total Weight: %d\n",tweight);

}
int main()
{
    int V,i,j;
    char ch;
    printf("Enter the total number of vertices: ");
    scanf("%d",&V);
    printf("Enter the adjacency Matrix:\n");
    int adj[V][V];
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            scanf("%d",&adj[i][j]);
    printf("Enter starting node: ");
    scanf(" %c",&ch);
    prim(V,adj,ch);
}
