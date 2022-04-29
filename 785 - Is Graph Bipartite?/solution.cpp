class Solution {
public:
    const int red = 1;
    const int black = -1;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        
        for (int i=0; i<n; i++) {
            if (colors[i] != 0) continue;
            
            queue<int> qu;
            qu.push(i);
            colors[i] = red;
            
            while (!qu.empty()) {
                int v = qu.front();
                qu.pop();

                for (auto u : graph[v]) {
                    if (colors[u] == colors[v]) return false;
                    else if (!colors[u]) {
                        colors[u] = (-1) * colors[v];
                        qu.push(u);
                    }
                }
            }
        }
        
        
        return true;
    }
};