// dfs vs do thi G <v,E> dang ma tran ke
#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,u,vs[100],e[100];
// truoc do phai memset mang vs[]=0
void DFS(int u){
    cout<<u<<" ";
    vs[u]=1;
    for(int v=1;v<=n;v++)
    {
        if(vs[v]==0 && a[u][v]==1)
        {
            e[v]=u;
            DFS(v);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    memset(vs,0,sizeof(vs));
    DFS(1);
}
