class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> bitMask(n, 0);
        
        for (int i=0; i<n; i++) {
            for (auto w : words[i]) {
                bitMask[i] |= 1 << (w - 'a');
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((bitMask[i] & bitMask[j]) == 0) {
                    int len = words[i].length() * words[j].length();
                    ans = max(ans, len);
                }
            }
        }
        
        return ans;
    }
};