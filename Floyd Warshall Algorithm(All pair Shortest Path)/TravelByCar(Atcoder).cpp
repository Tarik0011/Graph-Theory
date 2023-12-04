//https://atcoder.jp/contests/abc143/tasks/abc143_e
//https://atcoder.jp/contests/abc143/submissions/46224223

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

#define pb push_back
#define all(v) v.begin(),v.end()
#define endl '\n'
#define uint long long
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mxn=505;
int dis[mxn][mxn];
int f[mxn][mxn];
void solve() {
	int n,m,l;
	cin>>n>>m>>l;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=1e18;
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=w;
		dis[v][u]=w;
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]<=l){
				f[i][j]=min(f[i][j],1LL);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int s,t;
		cin>>s>>t;
		if(f[s][t]==1e18)cout<<-1<<endl;
		else{
			cout<<f[s][t]-1<<endl;
		}
	}
}
signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
