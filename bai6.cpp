// dfs vs do thi G <v,E> dang ma tran ke
#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,u,vs[100],e[100];
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(q.size()>0)
	{
		int top=q.front();
		q.pop();
		
		vs[top]=1;
		for(int i=1;i<=n;i++)
		{
			if(vs[i]== 0 && a[top][i]==1){
				vs[i]=1;
                e[i]=top;
				q.push(i);
			}
		}
	}
}
void T_BFS(int a[100][100])
{
    for(int v=1;v<=n;v++) vs[v]=0;
    BFS(u);
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
    T_BFS(a);
}