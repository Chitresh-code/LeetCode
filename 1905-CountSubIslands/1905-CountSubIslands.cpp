class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>> &vis,bool &flag){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int row[4] = {0,1,-1,0};
        int col[4] = {-1,0,0,1};

        for(int i = 0;i<4;i++){
            int nrow = row[i] + r;
            int ncol = col[i] + c;

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                if(grid[nrow][ncol] == 1) flag = true;
                if(grid[nrow][ncol] == 1 || grid[nrow][ncol] == 2){
                    dfs(nrow,ncol,grid,vis,flag);
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n = grid1.size();
        int m = grid1[0].size();

        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++){
                if(grid1[i][j] == 1 && grid2[i][j]==1) grid2[i][j] = 2;
            }

        int count = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid2[i][j] == 2 && !vis[i][j]){
                    bool flag = false;
                    dfs(i,j,grid2,vis,flag);
                    if(flag) continue;
                    count++;
                }
            }
        }
        return count;
    }
};