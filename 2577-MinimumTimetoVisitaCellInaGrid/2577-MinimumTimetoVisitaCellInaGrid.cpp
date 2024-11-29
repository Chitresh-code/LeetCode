class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1]>1 && grid[1][0]>1) return -1;

        int n=grid.size(), m=grid[0].size();
        int d[][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<bool>> visited(n, vector<bool>(m));

        auto cmp = [&grid](pair<int,int> a, pair<int,int> b){
            return grid[a.first][a.second]>grid[b.first][b.second];
        };
        priority_queue < 
            pair<int,int>, vector< pair<int,int> >, decltype(cmp)
        > pq(cmp);

        pq.push({0,0});
        visited[0][0]=true;
        while(!pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();
            for(auto [a, b]: d){
                a+=x;
                b+=y;
                if(a<0 || a>=n || b<0 || b>=m || visited[a][b]) continue;
                visited[a][b]=true;
                grid[a][b]=(grid[a][b]<=grid[x][y])
                    ? grid[x][y]+1
                    : grid[a][b]+(grid[a][b]%2==grid[x][y]%2);
                if(a==n-1 && b==m-1) return grid[a][b];
                pq.push({a, b});
            }
        }
        
        return -1;
    }
};