#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) {
                dist[i][j] = 1e9;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int maxm = -1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] != 1e9) {
                maxm = max(maxm, dist[i][j]);
            }
        }
    }
    cout << maxm;
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