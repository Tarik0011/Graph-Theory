
class Solution {
public:
     bool vis[501][501];
    int dx[8]={-1,+1,0,0,-1,-1,+1,+1};
    int dy[8]={0,0,-1,+1,-1,+1,-1,+1};
    
    bool isValid(int x,int y,int n,int m){
        if(x>=0 and x<n and y>=0 and y<m)return true;
        return false;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        while(!q.empty()){
            auto x=q.front();
            int row=x.first;
            int col=x.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=row+dx[i];
                int newc=col+dy[i];
                if(isValid(newr,newc,n,m) and grid[newr][newc]==1 and vis[newr][newc]==0){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
