#include<bits/stdc++.h>
using namespace std;
int n, m,a[100][100];
int d[10000],c[10000],ts[10000];
int vs[100],t[100];
int tg,dd[100][100];
void khoitao()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            dd[i][j]=0;
        }
    }
}
void canh()
{
    m=0;
    int l=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j && dd[i][j]==0 && a[i][j]<10){
                d[l]=i;
                c[l]=j;
                ts[l]=a[i][j];
                dd[i][j]=-1;
                dd[j][i]=-1;
                m++;
                l++;
            }
        }
    }
    // cout<<m<<endl;
    // for(int i=1;i<=m;i++){
    //     cout<<d[i]<<" "<<c[i]<<" "<<ts[i]<<endl;
    // }
}
void KRUSKAL(int a[100][100]){
    for(int i=1;i<=m-1;i++){
        for(int j=i+1;j<=m;j++){
            if(ts[i]>ts[j]){
                swap(ts[i],ts[j]);
                swap(d[i],d[j]);
                swap(c[i],c[j]);
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     cout<<d[i]<<" "<<c[i]<<" "<<ts[i]<<endl;
    // }
    int wt=0,k=0;
    for(int i=1;i<=n;i++) vs[i]=0;

    for(int i=1;i<=m;i++)
    {
        // cout<<d[i]<<" "<<c[i]<<" ";
        if(!(vs[d[i]] != 0 && vs[d[i]]==vs[c[i]])){
            k++;
            t[k]=i;
            wt+=ts[i];
        }
        // cout<<k<<endl;
        if(k==n-1){
            cout<<wt<<endl;
            for(int j=1;j<=k;j++){
                cout<<d[t[j]]<<" "<<c[t[j]]<<endl;

            }
            return;
        }
        int u=d[i],v=c[i];
        if(vs[u]==0 && vs[v]==0){
            vs[u]=k;
            vs[v]=k;
        }else if(vs[u]==0 && vs[v]!= 0){
            vs[u]=vs[v];
        
        }else if(vs[u]!=0 && vs[v]==0) {
            vs[v]=vs[u];
        }
        else if(vs[u]<vs[v]){
            tg=vs[v];
            for(int j=1;j<=n;j++){
                if(vs[j]==tg) vs[j]=vs[u];
            }
        }else if(vs[v]<vs[u]){
            tg=vs[u];
            for(int j=1;j<=n;j++){
                if(vs[j]==tg) vs[j]=vs[v];
            }
        }
    }
    
} 
int main()
{
    khoitao();
    canh();
    KRUSKAL(a);
}