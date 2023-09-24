//https://atcoder.jp/contests/abc320/tasks/abc320_d

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
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 
 
const int mxn=1e6+123;
int xx[mxn],yy[mxn];
vector<array<int,3>>adj[mxn];
bool vis[mxn];

void dfs(int u){
	vis[u]=1;
	for(auto x:adj[u]){
		int node=x[0];
		int x_cordinate=x[1];
		int y_cordinate=x[2]; 

		if(!vis[node]){
			xx[node]=xx[u]+x_cordinate;
			yy[node]=yy[u]+y_cordinate;
			dfs(node);
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,x,y;
		cin>>u>>v>>x>>y;
		adj[u].pb({v,x,y});
		adj[v].pb({u,-x,-y});
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		if(vis[i]){
			cout<<xx[i]<<" "<<yy[i]<<endl;
		}else{
			cout<<"undecidable"<<endl;
		}
	}
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
    //	cout<<"Case #"<<i<<": ";
       solve();
    }
}
