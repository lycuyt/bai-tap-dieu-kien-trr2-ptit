
#include<bits/stdc++.h>
using namespace std;
int n,a[100][100],u,vs[100],e[100],s[10000],ce[10000];
void DFS(int u){
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
// vo huong
int kt(int a[100][100], int n){
    int v;
    for(v=1;v<=n;v++)
    {
        vs[v]=0;
        e[v]=0;
    }
    DFS(1);
    int ok=1;
    for(v=1;v<=n;v++){
        if(vs[v]==0){
            ok=0;
            break;
        }
    }
    if(ok==0) return 0;
    int bl=0;
    for(v=1;v<=n;v++)
    {
        int deg=0;
        for(int i=1;i<=n;i++)
        {
            if(a[v][i]==1) deg++;

        }
        if(deg%2==1){
            bl++;
            if(bl>2) return 0;
            if(bl==1){
                u=v;
                ok=2;
            }
        }
    }
    return ok;
    
}
// co huong
int kt2(int a[100][100], int n)
{
    int  top=0,dem=0;
    top++;
    s[top]=1;
    dem++;
    while(top>0)
    {
        int v=s[top],ok=1;
        for(int i=1;i<=n;i++){
            if((a[v][i]==1 || a[i][v]==1) && vs[i]==0){
                top++;
                s[top]=i;
                vs[i]=1;
                dem++;
                ok=0;
                break;
            }
            
        }
        if(ok==1)top--;
    }
    if(dem<n) return 0;
    int x=0,y=0;
    for(int v=1;v<=n;v++){
        int d1=0,d2=0;
        for(int i=1;i<=n;i++){
            if(a[i][v]==1) d1++;
            if(a[v][i]==1) d2++;
        }
        if(d1!=d2) {
            if(abs(d1-d2)>1) return 0;
            else {
                if(x>0 && y>0 ) return 0;
                else {
                    if(d2>d1) x=v;
                    else y=v;
                }
            }
        }
    }
    if(x==0 && y==0) return 1;
    else {
        u=x;
        return 2;
    }
}
//vo huong
void ceu (int a[100][100],int n,int u)
{
    int top=0;
    top++;
    s[top]=u;
    int k=0;
    while(top>0){
        int v=s[top];
        int ok=1;
        for(int x=1;x<=n;x++){
            if(a[v][x]==1) {
                top++;
                s[top]=x;
                ok=0;
                a[v][x]=0;
                a[x][v]=0;
                break;
            }
        }
        if(ok==1){
            k++;
            ce[k]=v;
            top--;
        }
    }
    for(int v=k;v>0;v--) cout<<ce[v]<<" ";
}
//cco huong
void ceu2 (int a[100][100],int n,int u)
{
    int top=0;
    top++;
    s[top]=u;
    int k=0;
    while(top>0){
        int v=s[top];
        int ok=1;
        for(int x=1;x<=n;x++){
            if(a[v][x]==1) {
                top++;
                s[top]=x;
                ok=0;
                a[v][x]=0;
                break;
            }
        }
        if(ok==1){
            k++;
            ce[k]=v;
            top--;
        }
    }
    for(int v=k;v>0;v--) cout<<ce[v]<<" ";
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int u=5;
    cout<<kt2(a,n)<<endl;
    ceu2(a,n,u);

    
}