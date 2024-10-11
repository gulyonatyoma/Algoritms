#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

struct edge {
    int a, b, cost;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<edge> e;
    for (int i = 0; i < m; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        e.push_back({u, v, cost});
    }
    vector<int> d(n + 1, INF);
    int s = 1;
    d[s] = 0;
    vector<int> par(n + 1, -1);
    for (;;) {
        bool any = false;
        for (int j = 0; j < m; j++) {
            if (d[e[j].a] < INF) {
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    par[e[j].b] = e[j].a;
                    any = true;
                }
            }
        }
        if (!any) {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            cout << 30000 << ' ';
        } else {
            cout << d[i] << ' ';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}