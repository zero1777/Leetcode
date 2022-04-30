class Solution {
public:
    // vector<pair<string, double> : adjacency list
    // pair<string, double> : (adjacency vertex, edge weight)  
    unordered_map<string, vector<pair<string, double>>> edge;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct graph
        for (int i=0; i<equations.size(); i++) {
            string v1 = equations[i][0];
            string v2 = equations[i][1];
            // v1
            if (edge.find(v1) == edge.end()) 
                edge[v1] = vector<pair<string, double>>();
            edge[v1].push_back(make_pair(v2, values[i]));
            // v2 
            if (edge.find(v2) == edge.end()) 
                edge[v2] = vector<pair<string, double>>();
            edge[v2].push_back(make_pair(v1, 1/values[i]));
        }
        
        // handle queries
        vector<double> results;
        for (auto qry : queries) {
						// vertex not in the graph -> directly return -1
            if (edge.find(qry[0]) == edge.end() || edge.find(qry[1]) == edge.end()) {
                results.push_back(-1.0);
            }
            else {
                unordered_set<string> visited = {qry[0]};
                auto [result, find] = dfs(visited, qry[0], qry[1], 1.0);
                if (find) results.push_back(result);
                else results.push_back(-1.0);
            }   
        }
        
        return results;
    }
    
    // pair<double, bool> : (query result, if des is connected to src)
    pair<double, bool> dfs(unordered_set<string> &visited, string v, string des, double val) {
        if (v == des) return make_pair(val, true);
        for (auto [name, weight] : edge[v]) {
            if (visited.find(name) != visited.end()) continue;
            visited.insert(name);
            auto [result, find] = dfs(visited, name, des, val * weight);
            if (find) return make_pair(result, true);
        }
        return make_pair(0, false);
    }
};