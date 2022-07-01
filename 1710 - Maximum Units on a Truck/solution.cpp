class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto compare = [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; };
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int units = 0;
        for (auto boxType: boxTypes) {
            while (boxType[0]--) {
                if (truckSize == 0) break;
                units += boxType[1];
                truckSize--;
            }
        }
        
        return units;
    }
};