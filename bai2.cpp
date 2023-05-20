// dfs vs do thi G <v,E> dang ma tran ke
#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,u,vs[100];
// truoc do phai memset mang vs[]=0
void BFS(int u){
	queue<int> q;
	q.push(u);
	while(q.size()>0)
	{
		int top=q.front();
		q.pop();
		cout<<top<<' ';
		vs[top]=1;
		for(int i=1;i<=n;i++)
		{
			if(vs[i]== 0 && a[top][i]==1){
				vs[i]=1;
				q.push(i);
			}
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
    BFS(2);
}