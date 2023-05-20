
#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,e[100][100];
void FLOYD(int a[100][100]) {
    int d[100][100];
    int i, j, k;
    // Khởi tạo ma trận trọng số với các giá trị ban đầu
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            d[i][j] = a[i][j];
            e[i][j]=i;
        }
    }
    // Tìm đường đi ngắn nhất thông qua các đỉnh trung gian
    for (k = 1; k <= n; k++) {
        for (i = 1; i <=n; i++) {
            for (j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    e[i][j]=k;
                }
            }
        }
    }
    for (i = 1; i <=n; i++) {
        for (j = 1; j <=n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
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
    FLOYD(a);
    
}