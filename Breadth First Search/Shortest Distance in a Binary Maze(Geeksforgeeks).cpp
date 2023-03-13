// User function Template for C++

class Solution {
  public:
  int dist[501][501];
  
  int dx[8]={-1,1,0,0,-1,-1,1,1};
  int dy[8]={0,0,-1,1,-1,1,-1,1};
  
  bool isValid(int x,int y,int n,int m){
	      if(x>=0 and x<n and y>=0 and y<m)return true;
    	else return false;
  }
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=1e9;
            }
        }
        queue<pair<int,pair<int,int>>>q;
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        while(!q.empty()){
            int d=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=dx[i]+x;
                int newc=dy[i]+y;
                if(isValid(newr,newc,n,m) and grid[newr][newc]==1 and d+1<dist[newr][newc]){
                    dist[newr][newc]=d+1;
                    q.push({dist[newr][newc],{newr,newc}});
                }
            }
        }
        if(dist[ destination.first][ destination.second]==1e9)return -1;
        else return dist[ destination.first][ destination.second];
    }
};
