class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, NON_VISITED));
        for(auto& pos: walls){  
            visited[pos[0]][pos[1]] = WALL;
        }

        queue<pair<int,int>> q;
        for(auto &pos: guards) {
            q.push({pos[0], pos[1]});
            visited[pos[0]][pos[1]] = GUARD;
        }

        pair<int,int> pos;
        int new_x, new_y;
        while(!q.empty()){
            pos = q.front(); q.pop();

            for(int d = 0; d < 4; d++){
                new_x = pos.first + dir[d][0];
                new_y = pos.second + dir[d][1];

                while(new_x >= 0 && new_y >= 0 && new_x < m && new_y < n &&
                      visited[new_x][new_y] != GUARD && visited[new_x][new_y] != WALL){
                    
                    visited[new_x][new_y] = VISITED;
                    new_x += dir[d][0];
                    new_y += dir[d][1];
                }
            }
        }

        int count = 0;
        
        for(int row = 0; row < m; row++){
            for(int col = 0; col<n; col++){
                if(visited[row][col] == NON_VISITED) count++;
            }
        }

        return count;
    }

private:
    enum CELLS{
        NON_VISITED,
        VISITED,
        GUARD,
        WALL
    };

    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};