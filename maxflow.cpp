#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 1e9;
int n;
int max_flow = 0;
int c[MAXN][MAXN], f[MAXN][MAXN], path[MAXN], g[MAXN][MAXN];
// c la mang luu ma tran trong so ban dau
// f là mảng lưu luồng cực đại
// path là mảng lưu đường di từ s đến t theo bfs
// g là cập nhật giá trị của đồ thị g sau mỗi lần tăng luồng
// Hàm tìm đường tăng luồng từ đỉnh s đến đỉnh t trên đồ thị G
// bằng thuật toán BFS
bool find_path(int s, int t) {
    memset(path, -1, sizeof(path));
    queue<int> q;
    q.push(s);
    path[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (path[v] == -1 && g[u][v]>0 ) {
                path[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}
// Hàm tính luồng cực đại trên đồ thị G 
void timluongcucdai(int s, int t) {
    while (find_path(s, t)) {
        // Tính giá trị của đường tăng luồng delta
        int delta = INF;
        for (int v = t; v != s; v = path[v]) {
            int u = path[v];
            delta = min(delta, g[u][v]); // delta là giá trị trọng số min của các cạnh trong bfs đc xét
        }
        // Cập nhật ma trận luồng f[][] 
        for (int v = t; v != s; v = path[v]) {
            int u = path[v];
            if(c[u][v]==0){//ban dau ko co canh do , tuc la day  canh nguoc
                f[v][u]-= delta;
            }else{
                 f[u][v] += delta;//ban dau co tuc la canh thuan
            }
        }
        // cap nhat g[][] do thi co ca duong thuan va nguoc
        for(int v=t;v != s; v=path[v]){
            int u=path[v];
            g[u][v] -= delta;
            g[v][u] += delta;
        }
    }
    // Tính giá trị của luồng cực đại Val(f)
    max_flow=0;
    for (int v = 1; v <= n; v++) {
        max_flow += f[s][v];
    }
    
}
int main() {
    // Đọc dữ liệu vào
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    in>>n;
    for (int i = 1; i <= n; i++) {
        for(int j=1;j<=n;j++){
            in>>c[i][j];
            g[i][j]=c[i][j];
        }
    }
    int s, t;
    in>>s;
    in>>t;
    // Tính luồng cực đại trên đồ thị G 
    timluongcucdai(s, t);
    // cho vao file
    out << max_flow << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            out << f[i][j] << " ";
        }
        out << endl;
    }
    // out<<endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         out << g[i][j] << " ";
    //     }
    //     out << endl;
    // }
    in.close();
    out.close();
    
}
