
// dfs vs do thi G <v,E> dang ma tran ke
#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,u,lt[100],e[100];
// dfs voi dinh u
void DFS(int u){
    lt[u]=1;
    for(int v=1;v<=n;v++)
    {
        if(lt[v]==0 && a[u][v]==1)
        {
            e[v]=u;
            DFS(v);
        }
    }
}
// tim so thanh phan lien thong dua vao dfs
int TPLT_DFS(int a[100][100]){
    int u;
    int k=0;// bien nay dung de dem so thanh phan lien thong
    for(u=1;u<=n;u++){// memset mang lt[]=0
        lt[u]=0;
    }
    for(u=1;u<=n;u++){
        if(lt[u]==0){//neu dinh u chua duoc xet thi ta dfs cho dinh u
            k++;// tang so tplt
            DFS(u);
        }
    }
    return k;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    // memset(vs,0,sizeof(vs));
    // DFS(1);
    cout<<TPLT_DFS(a)<<endl;
}