class Solution {
public:
    vector<vector<int>> bridges;
    int ts = 0; // timestamp
    
    void dfs(int v, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& vis, vector<int>& from) {
        disc[v] = low[v] = ts++;
        vis[v] = true;
        
        for (auto u : adj[v]) {
            if (!vis[u]) {
                from[u] = v;
                dfs(u, adj, disc, low, vis, from);
                
                low[v] = min(low[v], low[u]);
                if (low[u] > disc[v]) {
                    vector<int> s = {u, v};
                    bridges.push_back(s);
                }
            }
            else if (u != from[v]) {
                low[v] = min(low[v], disc[u]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> disc(n, INT_MAX);
        vector<int> low(n, INT_MAX);
        vector<bool> vis(n, false);
        vector<int> adj[n];
        vector<int> from(n, -1);
        
        for (auto connect : connections) {
            adj[connect[0]].push_back(connect[1]);
            adj[connect[1]].push_back(connect[0]);
        }
        
        for (int i=0; i<n; i++) {
            if (!vis[i]) dfs(i, adj, disc, low, vis, from);
        }
        
        return bridges;
    }
};