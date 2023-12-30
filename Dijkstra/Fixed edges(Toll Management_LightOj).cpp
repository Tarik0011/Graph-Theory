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

const int mxn=1e4+123;
vector<pair<int,int>>adj[3][mxn];
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
		for(auto u:adj[f][node]){
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
	int n,m,s,t,p;
	cin>>n>>m>>s>>t>>p;
	vector<info>edges;

	for(int i=1;i<=n;i++){
		adj[0][i].clear();
		adj[1][i].clear();
	}


	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[0][u].pb({v,w});
		adj[1][v].pb({u,w});
		edges.pb({u,v,w});
	}
	dijkstra(s,n,0);
	dijkstra(t,n,1);

	int ans=-1;

	for(auto x:edges){
		int u=x.u;
		int v=x.v;
		int w=x.w;
		int need=dist[0][u]+w+dist[1][v];
		if(need<=p){
			ans=max(ans,w);
		}
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
