class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        int prev = -1;
        
        for (int i=0; i<n; i++) {
            if (dominoes[i] == 'R') {
                if (prev != -1 && dominoes[prev] == 'R') {
                    for (int k=prev+1; k<i; k++) dominoes[k] = 'R';
                }
                prev = i;
            }
            else if (dominoes[i] == 'L') {
                if (prev == -1 || dominoes[prev] == 'L') {
                    for (int k=prev+1; k<i; k++) dominoes[k] = 'L';
                } 
                else {
                    int t = i-1; prev++;
                    while (prev < t) {
                        dominoes[prev++] = 'R';
                        dominoes[t--] = 'L';
                    }
                }
                prev = i;
            }
        }
        
        if (prev != -1 && dominoes[prev] == 'R') {
            for (int k=prev+1; k<n; k++) dominoes[k] = 'R';
        }
        
        return dominoes;
    }
};