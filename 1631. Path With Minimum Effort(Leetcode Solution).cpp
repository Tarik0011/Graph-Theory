class Solution {
public:
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
  
bool isValid(int n,int m,int x,int y){
    if(x>=0 and x<n and y>=0 and y<m)return true;
    return false;
}
    int minimumEffortPath(vector<vector<int>>& heights){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        int ans=-1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 and col==m-1){
                ans=diff;
                break;
            }
            for(int i=0;i<4;i++){
                int newr=row+dx[i];
                int newc=col+dy[i];
                if(isValid(n,m,newr,newc)){
                    int x=abs(heights[row][col]-heights[newr][newc]);
                    int newEffort=max(x,diff);
                    if(newEffort<dis[newr][newc]){
                        dis[newr][newc]=newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }

                }
            }
        }
         return ans;
    }



};
