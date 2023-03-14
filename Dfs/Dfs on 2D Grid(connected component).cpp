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

int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};

const int mxn=500;
bool vis[mxn][mxn];
int grid[mxn][mxn];

bool isValid(int x,int y,int n,int m){
	if(x>=1 and x<=n and y>=1 and y<=m)return true;
	return false;
}
void dfs(int x,int y,int n,int m){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int newr=x+dx[i];
		int newc=y+dy[i];
		if(isValid(newr,newc,n,m) and !vis[newr][newc] and grid[newr][newc]==1){
			dfs(newr,newc,n,m);
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>grid[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(grid[i][j]==1 and !vis[i][j]){
				dfs(i,j,n,m);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    while(t--){
       solve();
    }
}
