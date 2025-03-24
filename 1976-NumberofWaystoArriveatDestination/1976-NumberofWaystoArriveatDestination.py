# Last updated: 3/24/2025, 10:21:50 AM
MOD = 10**9 + 7
from sortedcontainers import SortedDict
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        # adj[i] = {j -> dist} where there's a road from i -> j with distance dist.
        adj = [{} for i in range(n)]
        for u, v, dist in roads:
            adj[u][v] = dist
            adj[v][u] = dist
        
        min_dists = [float('inf')] * n
        # NlogN approach
        dist_to_nodes = SortedDict({ float('inf'): set(range(n))}) 
        # Maps: minimum_distance -> nodes with that distance

        # Counts the number of times we've achieved the minimum distance
        # for the given node.
        multiplicities = [1] * n
        
        # Update our min_dists and dist_to_nodes data structures
        # to set the minimum distance for node to dist
        def update_dist(node, dist):
            prev_dist = min_dists[node]
            min_dists[node] = dist
            dist_to_nodes[prev_dist].remove(node)
            if not len(dist_to_nodes[prev_dist]):
                del dist_to_nodes[prev_dist]
            cur_node_set = dist_to_nodes.get(dist, set())
            cur_node_set.add(node)
            dist_to_nodes[dist] = cur_node_set

        update_dist(0, 0)
        unvisited = set(range(n))
        while n - 1 in unvisited:
            cur_dist, cur_nodes = dist_to_nodes.peekitem(0)
            for nd in cur_nodes:
                cur_node = nd
                break
            
            unvisited.remove(cur_node)
            cur_nodes.remove(cur_node)
            if not len(cur_nodes):
                del dist_to_nodes[cur_dist]

            cur_mult = multiplicities[cur_node]

            for v, d in adj[cur_node].items():
                if v not in unvisited:
                    continue
                v_dist = cur_dist + d
                if v_dist == min_dists[v]:
                    # Found a new way to reach the minimum distance
                    multiplicities[v] = (multiplicities[v] + cur_mult) % MOD
                elif v_dist < min_dists[v]:
                    # Found a new minimum distance, wipe out the old ones
                    update_dist(v, v_dist)
                    multiplicities[v] = cur_mult

        return  multiplicities[n-1]