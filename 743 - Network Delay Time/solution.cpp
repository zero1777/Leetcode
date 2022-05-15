class Solution {
public:
    #define pi pair<int, int>
    vector<pi> adj[105];
    int dijkstra(int n, int src) {
        vector<int> dis(n+1, INT_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        pq.push({0, src});
        dis[src] = 0;
        
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            
            if (d > dis[v]) continue;
            
            for (auto [wi, u] : adj[v]) {
                if (dis[u] > dis[v] + wi) {
                    dis[u] = dis[v] + wi;
                    pq.push({dis[u], u});
                }
            }
        }
        
        int ans = -1;
        for (int i=1; i<=n; i++) ans = max(ans, dis[i]);
        
        return (ans == INT_MAX) ? -1 : ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto time : times) 
            adj[time[0]].push_back({time[2], time[1]});
        
        return dijkstra(n, k);
    }
};