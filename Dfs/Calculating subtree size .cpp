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
vector<int>adj[mxn];
int sub[mxn];
bool vis[mxn];

int dfs(int node){
	vis[node]=1;
	int cur=1;
	for(auto u:adj[node]){
		if(!vis[u]){
			cur+=dfs(u);
		}
	}
	sub[node]=cur;
	return cur;

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
 	dfs(1);
 	for(int i=1;i<=n;i++){
 		cout<<sub[i]<<" ";
 	}
 	cout<<endl;
 	
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
