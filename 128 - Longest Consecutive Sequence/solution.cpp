class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for (int num : nums) uset.insert(num);
        
        int longestStreak = 0;
        for (int num : nums) {
            if (uset.find(num-1) == uset.end()) {
                int streak = 1;
                int curNum = num + 1;
                
                while (uset.find(curNum) != uset.end()) {
                    streak++;
                    curNum++;
                }
                longestStreak = max(longestStreak, streak);
            }
        }
        
        return longestStreak;
    }
};