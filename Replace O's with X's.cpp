//-----------------TC==O(N*M)--------------SC==O(N*M)-----------------------------------

 vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        
            for(int j=0;j<m;j++){
                if(mat[0][j]=='O'&&!vis[0][j]){
                    vis[0][j]=1;
                    q.push({0,j});
                }
                if(!vis[n-1][j]&&mat[n-1][j]=='O'){
                    q.push({n-1,j});
                    vis[n-1][j]=1;
                }
            }
             for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&vis[nrow][ncol]==0&&mat[nrow][ncol]=='O'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }









