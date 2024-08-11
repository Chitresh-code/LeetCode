class Solution {
public:
    void dfsTraversal(vector<vector<int>>& grid, int row, int col, int sizeR, int sizeC){
        if (row < 0 || col < 0 || row >= sizeR || col >= sizeC || grid[row][col] == 0) return;

        grid[row][col] = 0;  // Mark as visited

        // Traverse the four possible directions
        dfsTraversal(grid, row + 1, col, sizeR, sizeC);
        dfsTraversal(grid, row - 1, col, sizeR, sizeC);
        dfsTraversal(grid, row, col + 1, sizeR, sizeC);
        dfsTraversal(grid, row, col - 1, sizeR, sizeC);
    }

    int countIslands(vector<vector<int>> grid) {
        int sizeR = grid.size(), sizeC = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < sizeR; i++) {
            for (int j = 0; j < sizeC; j++) {
                if (grid[i][j] == 1) {
                    dfsTraversal(grid, i, j, sizeR, sizeC);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }

    int minDays(vector<vector<int>>& grid) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int sizeR = grid.size(), sizeC = grid[0].size();

        // Check initial island count
        if (countIslands(grid) != 1) return 0;

        // Try removing each cell to see if it disconnects the island
        for (int i = 0; i < sizeR; i++) {
            for (int j = 0; j < sizeC; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  // Remove the land
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1;  // Restore the land
                }
            }
        }

        // If removing one cell didn't work, the answer is 2
        return 2;
    }
};
