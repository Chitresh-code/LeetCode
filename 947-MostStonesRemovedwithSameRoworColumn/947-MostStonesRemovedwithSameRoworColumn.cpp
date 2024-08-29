class Solution {
public:
    unordered_map<int, int> parent;
    
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

int removeStones(vector<vector<int>>& stones) {
    Solution uf;
    
    for (auto& stone : stones) {
        int x = stone[0];
        int y = stone[1] + 10001;
        uf.unite(x, y);
    }
    
    unordered_map<int, int> rootCount;
    for (auto& stone : stones) {
        int root = uf.find(stone[0]);
        rootCount[root] = 1;
    }
    
    int numberOfUniqueComponents = rootCount.size();
    
    return stones.size() - numberOfUniqueComponents;
  }
};

