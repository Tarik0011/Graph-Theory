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
int dist[mxn],parent[mxn];

void dijkstra(int s,int n){
	for(int i=1;i<=n;i++)dist[i]=1e18;
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,s});
	while(!pq.empty()){
		int node=pq.top().second;
		int dis=pq.top().first;
		pq.pop();
		if(dist[node]<dis)continue;
		for(auto u:adj[node]){
			int weight=u.second;
			int adjNode=u.first;
			if(weight+dis<dist[adjNode]){
				dist[adjNode]=weight+dis;
				pq.push({dist[adjNode],adjNode});
				parent[adjNode]=node;//also track parent
			}
		}
	}
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
	dijkstra(1,n);
	if(dist[n]==1e18){
		cout<<"-1"<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}

	/*
	vector<int>ans;
	int node=n;
	ans.pb(node);
	while(parent[node]!=0){
		ans.pb(parent[node]);
		node=parent[node];
	}
	reverse(all(ans));
	for(auto x:ans)cout<<x<<" ";
	cout<<endl;
	*/

}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    while(t--){
       solve();
    }
}
