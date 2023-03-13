
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
int level[mxn];
void bfs(int source){
	memset(level,-1,sizeof(level));
	queue<int>q;
	q.push(source);
	level[source]=0;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto u:adj[node]){
			if(level[u]==-1){
				level[u]=level[node]+1;
				q.push(u);
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
	for(int i=1;i<=n;i++){
		cout<<level[i]<<" ";
	}
	cout<<endl;
	

}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    while(t--){
       solve();
    }
}
