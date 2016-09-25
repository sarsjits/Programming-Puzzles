class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i=0;i<12;++i) {
            for(int j=0;j<60;++j) {
                if(__builtin_popcount(i) + __builtin_popcount(j) == num) {
                    string intRes = to_string(i) + ":" + char('0' + j/10) + char('0' + j%10);
                    ans.push_back(intRes);
                }
            }
        }
        return ans;
    }
};
