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
int color[mxn];
bool isBipartite(int source){
	queue<int>q;
	q.push(source);
	color[source]=1;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto u:adj[node]){
			//Give the oposite color
			if(color[u]==-1){
				color[u]=!color[node];//color[u]=1-color[node];
				q.push(u);
			}
			else if(color[u]==color[node]){
				return false;
			}
		}
	}
	return true;
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
	memset(color,-1,sizeof(color));
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			if(isBipartite(i)==true){
				cout<<"Bipartite"<<endl;
				return;
			}
		}
	}
	cout<<"Not Bipartite"<<endl;
	

}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    while(t--){
       solve();
    }
}
