int adj_mat[100][100],reach[20];
int n,f=0,r=-1;
int q[20], visited[20],v,stack[20];
int top=-1;
void read_graph ()
{
    int i, j;
    char reply;
    for ( i = 1 ; i <= n ; i++ )
    {
         for ( j = 1 ; j <= n ; j++ )
         {
              if ( i == j )
               {
                   adj_mat[i][j] = 0;
                   continue;
                }
              printf("\nVertices %d & %d are Adjacent ? (Y/N) :",i,j);
              scanf("%c", &reply);
              scanf("%c", &reply);
              if ( reply == 'y' || reply == 'Y' )
                   adj_mat[i][j] = 1;
              else
                   adj_mat[i][j] = 0;
         }
     }
}
void graph()
{

      int in_deg, out_deg, i, j;
      printf("\n How Many Vertices ? : ");
      scanf("%d", &n);
      read_graph();
      printf("\n Vertex ");
      for(i=1;i<=n;i++)
         printf("%d\t",i);
      printf("\n");
      for (i = 1; i <= n ; i++ )
        {
           printf("%d\t",i);
           for ( j = 1 ; j <= n ; j++ )
               printf("%d\t",adj_mat[i][j]);
           printf("\n");
        }
}
void bfs(int v) {
     for(int i = 1; i <= n; i++)
       if(adj_mat[v][i] && !visited[i])
     q[++r] = i;
     if(f <= r) {
        visited[q[f]] = 1;
        bfs(q[f++]);
           }
}
int pop()
{
   int d=stack[top];
   top--;
   return d;
}
void dfs(int v)
{
 int i,k=0;
 reach[v]=1;
 for(i=1;i<=n;i++)
      if(adj_mat[v][i] && !reach[i])
     {
         for(int j=0;j<=top;j++)
             if(i==stack[j])
                k++;
         if(k==0)
         {
             top++;
             stack[top]=i;
             k=0;
         }
     }
for(i=0;i<=top;i++)
  {
      int p=pop();
      printf("%d\t",p);
      reach[p]=1;
      dfs(p);
   }
}
void print()
{
    printf("\n Enter the starting vertex for BFS:");
    scanf("%d", &v);
    bfs(v);
    printf("BFS :\n");
    for(int i=1; i <= n; i++) {
    if(visited[i])
        printf("%d\t", i);
    else {
        printf("\n Bfs is not possible. Not all nodes are reachable");
        break;
         }
    }
    printf("\n Enter the starting vertex for DFS:");
    scanf("%d", &v);
    printf("\nDFS :\n");
    printf("%d\t",v);
    dfs(v);
}

void main()
{
    graph();
    print();
}
