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
int dis[mxn][mxn];

bool isValid(int x,int y,int n,int m){
	if(x>=1 and x<=n and y>=1 and y<=m)return true;
	return false;
}
void bfs(int x,int y,int n,int m){
	queue<pair<int,int>>q;
	q.push({x,y});
	vis[x][y]=1;
	dis[x][y]=0;
	while(!q.empty()){
		auto x=q.front();
		q.pop();
		int row=x.first;
		int col=x.second;
		for(int i=0;i<4;i++){
			int nrow=row+dx[i];
			int ncol=col+dy[i];
			if(isValid(nrow,ncol,n,m) and !vis[nrow][ncol]){
				vis[nrow][ncol]=1;
				dis[nrow][ncol]=1+dis[row][col];
				q.push({nrow,ncol});
			}
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	bfs(1,1,n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    while(t--){
       solve();
    }
}
