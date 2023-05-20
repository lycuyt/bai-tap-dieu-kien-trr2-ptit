// dfs vs do thi G <v,E> dang ma tran ke
#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,u,lt[100];
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(q.size()>0)
	{
		int top=q.front();
		q.pop();
		lt[top]=1;
		for(int i=1;i<=n;i++)
		{
			if(lt[i]== 0 && a[top][i]==1){
				lt[i]=1;
				q.push(i);
			}
		}
	}
}
int TPLT_BFS(int a[100][100]){
    int u;
    int k=0;
    for(u=1;u<=n;u++){
        lt[u]=0;
    }
    for( u=1;u<=n;u++){
        if(lt[u]==0){
            k++;
            BFS(u);
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
    // BFS(2);
    cout<<TPLT_BFS(a)<<endl;
}