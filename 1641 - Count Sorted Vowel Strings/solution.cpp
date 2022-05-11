class Solution {
public:
    int countVowelStrings(int n) {
        int sz = 5;
        int sum[sz];
        
        for (int i=0; i<sz; i++) sum[i] = 1;
        while (--n) {
            for (int i=1; i<sz; i++) {
                sum[i] += sum[i-1];
            }
        }
        
        int ans = 0;
        for (int i=0; i<sz; i++) ans += sum[i];
        
        return ans;
    }
};