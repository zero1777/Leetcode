class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int minCost = 0;
        int edgeNum = 0;
        int n = points.size();
        
        // vertices which are visited
        vector<bool> visited(n);
        vector<int> dist(n, INT_MAX);
        
        // set the startPoint dist = 0
        dist[0] = 0;
        
        while (edgeNum < n) {
            int minDist = INT_MAX;
            int minVtx = -1;
            
            // find out the min dist vertex
            for (int i = 0; i < n; i++) {
                if (!visited[i] && minDist > dist[i]) {
                    minDist = dist[i];
                    minVtx = i;
                }
            }
            
            // update min vertex's adjacent vertices
            for (int i = 0; i < n; i++) {
                int manhDist = abs(points[minVtx][0] - points[i][0]) + abs(points[minVtx][1] - points[i][1]);
                
                if (!visited[i]) dist[i] = min(dist[i], manhDist);
            }
            
            // update the minCost, edgeNum, visit status
            minCost += minDist;
            edgeNum++;
            visited[minVtx] = true;
        }
        
        return minCost;
    }
};