class Solution {
public:
    typedef long long ll;
    typedef pair<double, int> p;
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        
        vector<double> result(n, 0.0);
        result[start] = 1.0;
        
        priority_queue<p> pq;
        pq.push({1.0, start});
        
        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (node == end) {
                return prob;
            }
            
            for (const auto& neighbor : adj[node]) {
                int currnode = neighbor.first;
                double currprob = neighbor.second;
                
                if (result[currnode] < prob * currprob) {
                    result[currnode] = prob * currprob;
                    pq.push({result[currnode], currnode});
                }
            }
        }
        
        return 0.0;
    }
};