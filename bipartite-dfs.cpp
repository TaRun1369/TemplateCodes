#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vector<ll> power2;

bool dfs(long long node, vector<vector<long long>>& adj, vector<bool>& vis, vector<long long>& col, ll& c0, ll& c1) {
    vis[node] = true;
    if (col[node] == 0) c0++;
    else c1++;
    
    for (auto it : adj[node]) {
        if (col[it] == col[node]) return false;
        else if (!vis[it]) {
            col[it] = !col[node];
            if (!dfs(it, adj, vis, col, c0, c1)) return false;
        }
    }

    return true;
}

long long main() {
    setIO();
    long long maxN = 3e5 + 5;
    power2.assign(maxN, 1);
    for (long long i = 1; i < maxN; i++) {
        power2[i] = (power2[i - 1] * 2) % mod;
    }

    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> col(n, -1);
        vector<bool> vis(n, 0);
        vector<vector<long long>> adj(n);

        for (long long i = 0; i < m; i++) {
            long long u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }

        ll ans = 1;
        for (long long i = 0; i < n; i++) {
            if (!vis[i]) {
                ll c0 = 0, c1 = 0;
                col[i] = 0;
                if (!dfs(i, adj, vis, col, c0, c1)) {
                    ans = 0;
                    break;
                } else {
                    ans = (ans * (power2[c0] + power2[c1]) % mod) % mod;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
