class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n+1, vector<int>(target+1, INT_MAX)));
        
        // initialization
        if (houses[0] == 0) {
            for (int color=1; color<=n; color++) {
                dp[0][color][1] = cost[0][color-1];
            }
        }
        else dp[0][houses[0]][1] = 0;
        
        // dp
        for (int house=1; house<m; house++) {
            for (int color=1; color<=n; color++) {
                for (int t=1; t<=house+1 && t<=target; t++) {
                    int preCost = INT_MAX; 
                    for (int pre=1; pre<=n; pre++) {
                        if (pre != color) {
                            preCost = min(preCost, dp[house-1][pre][t-1]); 
                        }     
                        else {
                            preCost = min(preCost, dp[house-1][pre][t]); 
                        }
                    }
                    
                    if (preCost == INT_MAX) continue;
                    if (houses[house] == 0) {
                        dp[house][color][t] = cost[house][color-1] + preCost;
                    } 
                    else if (houses[house] == color) {
                        dp[house][color][t] = preCost;
                    }
                }
            }
        }
        
        // get min cost
        int minCost = INT_MAX;
        for (int color=1; color<=n; color++) {
            minCost = min(minCost, dp[m-1][color][target]);
        }
        
        return (minCost == INT_MAX) ? -1 : minCost;
    }
};