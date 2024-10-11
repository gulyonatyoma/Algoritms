#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    int s, tt; cin >> s >> tt;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> d(n + 1, 1e18);
    vector<int> p(n + 1, -1);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int j = 0; j < g[v].size(); j++) {
            int to = g[v][j].first, len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    if (d[tt] == 1e18) {
        cout << -1;
    } else {
        vector<int> path;
        int cur = tt;
        while (p[cur] != -1) {
            path.push_back(cur);
            cur = p[cur];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        cout << d[tt] << ' ' << path.size() << '\n';
        for (auto it : path) {
            cout << it << ' ';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}
