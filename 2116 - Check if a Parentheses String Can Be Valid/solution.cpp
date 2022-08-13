class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = locked.length();
        if (n % 2) return false;
        
        int unlock = 0, right = 0, left = 0;
        for (int i=0; i<n; i++) {
            if (locked[i] == '0') {
                unlock++; 
            }   
            else {
                if (s[i] == '(') right--;
                else right++;
            }
            
            if (right > unlock) return false;
        }
        if (unlock + right < 0) return false;
        
        unlock = 0;
        for (int i=n-1; i>=0; i--) {
            if (locked[i] == '0') {
                unlock++; 
            }   
            else {
                if (s[i] == ')') left--;
                else left++;
            }
            
            if (left > unlock) return false;
        }
        if (unlock + left < 0) return false;
        
        return true;
    }
};