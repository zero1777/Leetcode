class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> edge[n];
        
        for (auto pair : pairs) {
            edge[pair[0]].push_back(pair[1]);
            edge[pair[1]].push_back(pair[0]);
        }
        
        vector<bool> visited(n, false);
        for (int i=0; i<n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            
            queue<int> qu;
            set<int> vis;
            string str = "";
            
            qu.push(i);
            while (!qu.empty()) {
                int v = qu.front();
                qu.pop();
                
                if (vis.find(v) != vis.end()) continue;
                vis.insert(v);
                visited[v] = true;
                str.push_back(s[v]);
               
                for (auto e : edge[v]) {
                    qu.push(e);
                    
                }
            }
            
            sort(str.begin(), str.end());
            
            int cnt = 0;
            for (auto idx : vis) {
                s[idx] = str[cnt++];
            }
            
        }
        return s;
    }
};