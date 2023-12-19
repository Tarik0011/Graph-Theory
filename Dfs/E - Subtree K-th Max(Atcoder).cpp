//https://atcoder.jp/contests/abc239/tasks/abc239_e
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mxn = 1e6 + 123;
int a[mxn],b[mxn];
vector<int>adj[mxn];
multiset<int,greater<int>>ms[mxn];

void dfs(int node,int par){
	ms[node].insert(a[node]);
	for(auto v:adj[node]){
		if(par==v)continue;
		dfs(v,node);
		for(auto x:ms[v]){
			ms[node].insert(x);
			if(ms[node].size()>20){
				ms[node].erase(ms[node].find(*ms[node].rbegin()));
			}
		}
	}
	// while(ms[node].size()>20){
	// 	ms[node].erase(ms[node].find(*ms[node].rbegin()));
	// }
}
void solve(){
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   }
   for(int i=1;i<=n-1;i++){
   	int u,v;
   	cin>>u>>v;
   	adj[u].pb(v);
   	adj[v].pb(u);
   }
   dfs(1,-1);
   while(k--){
   	int node,val;
   	cin>>node>>val;
   	vector<int>v;
   	for(auto x:ms[node]){
   		v.pb(x);
   	}
   	val--;
   	cout<<v[val]<<endl;
   }
}
signed main() {
    fastio;
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}


/*
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mxn = 1e6 + 123;
int a[mxn],b[mxn];
vector<int>adj[mxn];

vector<int>ms[mxn];

void dfs(int node,int par){
	ms[node].pb(a[node]);
	for(auto v:adj[node]){
		if(par==v)continue;
		dfs(v,node);
		for(auto x:ms[v]){
			ms[node].pb(x);
		}
	}
	 sort(all(ms[node]), greater<>());
    while (ms[node].size() > 20) {
        ms[node].pop_back();
    }
}
void solve(){
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   }
   for(int i=1;i<=n-1;i++){
   	int u,v;
   	cin>>u>>v;
   	adj[u].pb(v);
   	adj[v].pb(u);
   }
   dfs(1,-1);
   while(k--){
   	int node,val;
   	cin>>node>>val;
   
   	val--;
   	cout<<ms[node][val]<<endl;
   }
}
signed main() {
    fastio;
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}

*/
