class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int sz = heights.size();
        priority_queue<int, std::vector<int>, std::greater<int>> bricksNum;
        
        for (int i=1; i<sz; i++) {
            if (heights[i] > heights[i-1]) {
                bricksNum.push(heights[i] - heights[i-1]);
                if (ladders > 0) ladders--;
                else {
                    int minBrick = bricksNum.top();
                    bricksNum.pop();
                    bricks -= minBrick;
                    if (bricks < 0) return i-1;
                }
            }
        }
        
        return sz - 1;
    }
};