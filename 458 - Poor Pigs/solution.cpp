class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest / minutesToDie + 1;
        int ret = 0;
        
        while (pow(T, ret) < buckets) ret++;
        
        return ret;
    }
};