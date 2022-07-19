class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        
        for (int row=0; row<numRows; row++) {
            vector<int> tri(row+1, 0);
            if (row == 0) tri[0] = 1;
            else {
                for (int i=0; i<row; i++) {
                    tri[i] += ret[row-1][i];
                    tri[i+1] += ret[row-1][i];
                }
            }
            ret.push_back(tri);
        }
        
        return ret;
    }
};