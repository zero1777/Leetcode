class Solution {
public:
    int twoEggDrop(int n) {
        int sum = 1;
        int iter = 0;
        while (sum <= n) {
            iter++;
            sum += iter;
        }
        
        return iter;
    }
};