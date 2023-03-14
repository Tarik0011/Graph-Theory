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
vector<int>primes;
int dis[mxn];

bool isValid(int u,int v){
	int cnt=0;
	while(u>0){
		if(u%10!=v%10)cnt++;
		u/=10,v/=10;
	}
	if(cnt==1)return true;
	return false;
}
bool isPrime(int n){
	if(n<=1)return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}
void bulid_graph(){
	for(int i=1000;i<=9999;i++){
		if(isPrime(i)){
			primes.pb(i);
		}
	}
	for(int i=0;i<primes.size()-1;i++){
		for(int j=i+1;j<primes.size();j++){
			int u=primes[i],v=primes[j];
			if(isValid(u,v)){
				adj[u].pb(v);
				adj[v].pb(u);
			}
		}
	}
}
void bfs(int source){
	memset(dis,-1,sizeof(dis));
	queue<int>q;
	q.push(source);
	dis[source]=0;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto u:adj[node]){
			if(dis[u]==-1){
				dis[u]=dis[node]+1;
				q.push(u);
			}
		}
	}
}
void solve(){
 	int a,b;
 	cin>>a>>b;
 	bfs(a);
 	if(dis[b]==-1)cout<<"Impossible"<<endl;
 	else cout<<dis[b]<<endl;

 	for(int i=1;i<=9999;i++){
 		dis[i]=-1;
 	}
}
signed main(){ 
    fastio; 
    bulid_graph();
    int t=1;
    cin>>t;
    while(t--){
       solve();
    }
}
