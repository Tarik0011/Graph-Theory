

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
#define  BLOCK        700
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 

const int mxn=1e6+123;
vector<int>adj[mxn];
int S[mxn],T[mxn],FT[2*mxn],timer=1;

void dfs(int node,int par){
	S[node]=timer;
	FT[timer]=node;
	timer++;
	for(auto u:adj[node]){
		if(u!=par){
			dfs(u,node);
		}
	}
	T[node]=timer;
	FT[timer]=node;
	timer++;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,-1);
	//start time
	for(int i=1;i<=n;i++){
		cout<<S[i]<<" ";
	}
	cout<<endl;
	//Terminating time
	for(int i=1;i<=n;i++){
		cout<<T[i]<<" ";
	}
	cout<<endl;
	//Flattening 
	for(int i=1;i<=2*n;i++){
		cout<<FT[i]<<" ";
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
