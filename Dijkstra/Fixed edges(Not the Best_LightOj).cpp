//https://lightoj.com/problem/not-the-best
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
int dist[3][mxn];

struct info{
	int u,v,w;
};

void dijkstra(int s,int n,int f){
	for(int i=1;i<=n;i++)dist[f][i]=1e18;
	dist[f][s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,s});
	while(!pq.empty()){
		int node=pq.top().second;
		int dis=pq.top().first;
		pq.pop();
		if(dist[f][node]<dis)continue;
		for(auto u:adj[node]){
			int weight=u.second;
			int adjNode=u.first;
			if(weight+dis<dist[f][adjNode]){
				dist[f][adjNode]=weight+dis;
				pq.push({dist[f][adjNode],adjNode});
			}
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)adj[i].clear();
	vector<info>edges;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
		edges.pb({u,v,w});
	}
	dijkstra(1,n,0);
	dijkstra(n,n,1);

	int mn=dist[0][n];
	int ans=1e18;

	for(auto e:edges){
		int x=min(dist[0][e.u]+dist[1][e.v],dist[1][e.u]+dist[0][e.v]);
		if(x+e.w>mn){
			ans=min(ans,x+e.w);
		}
		ans=min(ans,x+(e.w*3));
	}
	cout<<ans<<endl;
	
	

}
signed main(){ 
    fastio; 
    int t=1;
    cin>>t;
   	for(int tc=1;tc<=t;tc++){
    	cout << "Case " << tc << ": ";
       solve();
    }
}
