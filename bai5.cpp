// dfs vs do thi G <v,E> dang ma tran ke
#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,u,vs[100],e[100];
void DFS(int u){
    // cout<<u<<" ";
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
void T_DFS(int a[100][100])
{
    for(int v=1;v<=n;v++) vs[v]=0;
    DFS(u);
    int dem=0;
    for(int v=1;v<=n;v++){
        if(vs[v]==1) dem++;
    }
    if(dem==n){
        for(int v=1;v<=n;v++){
            if(e[v]!=0) cout<<v<<" "<<e[v]<<endl;
            
        }
    }else cout<<"Khong co cay khung ";
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    u=1;
    T_DFS(a);
}