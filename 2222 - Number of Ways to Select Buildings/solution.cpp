class Solution {
public:
    long long numberOfWays(string s) {
        long long ret = 0;
        long long z, o, zo, oz;
        z = o = zo = oz = 0;
        
        for (auto c : s) {
            if (c == '0') {
                z += 1;
                oz += o; 
                ret += zo;
            }
            else {
                o += 1;
                zo += z;
                ret += oz;
            }
        }
        
        return ret;
    }
};