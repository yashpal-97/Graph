Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
consisting of '0's (Water) and '1's(Land). Find the number of islands.
  
  //-----------------------TC==O(8*N*M)---------------------SC==O(N*N)+O(N*N)-----------------------------------------//
  
  
   void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
     int n=grid.size();
     int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=delrow+row;
                    int ncol=delcol+col;
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
         int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }






