#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int n, m;
int c[MAXN][MAXN], f[MAXN][MAXN], trace[MAXN], g[MAXN][MAXN];

// Hàm tìm đường tăng luồng từ đỉnh s đến đỉnh t trên đồ thị G
// bằng thuật toán BFS
bool find_path(int s, int t) {
    memset(trace, -1, sizeof(trace));
    queue<int> q;
    q.push(s);
    trace[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (trace[v] == -1 && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

// Hàm tính luồng cực đại trên đồ thị G bằng thuật toán Ford-Fulkerson
void ford_fulkerson(int s, int t) {
    while (find_path(s, t)) {
        // Tính giá trị của đường tăng luồng delta
        int delta = INF;
        for (int v = t; v != s; v = trace[v]) {
            int u = trace[v];
            delta = min(delta, c[u][v] - f[u][v]);
        }
        // Cập nhật ma trận luồng f[][] với đường tăng luồng delta
        for (int v = t; v != s; v = trace[v]) {
            int u = trace[v];
            f[u][v] += delta;
            f[v][u] -= delta;
        }
    }

    // Tính giá trị của luồng cực đại Val(f)
    int max_flow = 0;
    for (int v = 1; v <= n; v++) {
        if (f[s][v] > 0) max_flow += f[s][v];
    }

    // Ghi kết quả ra màn hình
    cout << max_flow << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Đọc dữ liệu vào
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        // int u, v, w;
        // cin >> u >> v >> w;
        // c[u][v] += w;
        for(int j=1;j<=m;j++){
            cin>>c[i][j];
        }
    }

    // Tính luồng cực đại trên đồ thị G bằng thuật toán Ford-Fulkerson
    ford_fulkerson(1, n);

    return 0;
}
