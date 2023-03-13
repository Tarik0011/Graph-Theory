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
int lev[mxn];
bool vis[mxn];

void bfs(int source){
	memset(lev,-1,sizeof(lev));
	lev[source]=0;
	queue<int>q;
	q.push(source);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto v:adj[node]){
			if(lev[v]==-1){
				lev[v]=lev[node]+1;
				q.push(v);
			}
		}
	}
	
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
 	bfs(1);
 	int mx=-1,mxNode;
 	for(int i=1;i<=n;i++){
 		if(lev[i]>mx){
 			mx=lev[i];
 			mxNode=i;
 		}
 	}
 	bfs(mxNode);
 	for(int i=1;i<=n;i++){
 		if(lev[i]>mx){
 			mx=lev[i];
 		}
 	}
 	cout<<mx<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
