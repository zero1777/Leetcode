class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mod = 1e9 + 7;
        
        long long hcut = -1, vcut = -1, pre;
        
        pre = 0;
        for (auto hc : horizontalCuts) {
            hcut = max(hcut, hc - pre);
            pre = hc;
        }
        hcut = max(hcut, h - pre);
        
        pre = 0;
        for (auto vc : verticalCuts) {
            vcut = max(vcut, vc - pre);
            pre = vc;
        }
        vcut = max(vcut, w - pre);
        
        return (hcut * vcut) % mod;
    }
};