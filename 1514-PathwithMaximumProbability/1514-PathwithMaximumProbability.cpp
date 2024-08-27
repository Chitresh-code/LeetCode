class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Graph representation using an adjacency list
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        // Max probability array to store the maximum probability to reach each node
        vector<double> max_prob(n, 0.0);
        max_prob[start] = 1.0; // Start node has a probability of 1

        // Priority queue to process the nodes with maximum probability first
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start); // Push the start node with probability 1.0

        while (!pq.empty()) {
            double current_prob = pq.top().first;
            int current_node = pq.top().second;
            pq.pop();

            // If we have reached the end node, return the probability
            if (current_node == end) {
                return current_prob;
            }

            // Traverse all the neighbors of the current node
            for (const auto& neighbor : graph[current_node]) {
                int next_node = neighbor.first;
                double path_prob = neighbor.second;

                // If the probability of the path through this node is greater, update and push to the queue
                if (current_prob * path_prob > max_prob[next_node]) {
                    max_prob[next_node] = current_prob * path_prob;
                    pq.emplace(max_prob[next_node], next_node);
                }
            }
        }

        // If no path was found, return 0.0
        return 0.0;
    }
};
