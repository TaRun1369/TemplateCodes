
#include<bits/stdc++.h>
using namespace std;
vector<long long> tree[200001];
long long ancestor[200001][21];
long long level[200001];
long long ans[200001];
void height(long long curr,long long par){
    
    for(long long child : tree[curr]){
        if(child != par){
            level[child] = level[curr] + 1;
            height(child,curr);
        }
    }
}
void preprocess(long long curr,long long par){
    ancestor[curr][0] = par;
    for(long long i = 1;i<21;i++){
        if(ancestor[curr][i-1] != -1){
        ancestor[curr][i] = ancestor[ancestor[curr][i-1]][i-1];
        }
        else ancestor[curr][i] = -1;
    }
    
    for(long long child : tree[curr]){
        if(child != par){
            preprocess(child,curr);
        }
    }
}
long long query(long long node,long long k){
    if(node == -1) return -1;
    if(k == 0) return node;

    for(long long i = 20;i>=0;i--){
        if(k & (1 << i)){
            return query(ancestor[node][i],k - (1 << i));
        }
    }
}
long long lca(long long x,long long y){
    long long diff = abs(level[x] - level[y]);
        
        if(level[x] > level[y]){
             x = query(x,diff);
        }
        else{
             y = query(y,diff);
        }
        // cout<<" lavda - "<<x<<y<<endl;
        if(x == y) {return x;}

        for(long long i = 20;i>=0;i--){
            if(ancestor[x][i] != ancestor[y][i]){
                x = ancestor[x][i];
                y = ancestor[y][i];
            }
        }
        return query(x,1);
}
void dfs_for_ans(long long node,long long par){
    long long x = ans[node];

    for(long long child : tree[node]){
        if(child != par){
            dfs_for_ans(child,node);
            x += ans[child];
        }
    }
    ans[node] = x;
}
long long main() {
    long long n,q;
    cin>>n>>q;

    for(long long i=2;i<=n;i++){
        long long x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    // vector<pair<long long,long long>> queries(q);
    height(1,-1);
    preprocess(1,-1);
    // vector<long long> ans(n + 1,0);
    for(long long i = 0;i<q;i++){
        long long x,y;
        cin>>x>>y;
        // cout<<"query - "</<x<<y<<endl;
        ans[x] += 1;
        ans[y] += 1;
        long long LCA = lca(x,y);
        ans[LCA] -=1;
        long long lcabaap = query(LCA,1);
        if(lcabaap != -1)
        ans[lcabaap] -=1;
    }
    dfs_for_ans(1,-1);
    for(long long i = 1;i<=n;i++) cout<<ans[i]<<" ";
}
