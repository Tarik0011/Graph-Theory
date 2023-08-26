

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
#define  pb        push_back
#define  all(v)    v.begin(),v.end()
#define  endl       '\n'  
#define  uint       long long
#define  int        long long
#define  BLOCK        700
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 

const int mxn=2e5+123,sz=19;
vector<int>adj[mxn];
int dis[mxn];
int parent[mxn][sz];

void clr(int n){
	for(int i=0;i<=n;i++){
		adj[i].clear();
		dis[i]=0;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=19;j++){
			parent[i][j]=0;
		}
	}
}
void dfs(int node,int par){
	for(int i=1;i<sz;i++)parent[node][i]=parent[parent[node][i-1]][i-1];
	for(auto x:adj[node]){
		if(x!=par){
			parent[x][0]=node;
			dis[x]=dis[node]+1;
			dfs(x,node);
		}
	}
}
int getAncestor(int u,int d){
	if(d==0)return u;
	while(d){
		int l=(int)log2(d);
		d-=(1<<l);
		u=parent[u][l];
	}
	if(u==0)return -1;
	return u;
}
int LCA(int u,int v){
	if(dis[u]<dis[v])swap(u,v);
	for(int i=sz-1;i>=0;i--){
		if(dis[parent[u][i]]>=dis[v]){
			u=parent[u][i];
		}
	}
	if(u==v)return u;
	for(int i=sz-1;i>=0;i--){
		if(parent[u][i]!=parent[v][i]){
			u=parent[u][i];
			v=parent[v][i];
		}
	}
	return parent[u][0];
}
int getDist(int a, int b){
    int lca=LCA(a,b);
    return dis[a] + dis[b] - 2*dis[lca];
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1);
	cout<<LCA(4,6)<<endl;      //1
	cout<<getDist(4,6)<<endl;  //4
  
  //input
  
	// 6 5
	// 1 2
	// 1 3
	// 2 4
	// 2 5
	// 3 6
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
