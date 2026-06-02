class Solution {
public:
    void bfs(vector<vector<int>>& heights,vector<vector<bool>> &visited,int x,int y,queue<pair<int,int>> &qa){
        int xd[4]={1,-1,0,0};
        int yd[4]={0,0,1,-1};
        int m =heights.size();
        int n =heights[0].size();
        visited[x][y]=true;
        for(int i =0;i<4;i++){
            int nx=x+xd[i];
            int ny=y+yd[i];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[nx][ny]&&heights[nx][ny]>=heights[x][y]){
                qa.push({nx,ny});
                visited[nx][ny]=true;
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        //for top
        //for left
        //add it into the damn vector<vector>>
        int m =heights.size();
        int n =heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        queue<pair<int,int>> qp; 
        queue<pair<int,int>> qa;
        for(int i =0;i<n;i++){
            qp.push({0,i});
            pacific[0][i]=true;
            qa.push({m-1,i});
            atlantic[m-1][i]=true;
        }
        for(int i=0;i<m;i++){
            qp.push({i,0});
            pacific[i][0]=true;
            qa.push({i,n-1});
            atlantic[i][n-1]=true;
        }
        while(!qa.empty()){
            pair<int,int> b=qa.front();
            int f=b.first;
            int s= b.second;
            bfs( heights,atlantic,f,s,qa);
            qa.pop();
        }
        while(!qp.empty()){
            pair<int,int> b=qp.front();
            int f=b.first;
            int s= b.second;
            bfs( heights,pacific,f,s,qp);
            qp.pop();
        }
        vector<vector<int>> result;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
