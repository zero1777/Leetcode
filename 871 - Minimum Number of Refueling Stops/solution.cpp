class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int idx = 0, cur = startFuel, stops = 0;
        
        priority_queue<int> pq;
        
        while (cur < target) {
            while (idx < n) {
                if (stations[idx][0] > cur) break;
                pq.push(stations[idx][1]);
                idx++;
            } 
            
            if (pq.empty()) return -1;
            int fuel = pq.top(); cout << fuel << endl;
            pq.pop();
            cur += fuel;
            stops++;
        }
        return stops;
    }
};