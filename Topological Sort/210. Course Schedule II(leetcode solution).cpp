class Solution {
public:
     vector<int>adj[2000];
    int ind[2000];
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
            ind[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node]){
                ind[x]--;
                if(ind[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()==numCourses)return ans;
        else return vector<int>();
    }
};
