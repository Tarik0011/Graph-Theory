//https://cses.fi/problemset/task/1132/
/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/ 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define endl '\n'
#define uint long long
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mxn=1e6+123;
int a[mxn],b[mxn];
vector<int>adj[mxn];

pair<int,int>bfs(int node,int n){
	queue<pair<int,int>>q;
	vector<int>vis(n+1,0);
	q.push({node,0});
	vis[node]=1;
	pair<int,int>p;
	while(!q.empty()){
		p=q.front();
		q.pop();
		for(auto v:adj[p.first]){
			if(!vis[v]){
				q.push({v,p.second+1});
				vis[v]=1;
			}
		}
	}
	return p;
}
void dfs(int node,int par,int sign,int depth,vector<vector<int>>&dp){
	dp[node][sign]=depth;
	for(auto v:adj[node]){
		if(v!=par){
			dfs(v,node,sign,depth+1,dp);
		}
	}

}
void solve() {
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pair<int,int>p=bfs(1,n);
	pair<int,int>q=bfs(p.first,n);
  
	vector<vector<int>>dp(n+1,vector<int>(3,0));
  
	dfs(p.first,-1,0,0,dp);
	dfs(q.first,-1,1,0,dp);
  
	for(int i=1;i<=n;i++){
		cout<<max(dp[i][0],dp[i][1])<<" ";
	}
	cout<<endl;
  
}
signed main(){
    fastio;
    int t = 1;
   // cin >>t;
    for(int i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
