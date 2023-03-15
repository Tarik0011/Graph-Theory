//problem Link:https://www.codingninjas.com/codestudio/problems/minimum-steps-to-reach-target-by-a-knight_893050?leftPanelTab=0

int kdx[8]={-2,-1,1,2,2,1,-1,-2};
int kdy[8]={1,2,2,1,-1,-2,-2,-1};

bool isValid(int x,int y,int n,int m){
	if(x>=1 and x<=n and y>=1 and y<=m)return true;
	return false;
}

bool vis[1000][1000];
int dis[1000][1000];

int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    // Write your code here.
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            vis[i][j]=0;
            dis[i][j]=0;
        }
    }
    int n=size;
    int m=size;
    int x= knightPosition.first;
    int y= knightPosition.second;
    int t1=targetPosition.first;
    int t2=targetPosition.second;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{x,y}});
    vis[x][y]=1;
    dis[x][y]=1;
    while(!q.empty()){
        auto x=q.front();
        int row=x.second.first;
        int col=x.second.second;
        int step=x.first;
        q.pop();
        for(int i=0;i<8;i++){
            int newr=row+kdx[i];
            int newc=col+kdy[i];
            if(isValid(newr,newc,n,m) and !vis[newr][newc]){
                vis[newr][newc]=1;
                dis[newr][newc]=step+1;
                q.push({dis[newr][newc],{newr,newc}});
            }

        }
    }
    return dis[t1][t2];
}
