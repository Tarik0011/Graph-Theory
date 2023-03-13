
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
int a[mxn];

class Disjoinset{
public:	vector<int>size,par;
public:
	Disjoinset(int n){
		par.resize(n+2,0);
		size.resize(n+2,0);
		for(int i=0;i<=n;i++){
			par[i]=i;
			size[i]=1;
		}
	}
	int findPar(int node){
		if(par[node]==node)return node;
		return par[node]=findPar(par[node]);
	}
	void Union(int u,int v){
		int p=findPar(u);
		int q=findPar(v);
		if(p==q)return;
		if(size[p]<size[q]){
			par[p]=q;
			size[q]+=size[p];
		}else{
			par[q]=p;
			size[p]+=size[q];
		}
	}

};
void solve(){
 	int n,m;
 	cin>>n>>m;
 	Disjoinset ds(n);
 	vector<pair<int,pair<int,int>>>edges;
 	for(int i=1;i<=m;i++){
 		int u,v,w;
 		cin>>u>>v>>w;
 		edges.pb({w,{u,v}});
 	}
 	sort(all(edges));
 	int ans=0;
 	for(auto x:edges){
 		int u=x.second.first;
 		int v=x.second.second;
 		int w=x.first;
 		if(ds.findPar(u)!=ds.findPar(v)){
 			ans+=w;
 			ds.Union(u,v);
 		}
 	}
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
