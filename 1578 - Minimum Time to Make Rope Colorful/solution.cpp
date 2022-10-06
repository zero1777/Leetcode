class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ret = 0;
            
        int total, maxVal;
        total = maxVal = neededTime[0];
        for (int i=1; i<n; i++) {
            if (colors[i] == colors[i-1]) {
                total += neededTime[i];      
                maxVal = max(maxVal, neededTime[i]);
            }
            else {
                ret += (total - maxVal);
                total = maxVal = neededTime[i];
            }
        } 
        ret += (total - maxVal);
        
        return ret;
    }
};