class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_map<int, int> inDeg, outDeg;

        for(auto &pair : pairs) {
            adj[pair[0]].push_back({pair[0], pair[1]});
            outDeg[pair[0]]++;
            inDeg[pair[1]]++;
        }

        int start = pairs[0][0];
        for(auto& [n, deg] : outDeg) {
            if(deg > inDeg[n]) {
                start = n;
                break;
            }
        }
        
        vector<vector<int>> res;

        stack<int> stk;
        stk.push(start);
        while(!stk.empty()) {
            int node = stk.top();
            if(!adj[node].empty()) {
                auto edge = adj[node].back();
                adj[node].pop_back();
                stk.push(edge.second); 
            } else {
                stk.pop();
                if(!stk.empty()) {
                    res.push_back({stk.top(), node});
                }
            }
        }

        reverse(res.begin(), res.end()); 
        return res;
    }
};
