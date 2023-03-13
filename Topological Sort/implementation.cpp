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
int ind[mxn];

vector<int>khan(int n){
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			q.push(i);
		}
	}
	vector<int>ans;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		ans.push_back(node);
		for(auto u:adj[node]){
			ind[u]--;
			if(ind[u]==0){
				q.push(u);
			}
		}

	}
	return ans;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);//directed graph
		ind[v]++;
	}
	vector<int>ans=khan(n);
	for(auto x:ans)cout<<x<<" ";
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
