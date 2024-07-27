#include<bits/stdc++.h>
using namespace std;
#define INF 1e17
#define int long long
int n,m,k;

vector<vector<int>> dist;
vector<vector<pair<int,int>>> g;


void dij(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        if(dist[node][k-1] < cost){
            continue;
        }

        for(auto it : g[node]){
            int v = it.first;
            int c = it.second;
            if(dist[v][k-1] > c+cost){
                dist[v][k-1] = c+cost;
                pq.push({dist[v][k-1],v});
            }
            sort(dist[v].begin(),dist[v].end());
        }
    }

}
int32_t main(){
    cin>>n>>m>>k;
    g.resize(n+1);
    dist.resize(n+1);
    for(int i = 1;i<=n;i++){
        dist[i].resize(k);
        for(int j = 0;j<k;j++){
            dist[i][j] = INF;
        }
    }

    dist[1][0] = 0;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    dij();

    for(int i = 0;i<k;i++){
        cout<<dist[n][i]<<" ";
    }

}