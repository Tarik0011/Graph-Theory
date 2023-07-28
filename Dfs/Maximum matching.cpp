// https://www.hackerearth.com/challenges/competitive/october-circuits/algorithm/shil-and-lab-assignment-14/submission/84343041/
// https://www.hackerearth.com/challenges/competitive/october-circuits/algorithm/shil-and-lab-assignment-14/
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
int given[100011];
vector<int>adj[mxn];
bool ok(int i,map<int,bool>&seen){
	for(auto u:adj[i]){
		if(seen.find(u)==seen.end()){
			seen[u]=1;
			if(given[u]==-1){
				given[u]=i;
				return true;
			}else{
				if(ok(given[u],seen)){
					given[u]=i;
					return true;
				}
			}
		}
	}
	return false;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int k=1;k<=n;k++){
		int x;cin>>x;
		for(int i=1;i*i<=x;i++){
			if(x%i==0){
				if(i*i==x){
					if(i<=m){
					adj[k].pb(i);
					continue;
				}
				}
				if(i<=m){
					adj[k].pb(i);
				}
				int u=x/i;
				if(u<=m){
					adj[k].pb(u);
				}
			}
		}
	}
	for(int i=0;i<=100011;i++){
        given[i]=-1;
    }
	
	int ans=0;
	for(int i=1;i<=m;i++){
		map<int,bool>seen;
		if(ok(i,seen)){
			ans++;
		}
	}
	cout<<ans<<endl;
	
}
signed main(){ 
    fastio; 
    int t=1;
 //   cin>>t;
    while(t--){
       solve();
    }
}
