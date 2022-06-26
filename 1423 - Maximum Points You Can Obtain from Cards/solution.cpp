class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefixSum(n+1, 0);
        
        for (int i=1; i<=n; i++) {
            prefixSum[i] = prefixSum[i-1] + cardPoints[i-1];
        }
        int total = prefixSum[n];
        
        int minSum = INT_MAX;
        for (int i=n-k; i<=n; i++) {
            minSum = min(minSum, prefixSum[i] - prefixSum[i-(n-k)]); 
        }
        
        return total - minSum; 
    }
};