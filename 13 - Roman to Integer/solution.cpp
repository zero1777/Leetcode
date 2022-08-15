class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int number = 0;
        for (int i=s.length()-1; i>=0; i--) {
            if (i > 0 && mp[s[i]] > mp[s[i-1]]) {
                number += mp[s[i]];
                number -= mp[s[i-1]];
                i--;
            }
            else {
                number += mp[s[i]]; 
            }
        }
        
        return number;
    }
};