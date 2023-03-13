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
vector<pair<int,int>>adj[mxn];
bool vis[mxn];

int prims(int source){

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    int ans=0;
    while(!pq.empty()){
    	auto x=pq.top();
    	int w=x.first;
    	int node=x.second;
    	pq.pop();
    	if(vis[node]==1)continue;
    	vis[node]=1;
    	ans+=w;
    	for(auto u:adj[node]){
    		int adjNode=u.first;
    		int adjW=u.second;
    		if(!vis[adjNode]){
    			pq.push({adjW,adjNode});
    		}
    	}
    }
    return ans;
	
}
void solve(){
 	int n,m;
 	cin>>n>>m;
 	for(int i=1;i<=m;i++){
 		int u,v,w;
 		cin>>u>>v>>w;
 		adj[u].pb({v,w});
 		adj[v].pb({u,w});
 	}
 	int ans=prims(1);
 	cout<<ans<<endl;
 	
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
