#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

class TreeAncestor {
private:
    vector<vector<int>> adj; 
    const int sz = 19;
    vector<int> dis;
    vector<vector<int>> parent;

public:
    TreeAncestor(int n) {
        adj.resize(n + 1);
        dis.assign(n + 1, 0);
        parent.assign(n + 1, vector<int>(sz, 0));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int par) {
        for (int i = 1; i < sz; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
        for (auto x : adj[node]) {
            if (x != par) {
                parent[x][0] = node;
                dis[x] = dis[node] + 1;
                dfs(x, node);
            }
        }
    }

    int getAncestor(int u, int d) {
        if (d == 0) return u;
        while (d) {
            int l = (int)log2(d);
            d -= (1 << l);
            u = parent[u][l];
        }
        if (u == 0) return -1;
        return u;
    }

    int LCA(int u, int v) {
        if (dis[u] < dis[v]) swap(u, v);
        for (int i = sz - 1; i >= 0; i--) {
            if (dis[parent[u][i]] >= dis[v]) {
                u = parent[u][i];
            }
        }
        if (u == v) return u;
        for (int i = sz - 1; i >= 0; i--) {
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }

    int getDist(int a, int b) {
        int lca = LCA(a, b);
        return dis[a] + dis[b] - 2 * dis[lca];
    }
};

void solve(){
    int n;
    cin>>n;
    TreeAncestor t(n+2);
    for(int i=1;i<n;i++){
    	int u,v;
    	cin>>u>>v;
    	t.addEdge(u,v);
    }
   t.dfs(1,-1);
	int q;
	cin>>q;
	//simple path a->b->c;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		int x=t.getDist(a,b);
		int y=t.getDist(a,c);
		int z=t.getDist(b,c);
	   if (x+y+z == 2 * max(max(x,y),z))cout<<"Yes"<<endl; 
		else cout<<"No"<<endl;
	}
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
