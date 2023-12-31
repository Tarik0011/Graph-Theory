//https://lightoj.com/problem/new-traffic-system

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
vector<vector<int>>adj[mxn];
int dist[12][mxn];

void dijkstra(int s,int n,int d){
	for(int i=0;i<=d;i++){
		for(int j=0;j<=n;j++){
			dist[i][j]=1e18;
		}
	}
	dist[0][s]=0;
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
	pq.push({0,0,s});

	while(!pq.empty()){

		int dis=pq.top()[0];
		int cnt=pq.top()[1];
		int node=pq.top()[2];
		pq.pop();
		if(dist[cnt][node]<dis)continue;

		for(auto u:adj[node]){
			int weight=u[1];
			int adjNode=u[0];
			int typ=u[2];

			if(cnt+typ<=d and dist[cnt][node]+weight<dist[cnt+typ][adjNode]){
				dist[cnt+typ][adjNode]=dist[cnt][node]+weight;
				pq.push({dist[cnt+typ][adjNode],cnt+typ,adjNode});
			}
		}
	}
}
void solve(){
	int n,m,k,d;
	cin>>n>>m>>k>>d;
	for(int i=0;i<=n;i++)adj[i].clear();
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w,0});
	}
	for(int i=1;i<=k;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w,1});
	}
	dijkstra(0,n,d);
	int ans=1e18;
	for(int i=0;i<=d;i++){
		ans=min(ans,dist[i][n-1]);
	}
	if(ans==1e18)cout<<"Impossible"<<endl;
	else cout<<ans<<endl;
	

}
signed main(){ 
    fastio; 
    int t=1;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
    	cout << "Case " << tc <<": ";
       solve();
    }
}
