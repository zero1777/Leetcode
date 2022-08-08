class Solution {
public:
    int countVowelPermutation(int n) {
        int a, e, i, o, u;
        int aa, ee, ii, oo, uu;
        int mod = 1e9 + 7;
        
        a = e = i = o = u = 1; 
        while (--n) {
            aa = (e + i) % mod + u;
            ee = a + i;
            ii = e + o;
            oo = i;
            uu = i + o;
            
            a = aa % mod;
            e = ee % mod;
            i = ii % mod;
            o = oo % mod;
            u = uu % mod;
        }
        
        int sum = a;
        sum += e; sum %= mod;
        sum += i; sum %= mod;
        sum += o; sum %= mod;
        sum += u; sum %= mod;
        
        return sum;
    }
};