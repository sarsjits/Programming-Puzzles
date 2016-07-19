class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows < 1) {
            return res;
        } else if(numRows >= 1) {
            vector<int> x;
            x.push_back(1);
            res.push_back(x);
        }
        
        for(int i=1;i<numRows;i++) {
            vector<int> x;
            x.push_back(1);
            for(int j=0;j<res[res.size()-1].size()-1;j++) {
                int y = res[res.size()-1][j] + res[res.size()-1][j+1];
                x.push_back(y);
            }
            x.push_back(1);
            res.push_back(x);
        }
        
        return res;
    }
};
