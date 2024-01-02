//https://codeforces.com/contest/1915/problem/G
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

const int mxn=1e3+123;
int a[mxn];
vector<pair<int,int>>adj[mxn];
int dist[mxn][mxn];

void dijkstra(int s,int n){
	for(int i=0;i<=1001;i++){
		for(int j=0;j<=n;j++){
			dist[i][j]=1e18;
		} 
	}
	dist[a[1]][1]=0;
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
	pq.push({0,1,a[1]});

	while(!pq.empty()){

		int dis=pq.top()[0];
		int node=pq.top()[1];
		int speed=pq.top()[2];
		pq.pop();
		if(dist[speed][node]<dis)continue;
		for(auto u:adj[node]){
			int weight=u.second;
			int adjNode=u.first;
			int nextDist=dis+(weight*speed);
			if(dist[speed][adjNode]>nextDist){
				dist[speed][adjNode]=nextDist;
				pq.push({nextDist,adjNode,min(speed,a[adjNode])});
			}
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)adj[i].clear();
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dijkstra(1,n);
	int ans=1e18;
	for(int i=1;i<=1000;i++){
		ans=min(ans,dist[i][n]);
	}
	cout<<ans<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    	//cout << "Case " << tc <<": ";
       solve();
    }
}
