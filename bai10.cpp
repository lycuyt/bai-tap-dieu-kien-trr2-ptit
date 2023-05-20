#include<bits/stdc++.h>
using namespace std;
int n, a[100][100];
int vs[100], d[100],e[100];
void khoitao()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}
void PRIM(int a[100][100],int u) {
    for(int i=1;i<=n;i++) {
        d[i]=a[u][i];
        e[i]=u;
        vs[i]=0;
    }
    d[u]=0;e[u]=0;vs[u]=1;
    int wt=0;
    int dem=1;
    while(dem<n)
    {
        int k=0;
        int min=30000;
        for(int i=1;i<=n;i++){
            if(vs[i]==0 && d[i]<min){
                k=i;
                min=d[i];
            }
            
        }
        if(k==0) {
            cout<<"khong co cay khung";
            return;
        }
        vs[k]=1;
        wt+=a[e[k]][k];
        
        for(int i=1;i<=n;i++){
            if(vs[i]== 0 && d[i]> a[k][i]){
                d[i]=a[k][i];
                e[i]=k;
            }
        }
        dem++;
       
    }
    
    cout<<wt<<endl;
        for(int v=1;v<=n;v++){
            if(e[v]!=0){
                cout<<v<<" "<< e[v]<<endl;
                
            }
             
        }
    
}
int main()
{
    khoitao();
    PRIM(a,1);
}