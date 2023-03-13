// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int>dist(100001,1e9);
        queue<pair<int,int>>q;
        q.push({start,0});
        dist[start]=0;
        
        while(!q.empty()){
            auto it=q.front();
            int node=it.first;
            int step=it.second;
            q.pop();
            for(auto x:arr){
                int mul=(x*node)%100000;
                if(step+1<dist[mul]){
                    dist[mul]=step+1;
                    if(mul==end)return step+1;
                    q.push({mul,dist[mul]});
                }
                
            }
            
        }
        return -1;

    }
};
