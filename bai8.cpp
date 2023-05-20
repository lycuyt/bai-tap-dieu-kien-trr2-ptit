
#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
int d[100],e[100],vs[100];
void DIJKSTRA(int u) {
    for(int i=1;i<=n;i++) {
        d[i]=a[u][i];
        e[i]=u;
    }
    d[u]=0;e[u]=0;vs[u]=1;
    while(1)
    {
        int k=0;
        int min=32767;
        for(int i=1;i<=n;i++){
            if(vs[i]==0 && d[i]<min){
                k=i;
                min=d[i];
            }
            
        }
        if(k==0) return ;
        vs[k]=1;
        for(int i=1;i<=n;i++){
            if(vs[i]== 0 && d[i]> d[k]+a[k][i]){
                d[i]=d[k]+a[k][i];
                e[i]=u;
            }
        }
    }
    for(int v=1;v<=n;v++){
        if(v != u){
            cout<<d[v]<<" ";// d[v] la duong di ngan nhat xuat phat tu u den cac dinh v con lai
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
    DIJKSTRA(1);
    for(int i=2;i<=n;i++){
        cout<<d[i]<<endl;
    }
}